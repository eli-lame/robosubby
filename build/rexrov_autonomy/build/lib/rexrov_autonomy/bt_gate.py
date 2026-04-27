import rclpy
from rclpy.node import Node

from rexrov_interfaces.msg import GateDetection
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

import py_trees
import time
import math


# ============================================================
# SHARED DATA (BLACKBOARD STYLE)
# ============================================================
class GateData:
    def __init__(self):
        # perception
        self.detected = False
        self.error_x = 0.0
        self.distance = 999.0

        # odometry
        self.x = 0.0
        self.y = 0.0


# ============================================================
# ROS INTERFACE NODE
# ============================================================
class GateInterface(Node):
    def __init__(self, data):
        super().__init__('gate_interface')
        self.data = data

        # perception subscriber
        self.create_subscription(
            GateDetection,
            '/gate_detection',
            self.gate_cb,
            10
        )

        # odometry subscriber
        self.create_subscription(
            Odometry,
            '/rexrov/odom',
            self.odom_cb,
            10
        )

        # command publisher
        self.cmd_pub = self.create_publisher(
            Twist,
            '/rexrov/cmd_vel',
            10
        )

    def gate_cb(self, msg):
        self.data.detected = msg.detected
        self.data.error_x = msg.error_x
        self.data.distance = msg.distance

    def odom_cb(self, msg):
        self.data.x = msg.pose.pose.position.x
        self.data.y = msg.pose.pose.position.y


# ============================================================
# DIVE
# ============================================================
class Dive(py_trees.behaviour.Behaviour):
    def __init__(self, node):
        super().__init__("Dive")
        self.node = node
        self.t0 = None

    def initialise(self):
        self.t0 = time.time()
        print("[BT] Dive start")

    def update(self):
        cmd = Twist()
        cmd.linear.z = -0.3
        self.node.cmd_pub.publish(cmd)

        if time.time() - self.t0 > 2.5:
            cmd.linear.z = 0.0
            self.node.cmd_pub.publish(cmd)
            print("[BT] Dive complete")
            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING


# ============================================================
# FIND GATE
# ============================================================
class FindGate(py_trees.behaviour.Behaviour):
    def __init__(self, data, node):
        super().__init__("FindGate")
        self.data = data
        self.node = node

    def update(self):
        cmd = Twist()

        if self.data.detected:
            cmd.angular.z = 0.0
            self.node.cmd_pub.publish(cmd)
            print("[BT] Gate detected")
            return py_trees.common.Status.SUCCESS

        cmd.angular.z = 0.2  # slow spin search
        self.node.cmd_pub.publish(cmd)

        print("[BT] Searching...")
        return py_trees.common.Status.RUNNING


# ============================================================
# ALIGN GATE (smoothed control)
# ============================================================
class AlignGate(py_trees.behaviour.Behaviour):
    def __init__(self, data, node):
        super().__init__("AlignGate")
        self.data = data
        self.node = node

    def update(self):
        cmd = Twist()

        if not self.data.detected:
            return py_trees.common.Status.RUNNING

        if abs(self.data.error_x) < 0.08:
            cmd.angular.z = 0.0
            self.node.cmd_pub.publish(cmd)
            print("[BT] Aligned")
            return py_trees.common.Status.SUCCESS

        # proportional + clamp (prevents overshoot)
        turn = -0.6 * self.data.error_x
        turn = max(min(turn, 0.25), -0.25)

        cmd.angular.z = turn
        self.node.cmd_pub.publish(cmd)

        print(f"[BT] Align error={self.data.error_x:.3f}")
        return py_trees.common.Status.RUNNING


# ============================================================
# DRIVE THROUGH GATE (COMMIT + EXECUTE)
# ============================================================
class DriveThroughGate(py_trees.behaviour.Behaviour):
    def __init__(self, data, node):
        super().__init__("DriveThroughGate")
        self.data = data
        self.node = node

        self.committed = False
        self.start_x = 0.0
        self.start_y = 0.0
        self.target_distance = 0.0

    def initialise(self):
        self.committed = False
        print("[BT] DriveThroughGate start")

    def update(self):
        cmd = Twist()

        # ====================================================
        # PHASE 1: APPROACH + COMMIT
        # ====================================================
        if not self.committed:

            if not self.data.detected:
                return py_trees.common.Status.RUNNING

            if self.data.distance < 2.0:
                self.committed = True

                self.start_x = self.data.x
                self.start_y = self.data.y

                buffer = 1.5
                max_travel = 4.0

                self.target_distance = min(self.data.distance + buffer, max_travel)

                print(f"[BT] COMMITTED travel={self.target_distance:.2f}")

            else:
                cmd.linear.x = 0.5
                cmd.angular.z = -0.4 * self.data.error_x
                self.node.cmd_pub.publish(cmd)

                return py_trees.common.Status.RUNNING

        # ====================================================
        # PHASE 2: DRIVE STRAIGHT
        # ====================================================
        dx = self.data.x - self.start_x
        dy = self.data.y - self.start_y
        traveled = math.sqrt(dx*dx + dy*dy)

        print(f"[BT] Travel {traveled:.2f}/{self.target_distance:.2f}")

        # STOP CONDITION (robust)
        if traveled >= self.target_distance or traveled > 4.5:
            cmd.linear.x = 0.0
            self.node.cmd_pub.publish(cmd)
            print("[BT] Gate passed")
            return py_trees.common.Status.SUCCESS

        cmd.linear.x = 0.7
        cmd.angular.z = 0.0
        self.node.cmd_pub.publish(cmd)

        return py_trees.common.Status.RUNNING


# ============================================================
# MAIN
# ============================================================
def main():
    rclpy.init()

    data = GateData()
    node = GateInterface(data)

    root = py_trees.composites.Sequence("GateMission", memory=True)

    root.add_children([
        Dive(node),
        FindGate(data, node),
        AlignGate(data, node),
        DriveThroughGate(data, node)
    ])

    tree = py_trees.trees.BehaviourTree(root)

    print("\n===== BT STARTED =====\n")

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
            tree.tick()
            time.sleep(0.1)

    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()