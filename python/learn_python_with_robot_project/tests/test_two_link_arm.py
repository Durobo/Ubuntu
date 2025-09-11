from components.two_link_arm import TwoLinkArm
import pytest
import numpy as np

def test_two_link_arm():
    arm = TwoLinkArm(10.0, 5.0)
    arm.set_joint_angles(0, 0)

    actual_pos = arm.get_end_effector_position()
    expected_pos = np.array([15.0, 0.0])
    
    np.testing.assert_allclose(actual_pos, expected_pos)
    