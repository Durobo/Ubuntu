from components.gripper import Gripper
import pytest

def test_gripper_initialization():
    gripper = Gripper(2, "test_gripper")

    assert gripper.get_force() == 0.0

def test_set_froce():
    gripper = Gripper(2, "test_gripper")
    gripper.set_force(45.5)

    assert gripper.get_force() == 45.5