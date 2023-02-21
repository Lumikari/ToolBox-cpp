#include "matrix.h"
#include <vector>



std::vector<double>& Matrix::operator[](int i)
{
    return data[i];
}

std::vector<double> Matrix::operator[](int i) const
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

double Matrix::norm() const
{
    double sum_of_squares = 0.0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            sum_of_squares += data[i][j] * data[i][j];
        }
    }
    return sqrt(sum_of_squares);

}

void Matrix::print() const {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
