#include "ros/ros.h"
#include "package1/magnitude.h"
#include <math.h>

bool findMagnitude(package1::magnitude::Request &req, package1::magnitude::Response &resp) {
    // Mengolah data request ke dalam respon
    resp.magnitude = sqrt(pow(req.komponenX, 2) + pow(req.komponenY, 2) + pow(req.komponenZ, 2));

    // Mencetak hasil olahan data
    ROS_INFO(
        "\n[Server]\n"
        "Nilai komponen X: %lf Nilai komponen Y: %lf Nilai komponen Z: %lf\n"
        "Magnitude: %lf\n",
        req.komponenX,
        req.komponenY,
        req.komponenZ,
        resp.magnitude
    );
    return true;
}

int main(int argc, char **argv)
{
    // Inisialisasi Node
    ros::init( argc, argv, "magnitude_server");

    // Inisialisasi Handler Node
    ros::NodeHandle nh;

    // Inisialisasi Server dari Handler
    ros::ServiceServer server = nh.advertiseService("magnitude", findMagnitude);

    ros::spin();

    return 0;
}
