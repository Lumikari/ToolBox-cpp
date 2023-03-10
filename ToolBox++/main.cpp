

#include <iostream>
#include "matrix.h"
#include "vector.h"
#include <numbers>

int main() {
    Matrix A(2, 3);
    std::cout << "Size of matrix A: " << A.getNumRows() << " x " << A.getNumCols() << std::endl;
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A.print();
    Matrix B = -A;
    std::cout << "Negative of matrix A: " << B.getNumRows() << " x " << B.getNumCols() << std::endl;
    B.print();


    std::cout << "Norm of matrix A: " << A.norm() << std::endl;

    std::cout << "Diagonal of matrix A': " << std::endl;
    Vector diag = A.getDiagonale();
    diag.print();
    std::cout << "Tr(A) =  " << A.getTr() <<std::endl;
    Matrix transpose = A.transpose();
    std::cout << "Transpose of matrix A': " << std::endl;
    transpose.print();

    Matrix Mproduct = A * transpose;
    std::cout << "Transpose of A * matrix A': " << std::endl;
    Mproduct.print();


    

    Vector v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    std::cout << "Size of vector v : " << v.getSize() << std::endl;
    v.print();
    std::cout << "Norm of vector v : " << v.norm() << std::endl;

    Vector w = -v;
    std::cout << "Size of the negative of vector v : " << w.getSize() << std::endl;
    w.print();

    Vector x(3);
    x[0] = 4;
    x[1] = 5;
    x[2] = 6;
    
    std::cout << "Size of vector x : " << x.getSize() << std::endl;
    x.print();
    std::cout << "Norm of vector x : " << x.norm() << std::endl;

    Vector z = x + v;
    std::cout << "Result of vector x and v : " ;
    z.print();

    Vector cross = x.product(v);
    std::cout << "Product of vector x and v : " ;
    cross.print();

    double scalar = x.scalar(v);
    std::cout << "Scalar product of x and v : " << scalar << std::endl;

    float angle = v.angle(x);
    std::cout << "Angle between x and v : " << angle * 180/(std::numbers::pi) << std::endl; //radian to degree

    float distance = v.distance(x);
    std::cout << "Distance between v and x : " << distance << std::endl;

    Vector a(2);
    a[0] = 0;
    a[1] = 4;
    std::cout << "Size of vector x : " << a.getSize() << std::endl;
    a.print();
    std::cout << "Norm of vector x : " << a.norm() << std::endl;

    Vector b(2);
    b[0] = 3;
    b[1] = 0;
    std::cout << "Size of vector b : " << b.getSize() << std::endl;
    b.print();
    std::cout << "Norm of vector b : " << b.norm() << std::endl;

    float scalar2 = a.scalar(b);
    std::cout << "Scalar product of a and b : " << scalar2 << std::endl;

    float angle2 = a.angle(b);
    std::cout << "Angle between a and b : " << angle2 * 180 / (std::numbers::pi) << std::endl; //radian to degree

    float distance2 = a.distance(b);
    std::cout << "Distance between v and x : " << distance2 << std::endl;






    return 0;

}