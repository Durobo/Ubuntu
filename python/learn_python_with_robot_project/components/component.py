
class RobotComponent:
    def __init__(self, component_id, name):
        self._id = component_id
        self._name = name
    
    def get_id(self):
        return self._id
    
    def get_name(self):
        return self._name

    def print_status(self):
        print(f"Component [ID: {self._id}, Name: {self._name}]: ")