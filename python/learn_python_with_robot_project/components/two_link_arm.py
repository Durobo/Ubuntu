from .joint import RobotJoint
import numpy as np
import math as m

def degrees_to_radians(degrees):
    return degrees * m.pi / 180.0

class TwoLinkArm():
    def __init__(self, link1_length, link2_length):
        self.__l1 = link1_length
        self.__l2 = link2_length
        self.__joint1 = RobotJoint(1, "base_joint", 180.0)
        self.__joint2 = RobotJoint(2, "elbow_joint", 180.0)

        print(f"Two-Link Arm created with L1 = {self.__l1}, L2 = {self.__l2}\n")

    def set_joint_angles(self, theta1_deg, theta2_deg):
        self.__joint1.set_angle(theta1_deg)
        self.__joint2.set_angle(theta2_deg)

    def get_end_effector_position(self):
        theta1_rad = degrees_to_radians(self.__joint1.get_angle())
        theta2_rad = degrees_to_radians(self.__joint2.get_angle())

        x = self.__l1 * m.cos(theta1_rad) + self.__l2 * m.cos(theta1_rad + theta2_rad)
        y = self.__l1 * m.sin(theta1_rad) + self.__l2 * m.sin(theta1_rad + theta2_rad)

        position = np.array([x, y])
        return position

    def print_status(self):
        self.__joint1.print_status()
        self.__joint2.print_status()

        ee_pos = self.get_end_effector_position()
        print(f"End-Effector at: (x = {ee_pos[0]}, y = {ee_pos[1]})\n")

    # Trực quan hóa với Matplotlib
    def get_link_lengths(self):
        """Trả về một tuple chứa chiều dài L1, L2."""
        return (self.__l1, self.__l2)

    def get_joint_angles_deg(self):
        """Trả về một tuple chứa góc của khớp 1, khớp 2 (độ)."""
        return (self.__joint1.get_angle(), self.__joint2.get_angle())

    def get_joint_angles_rad(self):
        """Trả về một tuple chứa góc của khớp 1, khớp 2 (radian)."""
        theta1_deg, theta2_deg = self.get_joint_angles_deg()
        return (degrees_to_radians(theta1_deg), degrees_to_radians(theta2_deg))