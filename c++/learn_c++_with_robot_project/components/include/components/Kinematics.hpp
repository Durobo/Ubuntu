#ifndef KINEMATICS_HPP
#define KINEMATICS_HPP

#include <Eigen/Dense>

class Kinematics {
    public:
        Kinematics(double x, double y, double theta_rad);
        
        // Di chuyen robot mot doan (dx, dy)
        void move(double dx, double dy);

        // In ra vi tri hien tai
        void printPose() const;

        Eigen::Vector3d getPose() const;

    private:
        Eigen::Vector3d m_pose;
};

#endif
