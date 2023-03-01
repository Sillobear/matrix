#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

int main() {
    Matrix<double> matrix1(3, 3, 7.0);
    Matrix<double> matrix2(3, 3, 4);
    Matrix<double> matrix3 = matrix1 + matrix2;
    for (int i=0; i<matrix3.get_rows(); i++) {
        for (int j=0; j<matrix3.get_columns(); j++) {
            std::cout << matrix3(i,j) << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
