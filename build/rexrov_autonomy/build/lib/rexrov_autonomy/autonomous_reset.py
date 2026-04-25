#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class RexrovAutonomy(Node):
    def __init__(self):
        super().__init__('rexrov_autonomy')

        self.publisher = self.create_publisher(
            Twist,
            '/rexrov/cmd_vel',
            10
        )

        self.timer = self.create_timer(0.1, self.control_loop)
        self.time = 0

    def control_loop(self):
        msg = Twist()

        # Simple behavior: move up for 5 seconds, then turn
        if self.time < 200:
            msg.linear.z = 1.0  # up
        elif self.time < 250:
            msg.angular.z = -0.5  # turn
        else:
            msg.linear.z = 0.0
            msg.angular.z = 0.0

        self.publisher.publish(msg)

        self.time += 1


def main(args=None):
    rclpy.init(args=args)
    node = RexrovAutonomy()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
