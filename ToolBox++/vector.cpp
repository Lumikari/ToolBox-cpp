#include "vector.h"
#include <math.h>
#include <numbers>

float& Vector::operator[](int i)
{
    return data[i];
}

float Vector::operator[](int i) const
{
    return data[i];
}

int Vector::getSize() const
{
    return size;
}

float Vector::norm() const
{
    float sum_of_square = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum_of_square += data[i] * data[i];
    }
    return sqrt(sum_of_square);
}

float Vector::scalar(const Vector& other) const 
{
    if (size != other.getSize()) {
        throw std::invalid_argument("Vectors must have same size for scalar product");
    }

    float result = 0.0f;
    for (int i = 0; i < size; i++) 
    {
        result += data[i] * other[i];
    }
    return result;
}

Vector Vector::product(const Vector& other) const {
    if (size != 3 || other.getSize() != 3) {
        throw std::invalid_argument("Vectors must have size 3 for cross product");
    }

    float i = data[1] * other[2] - data[2] * other[1];
    float j = data[2] * other[0] - data[0] * other[2];
    float k = data[0] * other[1] - data[1] * other[0];

    Vector result(3);
    result[0] = i;
    result[1] = j;
    result[2] = k;
    return result;
}

float Vector::angle(const Vector& other) const
{
    float result;
    if (size != other.getSize())
    {
        throw std::invalid_argument("Vectors must have same size");
    }
    if (size < 2 || size > 3)
    {
        throw std::invalid_argument("Vectors must have a size of 2 or 3");
    }


    float up = scalar(other);
    Vector down(2);
    down[0] = norm();
    down[1] = other.norm();
    
    result = up / (down[0] * down[1]);
    
    return std::acosf(result) ;
}

Vector Vector::operator-() const
{
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result[i] = -data[i];
    }
    return result;
}

Vector Vector::operator+(const Vector& other) const
{
    if (size != other.getSize()) 
    {
        throw std::invalid_argument("Vectors must have same size for addition");
    }
    else {


        Vector result(size);
        for (int i = 0; i < size; i++)
        {
            result[i] = data[i] + other[i];
        }
        return result;
    }
}


void Vector::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
        std::cout << std::endl;
    
}
