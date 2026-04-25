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

    def cb(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        h, w, _ = frame.shape
        cx = w // 2

        # --- HSV conversion ---
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # --- RED mask (wrap-around) ---
        lower1 = np.array([0, 120, 120])
        upper1 = np.array([10, 255, 255])

        lower2 = np.array([170, 120, 120])
        upper2 = np.array([180, 255, 255])

        mask = cv2.inRange(hsv, lower1, upper1) | cv2.inRange(hsv, lower2, upper2)

        # --- clean mask ---
        mask = cv2.medianBlur(mask, 5)

        # --- find contours ---
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        print(f"Contours found: {len(contours)}")

        detected = False
        error_x = 0.0
        distance = 0.0
        gate_center = cx  # default

        # --- MAIN FIX: use largest contour ALWAYS ---
        if len(contours) > 0:
            largest = max(contours, key=cv2.contourArea)
            area = cv2.contourArea(largest)

            print(f"Using contour area: {area}")

            if area > 50:   # very low threshold
                x, y, bw, bh = cv2.boundingRect(largest)

                obj_x = x + bw // 2

                error_x = (obj_x - cx) / cx
                distance = 1.0 / (bw * bh + 1e-6)

                detected = True
                gate_center = obj_x

                # draw bounding box
                cv2.rectangle(frame, (x, y), (x + bw, y + bh), (0, 255, 0), 2)

        # --- visualization ---
        cv2.line(frame, (cx, 0), (cx, h), (0, 0, 255), 2)  # robot center (red)
        cv2.line(frame, (int(gate_center), 0), (int(gate_center), h), (255, 0, 0), 2)  # gate center (blue)

        # --- debug text ---
        cv2.putText(frame, f"detected: {detected}", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        cv2.putText(frame, f"error_x: {error_x:.2f}", (10, 60),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        cv2.putText(frame, f"distance: {distance:.5f}", (10, 90),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        # --- terminal output ---
        print(f"detected: {detected} | error_x: {error_x:.3f} | distance: {distance:.6f}")

        # --- show windows ---
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