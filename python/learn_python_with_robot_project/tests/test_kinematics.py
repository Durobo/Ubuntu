from components.kinematics import Kinematics
import pytest
import numpy as np

def test_kinematics_initialization():
    kinematics = Kinematics(1.0, 2.0, 0.785)
    actual_kine = kinematics.get_pose()
    expeced_kine = [1.0, 2.0, 0.785]

    np.testing.assert_allclose(actual_kine, expeced_kine)

def test_kinematics_move():
    kinematics = Kinematics(1.0, 2.0, 0.785)
    kinematics.move(0.5, -0.2)

    actual_kine = kinematics.get_pose()
    expeced_kine = [1.5, 1.8, 0.785]
    
    np.testing.assert_allclose(actual_kine, expeced_kine)