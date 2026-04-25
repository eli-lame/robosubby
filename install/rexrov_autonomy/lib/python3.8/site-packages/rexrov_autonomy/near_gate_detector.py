#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool
import math

class NearGateDetector(Node):
    def __init__(self):
        super().__init__('near_gate_detector')

        # Subscribe to robot position
        self.sub = self.create_subscription(
            Odometry,
            '/rexrov/odometry',
            self.odom_callback,
            10
        )

        # Publish whether we are near the gate
        self.pub = self.create_publisher(
            Bool,
            '/near_gate',
            10
        )

        # Gate position (mock perception)
        self.gx = 5.0
        self.gy = 0.0
        self.gz = -2.0

        # Distance threshold
        self.threshold = 1.0

        self.near_gate = False

    def odom_callback(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        z = msg.pose.pose.position.z

        dx = x - self.gx
        dy = y - self.gy
        dz = z - self.gz

        dist = math.sqrt(dx**2 + dy**2 + dz**2)

        new_state = dist < self.threshold

        # Only publish if state changes (cleaner behavior)
        if new_state != self.near_gate:
            self.near_gate = new_state
            self.get_logger().info(f"Near gate: {self.near_gate} (dist={dist:.2f})")

        msg_out = Bool()
        msg_out.data = self.near_gate
        self.pub.publish(msg_out)


def main(args=None):
    rclpy.init(args=args)
    node = NearGateDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()