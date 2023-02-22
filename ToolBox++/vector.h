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

    // @brief norm of the vector
    float norm() const;
    //@brief scalar product
    float scalar(const Vector& other) const; 
    //@brief vectorial product
    Vector product(const Vector& other) const; 
    //@brief angle between vectors
    float angle(const Vector& other) const;
    //@brief distance between
    float distance(const Vector& other) const;

    Vector operator-() const; // negative of matrix
    Vector operator+(const Vector& other) const;

    void print() const;
    
};