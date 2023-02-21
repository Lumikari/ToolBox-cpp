#pragma once

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int numRows, numCols;
    bool square = false;
    

public:
    Matrix(int m, int n) {
        numRows = m;
        numCols = n;
        data.resize(m, std::vector<double>(n));
    }

    std::vector<double>& operator[](int i);
    std::vector<double> operator[](int i) const;
        

    int getNumRows() const;

    int getNumCols() const;

    Matrix operator-() const;

    double norm() const;

    void print() const;


};
