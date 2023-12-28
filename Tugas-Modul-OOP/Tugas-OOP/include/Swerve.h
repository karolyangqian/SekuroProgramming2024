#ifndef SWERVE
#define SWERVE
#include "Matrix.h"

class Swerve
{
private:
    Matrix v_components;
    Matrix vx_vy_omega;
    Matrix x_y_theta;
    const float r = 0.26363;

public:
    Swerve(float x, float y, float theta);
    float get_x();
    float get_y();
    float get_theta();
    Matrix get_pose_matrix();
    void displayPose();
    void displayVelocity();
    void velocityCommand(float vx, float vy, float omega);
    void updatePose(float deltaTime);
    float get_vn(int n);
};

#endif