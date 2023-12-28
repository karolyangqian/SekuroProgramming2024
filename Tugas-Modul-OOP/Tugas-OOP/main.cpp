#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <math.h>
#include "include/Swerve.h"
#include "pbPlots/pbPlots.hpp"
#include "pbPlots/supportLib.hpp"

using namespace std;


float vx(float t) {
    return 48*cos(t)*pow(sin(t), 2);
}

float vy(float t) {
    return 4*sin(4*t) + 6*sin(3*t) + 10*sin(2*t) - 13*sin(t);
}

void draw(vector<double> x_data, vector<double> y_data, string path) {
    bool success;
	StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	vector<double> xs = x_data;
	vector<double> ys = y_data;

	success = DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);

	if(success){
		vector<double> *pngdata = ConvertToPNG(imageReference->image);
		WriteToFile(pngdata, path);
		DeleteImage(imageReference->image);
	}else{
		cerr << "Error: ";
		for(wchar_t c : *errorMessage->string){
			wcerr << c;
		}
		cerr << endl;
	}

	FreeAllocations();
}

int main() {
    // Inisialiasi objek swerve
    float x0 = 0;
    float y0 = 5;
    float theta0 = 0;
    Swerve swerve(x0, y0, theta0);

    // Inisialisasi time bound
    float ti = 0;
    float tf = 6.3;
    float dt = 0.01;

    // Inisialisasi kumpulan data pose x dan y serta waktunya dalam vector
    vector<double> poses_x {x0};
    vector<double> poses_y {y0};
    vector<double> time {ti};

    // Inisialisasi kumpulan data v1, v2, v3, dan v4 dalam vector
    swerve.velocityCommand(vx(0), vy(0), 0);
    vector<double> v1 {swerve.get_vn(1)};
    vector<double> v2 {swerve.get_vn(2)};
    vector<double> v3 {swerve.get_vn(3)};
    vector<double> v4 {swerve.get_vn(4)};

    // swerve.displayPose();

    // Looping pengambilan data
    for (float t = ti + dt; t <= tf; t+=dt)
    {
        swerve.velocityCommand(vx(t), vy(t), 0);
        swerve.updatePose(dt);
        poses_x.push_back(swerve.get_x());
        poses_y.push_back(swerve.get_y());
        time.push_back(t);
        v1.push_back(swerve.get_vn(1));
        v2.push_back(swerve.get_vn(2));
        v3.push_back(swerve.get_vn(3));
        v4.push_back(swerve.get_vn(4));
        
        // swerve.displayPose();
    }

    // Membuat grafik
    draw(poses_x, poses_y, "../Hasil-Grafik/grafik_y_terhadap_x.png");
    draw(time, v1, "../Hasil-Grafik/grafik_v1_terhadap_time.png");
    draw(time, v2, "../Hasil-Grafik/grafik_v2_terhadap_time.png");
    draw(time, v3, "../Hasil-Grafik/grafik_v3_terhadap_time.png");
    draw(time, v4, "../Hasil-Grafik/grafik_v4_terhadap_time.png");

    // Exit
    cout << "Press any key to exit";
    cin.get();

    return 0;
}