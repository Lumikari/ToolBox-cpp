#include "matrix.h"
#include "vector.h"
#include <vector>



std::vector<float>& Matrix::operator[](int i)
{
    return data[i];
}

std::vector<float> Matrix::operator[](int i) const
{
    return data[i];
}

int Matrix::getNumRows() const {
    return numRows;
}

int Matrix::getNumCols() const
{
    return numCols;
}

Matrix Matrix::operator-() const
{
    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            result[i][j] = -data[i][j];
        }
    }
    return result;
}

float Matrix::norm() const
{
    float sum_of_squares = 0.0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            sum_of_squares += data[i][j] * data[i][j];
        }
    }
    return sqrt(sum_of_squares);

}

Vector Matrix::getDiagonale() const 
{
    Vector result(std::min(numRows, numCols));
    for (int i = 0; i < result.getSize(); i++) {
        result[i] = data[i][i];
    }
    return result;
}

float Matrix::getTr() const
{
    float result = 0.0;
    Vector diag = getDiagonale();
    for (int i = 0; i < diag.getSize(); i++)
    {
        result += diag[i];
    }
    return result;
}

Matrix Matrix::transpose() const
{
    Matrix transpose(getNumCols(), getNumRows());

    for (int i = 0; i < getNumCols(); i++)
    {
        for (int j = 0; j < getNumRows(); j++)
        {
            transpose[i][j] = data[j][i];
        }
    }

    return transpose;
}

Matrix Matrix::operator+(const Matrix& other) const
{ 
        if (getNumCols() != other.getNumCols() || getNumRows() != other.getNumRows())
        {
            throw std::invalid_argument("Matrxi must have same dimension for addition");
        }

            Matrix result(getNumCols(), getNumRows());
            for (int i = 0; i < getNumCols(); i++)
            {
                for (int j = 0; j < getNumRows(); j++)
                result[i][j] = data[i][j] + other[i][j];
            }
            return result;
        
    
}

Matrix Matrix::operator*(const float& other) const
{
    Matrix result(getNumCols(), getNumRows());

    for (int i = 0; i < getNumCols(); i++)
        for (int j = 0; j < getNumRows(); j++)
            result[i][j] = data[i][j] * other;

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    if (getNumRows() != other.getNumCols())
    {
        throw std::invalid_argument("");
    }

    Matrix result(getNumRows(), other.getNumCols());
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < other.numCols; j++) 
        {
            float sum = 0.0;
            for (int k = 0; k < numCols; k++) 
            {
                sum += data[i][k] * other.data[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void Matrix::print() const {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
