from components.joint import RobotJoint
import pytest

def test_joint_initialization():
    joint = RobotJoint(1, "test_joint", 90.0)

    assert joint.get_id() == 1
    assert joint.get_name() == "test_joint"
    assert joint.get_angle() == 0.0
    assert joint.get_velocity() == 0.0

def test_set_angle_within_limits():
    joint = RobotJoint(1, "test_joint", 90.0)
    joint.set_angle(45.5)

    assert joint.get_angle() == 45.5

def test_set_angle_exceeds_positive_limits():
    joint = RobotJoint(1, "test_joint", 90.0)
    joint.set_angle(100.0)

    assert joint.get_angle() == 90.0

def test_set_angle_exceeds_nagative_limits():
    joint = RobotJoint(1, "test_joint", 90.0)
    joint.set_angle(-120.0)

    assert joint.get_angle() == -90.0

def test_set_velocity_dps():
    joint = RobotJoint(1, "test_joint", 90.0)
    joint.set_velocity(25.0)

    assert joint.get_velocity() == 25.0