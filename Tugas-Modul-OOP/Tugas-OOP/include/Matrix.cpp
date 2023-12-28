#include "Matrix.h"
#include <iostream>
#include <vector>

using namespace std;


Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < this->rows; i++)
    {
        vector<float> temp;
        for (int j = 0; j < this->cols; j++)
        {
            temp.push_back(0);
        }
        this->data.push_back(temp);
    }
}

Matrix::Matrix(vector<vector<float>> v)
{
    bool colsValid = true;

    int i = 0;
    while (i < v.size()-1 && colsValid)
    {
        if (v[i].size() != v[i+1].size())
        {
            colsValid = false;
        }
        i++;
    }

    if (!(colsValid))
    {
        cout << "The input is not valid!\n" << endl;
        Matrix x(1, 1);
        this->data = x.data;
        this->rows = x.rows;
        this->cols = x.cols;
    } else {
        this->data = v;
        this->rows = v.size();
        this->cols = v[0].size();
    }
}

void Matrix::size()
{
    cout << "rows: " << this->rows << " columns: " << this->cols << endl;
}

void Matrix::display()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            cout << this->data[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<float>> Matrix::get_data_twoDvecf()
{
    return this->data;
}

float Matrix:: get_data_val(int row, int col)
{
    return this->data[row][col];
}

void Matrix::operator = (vector<vector<float>> v)
{
    this->data = v;
    this->rows = v.size();
    this->cols = v[0].size();
}

Matrix Matrix::operator + (Matrix m)
{
    bool rowsValid = m.rows == this->rows;
    bool colsValid = m.cols == this->cols;
    
    if (!(rowsValid && colsValid))
    {
        cout << "The Matrix dimension is not valid!\n" << endl;
        Matrix x(1, 1);
        return x;
    } else {
        Matrix temp(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                temp.data[i][j] = this->data[i][j] + m.data[i][j];
            }
        }
        return temp;
    }
}

Matrix Matrix::operator - (Matrix m)
{
    bool rowsValid = m.rows == this->rows;
    bool colsValid = m.cols == this->cols;
    
    if (!(rowsValid && colsValid))
    {
        cout << "The Matrix dimension is not valid!\n" << endl;
        Matrix x(1, 1);
        return x;
    } else {
        Matrix temp(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                temp.data[i][j] = this->data[i][j] - m.data[i][j];
            }
        }
        return temp;
    }
}

Matrix Matrix::operator * (Matrix m)
{
    bool Valid = this->cols == m.rows;
        
    if (!(Valid))
    {
        cout << "Multiplication cannot be done. The number of columns in " 
                "the first matrix should be equal to the number of rows in "
                "the second.\n\n"
                "Return 1 by 1 of zeros matrix\n" << endl;
        Matrix x(1, 1);
        return x;
    } else {
        Matrix temp(this->rows, m.cols);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                for (int k = 0; k < this->cols; k++)
                {
                    temp.data[i][j] += this->data[i][k] * m.data[k][j];
                }
            }
        }
        return temp;
    }
}

Matrix Matrix::scalarMultiply(float k)
{
    Matrix result = this->data;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            result.data[i][j] *= k;
        }
        
    }
    return result;
}
