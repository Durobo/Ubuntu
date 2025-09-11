from .component import RobotComponent

class RobotJoint(RobotComponent):
    def __init__(self, component_id, name, angle_limit):
        super().__init__(component_id, name)
        self.__angle_deg = 0.0
        self.__angle_limit_deg = angle_limit
        self.__velocity_dps = 0.0

        print(f"Joint '{self._name}' created.\n")
    
    def set_angle(self, angle):
        if angle > self.__angle_limit_deg:
            self.__angle_deg = self.__angle_limit_deg
            print(f"Warning: Angle for {self._name} exceeds limit. Clamped to {self.__angle_limit_deg}\n")
        elif angle < -self.__angle_limit_deg:
            self.__angle_deg = -self.__angle_limit_deg
            print(f"Warning: Angle for {self._name} exceeds limit. Clamped to {-self.__angle_limit_deg}\n")
        else:
            self.__angle_deg = angle

    def get_angle(self):
        return self.__angle_deg
    
    def set_velocity(self, velocity):
        self.__velocity_dps = velocity
    
    def get_velocity(self):
        return self.__velocity_dps
    
    def print_status(self):
        super().print_status()
        print(f"Joint [{self._name}]: Pos = {self.__angle_deg } deg, Vel = {self.__velocity_dps} dps\n")