from .component import RobotComponent

class Gripper(RobotComponent):
    def __init__(self, component_id, name):
        super().__init__(component_id, name)
        self.__is_open = True
        self.__force_newton = 0.0
    
    def open(self):
        self.__is_open = True

    def close(self):
        self.__is_open = False

    def set_force(self, force):
        self.__force_newton = force

    def get_force(self):
        return self.__force_newton
    
    def print_status(self):
        super().print_status()
        state = lambda state : "Open" if self.__is_open else "Close"
        print(f"State: {state}\nForce: {self.__force_newton} N\n")