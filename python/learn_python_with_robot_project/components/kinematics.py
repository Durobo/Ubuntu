import numpy as np

class Kinematics():
    def __init__(self, x, y, theta_rad):
        self.__pose = np.array([x, y, theta_rad])

    def move(self, dx, dy):
        self.__pose[0] += dx
        self.__pose[1] += dy

    def get_pose(self):
        return self.__pose    
    
    def print_pose(self):
        print(f"Robot Pose (x, y, theta): [{self.__pose[0]}, {self.__pose[1]}, {self.__pose[2]}]\n")
