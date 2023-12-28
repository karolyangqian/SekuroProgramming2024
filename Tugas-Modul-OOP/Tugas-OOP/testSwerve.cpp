#include <iostream>
#include "include/Swerve.h"

using namespace std;

int main() {
    Swerve swerve(0, 0, 0);
    swerve.displayVelocity();
    swerve.displayPose();
    swerve.velocityCommand(1, 1, 1);
    swerve.displayVelocity();
    swerve.updatePose(10);
    swerve.displayPose();

    cout << "\nPress any key to exit";
    cin.get();

    return 0;
}