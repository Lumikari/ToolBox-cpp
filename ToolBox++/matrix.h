#pragma once
#include "vector.h"

#include <iostream>
#include <vector>


class Matrix {
private:
    std::vector<std::vector<float>> data;
    int numRows, numCols;
    bool square = false;
    

    

public:
    Matrix(int m, int n) {
        numRows = m;
        numCols = n;
        data.resize(m, std::vector<float>(n));
    }

    std::vector<float>& operator[](int i);
    std::vector<float> operator[](int i) const;
        

    int getNumRows() const;

    int getNumCols() const;

    //@brief negative of a matrix
    Matrix operator-() const; 
    //@brief norm 
    float norm() const; 

    //@brief get diagonal in a vector
    Vector getDiagonale() const;
    //@brief Trace of matrix;
    float getTr() const;

    //@brief transpose of the matrix
    Matrix transpose() const;
    

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const float& other) const;
    Matrix operator*(const Matrix& other) const;

    void print() const;


};
