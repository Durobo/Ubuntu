#include <gtest/gtest.h>
#include "components/TwoLinkArm.hpp"
#include "components/Kinematics.hpp"

TEST(KinematicsTest, Constructor) {
    Kinematics pose(1.0, 2.0, 0.5);

    Eigen::Vector3d expected_pose;
    expected_pose << 1.0, 2.0, 0.5;

    // So sánh hai vector của Eigen. Cần dùng .isApprox() để xử lý sai số dấu phẩy động.
    ASSERT_TRUE(pose.getPose().isApprox(expected_pose));
}

TEST(KinematicsTest, MoveFunction) {
    Kinematics pose(0.0, 0.0, 0.0);
    pose.move(1.5, -2.5);

    Eigen::Vector3d expected_pose;
    expected_pose << 1.5, -2.5, 0.0;
    
    ASSERT_TRUE(pose.getPose().isApprox(expected_pose));
}