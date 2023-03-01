//
// Created by silas on 24.02.23.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <vector>

template <typename T> class Matrix {
private:
    std::vector<std::vector<T> > mat;
    unsigned rows;
    unsigned colums;

public:
    Matrix(unsigned _rows, unsigned _cols, const T &_initial);
    Matrix(const Matrix<T> &rhs);
    virtual ~Matrix();

    // Operator overloading
    Matrix<T>& operator=(const Matrix<T> &rhs);
    bool operator==(const Matrix<T> &rhs);

    // Matrix Operations
    Matrix<T> operator+(const Matrix<T> &rhs);
    Matrix<T>& operator+=(const Matrix<T> &rhs);
    Matrix<T> operator-(const Matrix<T> &rhs);
    Matrix<T>& operator -=(const Matrix<T> &rhs);
    Matrix<T> operator*(const Matrix<T> &rhs);
    Matrix<T>& operator *=(const Matrix<T> &rhs);
    Matrix<T> transpose();

    // Scalar operations
    Matrix<T> operator+(const T &rhs);
    Matrix<T>& operator+=(const T &rhs);
    Matrix<T> operator-(const T &rhs);
    Matrix<T> operator*(const T &rhs);
    Matrix<T> operator/(const T &rhs);

    // Matrix/vector operations
    std::vector<T> operator*(const std::vector<T>& rhs);
    std::vector<T> diag_vec();


    T& operator()(const unsigned& row, const unsigned& col);
    const T& operator()(const unsigned& row, const unsigned& col) const;


    unsigned get_rows() const;
    unsigned get_columns() const;
};
#endif


