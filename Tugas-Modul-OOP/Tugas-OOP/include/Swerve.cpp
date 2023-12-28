#define _USE_MATH_DEFINES
#include "Matrix.h"
#include "Swerve.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


Swerve::Swerve(float x, float y, float theta)
    : v_components(8, 1), vx_vy_omega(3, 1), x_y_theta(3, 1)
{
    vector<vector<float>> temp {
        {x},
        {y},
        {theta}
    };
    this->x_y_theta = temp;
}

float Swerve::get_x()
{
    return this->x_y_theta.get_data_val(0, 0);
}

float Swerve::get_y()
{
    return this->x_y_theta.get_data_val(1, 0);
}

float Swerve::get_theta()
{
    return this->x_y_theta.get_data_val(2, 0);
}

Matrix Swerve::get_pose_matrix()
{
    return this->x_y_theta;
}

void Swerve::displayPose()
{
    cout << "x: " << this->get_x() << " y: " << this->get_y() << " theta: " << this->get_theta() << endl;
}


void Swerve::displayVelocity()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "v_" << i+1 << "x: " << this->v_components.get_data_val(2*i, 0) << endl;
        cout << "v_" << i+1 << "y: " << this->v_components.get_data_val(2*i+1, 0) << endl;
    }
    
    cout << "vx: " << this->vx_vy_omega.get_data_val(0, 0)
         << " vy: " << this->vx_vy_omega.get_data_val(1, 0)
         << " omega: " << this->vx_vy_omega.get_data_val(2, 0) << endl;
}


void Swerve::velocityCommand(float vx, float vy, float omega)
{
    vector<vector<float>> input {
        {vx}, 
        {vy}, 
        {omega}
        };
    this->vx_vy_omega = input;
    vector<vector<float>> M_temp {
        {1, 0, -r*float(sin(M_PI/4))},
        {0, 1, r*float(cos(M_PI/4))},
        {1, 0, -r*-float(sin(M_PI/4))},
        {0, 1, r*float(cos(M_PI/4))},
        {1, 0, -r*float(sin(M_PI/4))},
        {0, 1, r*-float(cos(M_PI/4))},
        {1, 0, -r*-float(sin(M_PI/4))},
        {0, 1, r*-float(cos(M_PI/4))}
    };
    Matrix M = M_temp;
    this->v_components = M * this->vx_vy_omega;

}


void Swerve::updatePose(float deltaTime)
{
    this->x_y_theta = this->x_y_theta + this->vx_vy_omega.scalarMultiply(deltaTime);
}

float Swerve::get_vn(int n)
{
    float vnx = v_components.get_data_val((n-1)*2, 0);
    float vny = v_components.get_data_val((n-1)*2+1, 0);
    return sqrt(pow(vnx, 2) + pow(vny, 2));
}