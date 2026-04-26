import rclpy
from rclpy.node import Node

from rexrov_interfaces.msg import GateDetection
from geometry_msgs.msg import Twist

import py_trees
import time


# -----------------------------
# Shared Data Container
# -----------------------------
class GateData:
    def __init__(self):
        self.detected = False
        self.error_x = 0.0
        self.distance = 999.0


# -----------------------------
# ROS Node (Subscriber + Publisher)
# -----------------------------
class GateInterface(Node):
    def __init__(self, data):
        super().__init__('gate_interface')
        self.data = data

        self.sub = self.create_subscription(
            GateDetection,
            '/gate_detection',
            self.cb,
            10
        )

        self.cmd_pub = self.create_publisher(Twist, '/rexrov/cmd_vel', 10)

    def cb(self, msg):
        self.data.detected = msg.detected
        self.data.error_x = msg.error_x
        self.data.distance = msg.distance


# -----------------------------
# FIND GATE (SPIN SEARCH)
# -----------------------------
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
            return py_trees.common.Status.SUCCESS

        # spin in place
        cmd.angular.z = 0.5
        self.node.cmd_pub.publish(cmd)

        print("Searching for gate...")
        return py_trees.common.Status.RUNNING


# -----------------------------
# ALIGN GATE
# -----------------------------
class AlignGate(py_trees.behaviour.Behaviour):
    def __init__(self, data, node):
        super().__init__("AlignGate")
        self.data = data
        self.node = node

    def update(self):
        cmd = Twist()

        if not self.data.detected:
            return py_trees.common.Status.FAILURE

        if abs(self.data.error_x) < 0.08:
            cmd.angular.z = 0.0
            self.node.cmd_pub.publish(cmd)
            return py_trees.common.Status.SUCCESS

        cmd.angular.z = -1.5 * self.data.error_x
        self.node.cmd_pub.publish(cmd)

        print(f"Aligning... error_x={self.data.error_x:.3f}")
        return py_trees.common.Status.RUNNING


# -----------------------------
# APPROACH GATE
# -----------------------------
class ApproachGate(py_trees.behaviour.Behaviour):
    def __init__(self, data, node):
        super().__init__("ApproachGate")
        self.data = data
        self.node = node

    def update(self):
        cmd = Twist()

        if not self.data.detected:
            return py_trees.common.Status.FAILURE

        if self.data.distance < 1.5:
            cmd.linear.x = 0.0
            self.node.cmd_pub.publish(cmd)
            return py_trees.common.Status.SUCCESS

        cmd.linear.x = 0.6
        self.node.cmd_pub.publish(cmd)

        print(f"Approaching... distance={self.data.distance:.2f}")
        return py_trees.common.Status.RUNNING


# -----------------------------
# PASS GATE
# -----------------------------
class PassGate(py_trees.behaviour.Behaviour):
    def __init__(self, node):
        super().__init__("PassGate")
        self.node = node
        self.start_time = None

    def initialise(self):
        self.start_time = time.time()

    def update(self):
        cmd = Twist()
        cmd.linear.x = 0.5
        self.node.cmd_pub.publish(cmd)

        print("Passing through gate...")

        if time.time() - self.start_time > 3.0:
            cmd.linear.x = 0.0
            self.node.cmd_pub.publish(cmd)
            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING


# -----------------------------
# MAIN
# -----------------------------
def main():
    rclpy.init()

    data = GateData()
    node = GateInterface(data)

    root = py_trees.composites.Sequence("GateMission", memory=True)

    root.add_children([
        FindGate(data, node),
        AlignGate(data, node),
        ApproachGate(data, node),
        PassGate(node)
    ])

    tree = py_trees.trees.BehaviourTree(root)

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