#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

vector<float>rx;
vector<float>ry;

int steps = 0;

void hapusRedo()
{
	int n = rx.size()-steps-1;
	for (int i = 0; i < n; i++)
	{
		rx.pop_back();
		ry.pop_back();
	}
}

void lokasi()
{
    float x = rx[steps];
	float y = ry[steps];
	cout << "Lokasi drone saat ini: ";
	cout << setprecision(2) << fixed;
    cout << "(" << x << ", " << y << ")\n";
}

void gerak(float dx, float dy)
{
	hapusRedo();
	rx.push_back((rx[steps]+dx));
	ry.push_back((ry[steps]+dy));
	steps += 1;
}

void gerak_2(float v, float t, float theta)
{
	hapusRedo();
	float dx = v * cos(theta * M_PI / 180) * t;
	float dy = v * sin(theta * M_PI / 180) * t;
	rx.push_back(round((rx[steps]+dx)));
	ry.push_back(round((ry[steps]+dy)));
	steps += 1;
}

void undo()
{
	if (steps > 0)
	{
		steps--;
		cout << "Undo Berhasil" << endl;;
	}
	else
	{
		cout << "Tidak dapat undo" << endl;
	}
}

void redo()
{
	if (steps < rx.size() - 1)
	{
		steps++;
		cout << "Redo berhasil" << endl;
	}
	else 
	{
		cout << "Tidak dapat redo" << endl;
	}
}

void save()
{
	bool confirmed = false;
	while (!confirmed)
	{
		string confirm;
		cout << 
		"Apakah Anda yakin ingin save?\n"
		"Data yang tersimpan sebelumnya akan hilang.\n"
		"(y/n)" 
		<< endl;

		cin >> confirm;
		if (confirm == "y")
		{
			ofstream file("checkpoint.txt");
			file << steps << endl;
			for (int i = 0; i < steps+1; i++)
			{
				file << rx[i] << " " << ry[i] << endl;
			}
			file.close();
			confirmed = true;
			cout << "\nSave berhasil!" << endl;
		}
		else if (confirm == "n")
		{
			cout << "\nSave dibatalkan" << endl;
			confirmed = true;
		}
		else
		{
			cout << "\nInput tidak valid" << endl;
		}
	}
}

void load()
{
	bool confirmed = false;
	while (!confirmed)
	{
		string confirm;
		cout << 
		"Apakah Anda yakin ingin load?\n"
		"Data saat ini akan hilang.\n"
		"(y/n)" 
		<< endl;

		cin >> confirm;
		if (confirm == "y")
		{
			int n = rx.size();
			for (int i = 0; i < n; i++)
			{
				rx.pop_back();
				ry.pop_back();
			}
			
			ifstream file("checkpoint.txt");
			file >> steps;

			for (int i = 0; i < steps + 1; i++)
			{
				float x, y;
				file >> x >> y;
				rx.push_back(x);
				ry.push_back(y);
			}
			file.close();
			confirmed = true;
			cout << "\nLoad berhasil!" << endl;
		}
		else if (confirm == "n")
		{
			confirmed = true;
			cout << "\nLoad dibatalkan" << endl;
		}
		else
		{
			cout << "\nInput tidak valid" << endl;
		}
		cout << endl;
	}
	
}

void input()
{
	string perintah;
	string daftar;

	daftar = 
	"========================\n"
	"DAFTAR PERINTAH DRONE\n"
	"========================\n"
	"1. lokasi\n"
	"2. gerak\n"
	"3. gerak_2\n"
	"4. undo\n"
	"5. redo\n"
	"6. save\n"
	"7. load\n"
	"8. exit\n"
	"========================\n"
	"Masukkan perintah:";

	cout << daftar << endl;

	cin >> perintah;

	cout << endl;

	if (perintah == "lokasi")
	{
		lokasi();
	}
	else if (perintah == "gerak")
	{
		float dx, dy;
		cout << "Masukkan gerakkan (dx, dy) dipisah dengan spasi:" << endl;
		cin >> dx >> dy;
		gerak(dx, dy);
	}
	else if (perintah == "gerak_2")
	{
		float v, t, theta;
		cout << "Masukkan parameter (v, t, theta) dipisah dengan spasi:" << endl;
		cout << "*satuan: v (kotak/detik), t (detik), thetha (derajat)" << endl;
		cin >> v >> t >> theta;
		gerak_2(v, t, theta);
	}	
	else if (perintah == "undo")
	{
		undo();
	}
	else if (perintah == "redo")
	{
		redo();
	}
	else if (perintah == "save")
	{
		save();
	}
	else if (perintah == "load")
	{
		load();
	}
	else if (perintah == "exit")
	{
		exit(0);
	}
	else
	{
		cout << "Perintah tidak valid" << endl;
	}

	cout << endl;
}



int main()
{
	rx.push_back(0.00);
	ry.push_back(0.00);


	while(true)
	{
		input();
	}

}

