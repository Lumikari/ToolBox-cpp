#pragma once

#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<float> data;
    int size;

public:
    Vector(int n) {
        size = n;
        data.resize(n);
    }

    float& operator[](int i);
    float operator[](int i) const;
    

    int getSize() const;

    float norm() const;// norm of the vector

    float scalar(const Vector& other) const; // scalar product
    Vector product(const Vector& other) const; // vectorial product
    float angle(const Vector& other) const;
    float distance(const Vector& other) const;

    Vector operator-() const; // negative of matrix
    Vector operator+(const Vector& other) const;

    void print() const;
    
};