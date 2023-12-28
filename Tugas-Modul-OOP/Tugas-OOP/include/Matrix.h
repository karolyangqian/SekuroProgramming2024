#ifndef MATRIX
#define MATRIX
#include <vector>

using namespace std;


class Matrix
{
private:
    int rows;
    int cols;
    vector<vector<float>> data;

public:
    Matrix(int rows, int cols);
    Matrix(vector<vector<float>> v);
    void size();
    void display();
    vector<vector<float>> get_data_twoDvecf();
    float get_data_val(int row, int col);
    void operator = (vector<vector<float>> v);
    Matrix operator + (Matrix m);
    Matrix operator - (Matrix m);
    Matrix operator * (Matrix m);
    Matrix scalarMultiply(float k);
};

#endif