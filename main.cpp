#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int> matrix1(3, 3, 7);
    Matrix<int> matrix2(3, 3, 4);
    Matrix<int> matrix3 = matrix1 + matrix2;
    for (unsigned i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < 3; ++j) {
            std::cout << matrix3(i, j) << std::endl;
        }
    }
    return 0;
}
