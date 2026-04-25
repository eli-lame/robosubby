import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from cv_bridge import CvBridge

import cv2
import numpy as np


class PerceptionNode(Node):
    def __init__(self):
        super().__init__('perception_node')
        self.bridge = CvBridge()

        self.sub = self.create_subscription(
            Image,
            '/rexrov/camera/image_raw',
            self.cb,
            10
        )

        # --- simple tuning constant (you will adjust this once) ---
        self.FOCAL_LENGTH = 600  # approximate camera focal length in pixels
        self.GATE_REAL_WIDTH = 1.0  # meters (CHANGE if your gate differs)

    def cb(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        h, w, _ = frame.shape
        cx = w // 2

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # red mask
        mask = cv2.inRange(hsv, (0, 120, 120), (10, 255, 255)) | \
               cv2.inRange(hsv, (170, 120, 120), (180, 255, 255))

        mask = cv2.medianBlur(mask, 5)

        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        detected = False
        error_x = 0.0
        distance_m = 0.0
        gate_center = cx

        if contours:
            largest = max(contours, key=cv2.contourArea)
            area = cv2.contourArea(largest)

            if area > 100:
                x, y, bw, bh = cv2.boundingRect(largest)

                # -------------------------
                # CENTER ERROR
                # -------------------------
                obj_x = x + bw // 2
                error_x = (obj_x - cx) / cx

                gate_center = obj_x

                # -------------------------
                # DISTANCE (meters estimate)
                # pinhole camera model:
                # distance = (real_width * focal_length) / pixel_width
                # -------------------------
                if bw > 0:
                    distance_m = (self.GATE_REAL_WIDTH * self.FOCAL_LENGTH) / bw

                detected = True

                cv2.rectangle(frame, (x, y), (x + bw, y + bh), (0, 255, 0), 2)

        # -------------------------
        # VISUALIZATION
        # -------------------------
        cv2.line(frame, (cx, 0), (cx, h), (0, 0, 255), 2)
        cv2.line(frame, (int(gate_center), 0), (int(gate_center), h), (255, 0, 0), 2)

        cv2.putText(frame, f"detected: {detected}", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        cv2.putText(frame, f"error_x: {error_x:.2f}", (10, 60),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        cv2.putText(frame, f"distance(m): {distance_m:.2f}", (10, 90),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        print(f"detected: {detected} | error_x: {error_x:.3f} | distance: {distance_m:.2f} m")

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