#include "include/Matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<float>> a {
        {1, 2, 3},
        {2, 3, 1}
    };

    vector<vector<float>> b {
        {0, 2, 4},
        {1, 2, 5},
        {8, 2, 1.2}
    };

    Matrix A = a;
    Matrix B = b;
    Matrix C (2, 3);

    cout << "Matrix A" << endl;
    A.display();

    cout << "Matrix B" << endl;
    B.display();

    cout << "Matrix C" << endl;
    C.display();

    cout << endl;

    Matrix C1 = A + C;
    cout << "Matrix C1" << endl;
    C1.display();
    cout << endl;

    Matrix C2 = A - C;
    cout << "Matrix C2" << endl;
    C2.display();
    cout << endl;

    Matrix C3 = A * B;
    cout << "Matrix C3" << endl;
    C3.display();
    cout << endl;
    
    Matrix C4 = B * A;
    cout << "Matrix C4" << endl;
    C4.display();
    cout << endl;

    cout << "Press any key to exit";
    cin.get();

    return 0;
}