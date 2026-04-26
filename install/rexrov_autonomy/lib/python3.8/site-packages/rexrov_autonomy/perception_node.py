import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from rexrov_interfaces.msg import GateDetection  # ✅ ADD THIS

import cv2
import numpy as np


class PerceptionNode(Node):
    def __init__(self):
        super().__init__('perception_node')

        self.bridge = CvBridge()

        # ✅ SUBSCRIBER
        self.sub = self.create_subscription(
            Image,
            '/rexrov/camera/image_raw',
            self.cb,
            10
        )

        # ✅ PUBLISHER (THIS WAS MISSING)
        self.pub = self.create_publisher(
            GateDetection,
            '/gate_detection',
            10
        )

        # ---- ASSUMPTIONS (tune later) ----
        self.GATE_HEIGHT_METERS = 2.0
        self.FOV_DEG = 90.0

    def cb(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        h, w, _ = frame.shape
        cx = w // 2

        # focal length in pixels (pinhole approx)
        f = w / (2 * np.tan(np.deg2rad(self.FOV_DEG / 2)))

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        lower1 = np.array([0, 120, 120])
        upper1 = np.array([10, 255, 255])

        lower2 = np.array([170, 120, 120])
        upper2 = np.array([180, 255, 255])

        mask = cv2.inRange(hsv, lower1, upper1) | cv2.inRange(hsv, lower2, upper2)

        mask = cv2.medianBlur(mask, 5)

        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # ✅ DEFAULT VALUES (ALWAYS SET THESE)
        detected = False
        error_x = 0.0
        distance_m = 0.0

        if contours:
            largest = max(contours, key=cv2.contourArea)

            if cv2.contourArea(largest) > 100:
                x, y, bw, bh = cv2.boundingRect(largest)

                # center error
                obj_x = x + bw // 2
                error_x = (obj_x - cx) / cx

                # distance estimate
                if bh > 0:
                    distance_m = (self.GATE_HEIGHT_METERS * f) / bh

                detected = True

                # visualization
                cv2.rectangle(frame, (x, y), (x + bw, y + bh), (0, 255, 0), 2)
                cv2.circle(frame, (obj_x, y + bh // 2), 5, (0, 0, 255), -1)

        # ✅ ALWAYS PUBLISH (THIS FIXES YOUR ISSUE)
        msg_out = GateDetection()
        msg_out.detected = detected
        msg_out.error_x = float(error_x)
        msg_out.distance = float(distance_m)

        self.pub.publish(msg_out)

        # debug print
        print(f"detected: {detected} | error_x: {error_x:.3f} | distance_m: {distance_m:.2f}")

        # display
        cv2.imshow("perception", frame)
        cv2.imshow("mask", mask)
        cv2.waitKey(1)


def main():
    rclpy.init()
    node = PerceptionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()