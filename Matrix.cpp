//
// Created by silas on 24.02.23.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <stdexcept>
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _columns, const T& _initial){
    mat.resize(_rows);
    for (unsigned i=0; i<mat.size(); i++){
        mat[i].resize(_columns, _initial);
    }
    rows = _rows;
    colums = _columns;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &rhs) {
    mat = rhs.mat;
    rows = rhs.get_rows();
    colums = rhs.get_columns();
}

// (Virtual) Destructor
template<typename T>
Matrix<T>::~Matrix() {}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &rhs){
    if(&rhs == this){
        return *this;
    }

    unsigned new_cols = rhs.get_columns();
    unsigned new_rows = rhs.get_rows();

    if(rhs.size() != this->mat.size()){
        mat.resize(rhs.mat.size());
    }
    if(rhs.mat[1].size() != this->mat[1].size()) {
        for (unsigned i = 0; i < mat.size(); i++) {
            mat[i].resize(new_cols);
        }
    }
    for (unsigned i=0; i < mat.size(); i++){
        for (unsigned j=0; j < new_cols; j++){
            mat[i][j] = rhs(i, j);
        }
    }
    rows = new_rows;
    colums = new_cols;

    return *this;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T> &rhs){
    if (rows != rhs.rows){
        return false;
    }
    if (colums != rhs.colums){
        return false;
    }
    for (unsigned i=0; i<rows; i++){
        for (unsigned j=0; j<rows; j++){
            if(this->mat[i][j] != rhs(i,j)){
                return false;
            }
        }
    }
    return true;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs){
    Matrix<T> result(rows, colums, 0.0);

    for (unsigned i = 0; i<rows; i++){
        for (unsigned j = 0; j<colums; j++){
            result(i,j) = this->mat[i][j] + rhs(i,j);
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_columns();

    for (unsigned i = 0; i<rows; i++){
        for (unsigned j = 0; j<cols; i++){
            this->mat[i][j] += rhs(i,j);
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs){
    Matrix<T> result(rows, colums, 0.0);

    for (unsigned i = 0; i<rows; i++){
        for (unsigned j = 0; j<colums; j++){
            result(i,j) = this->mat[i][j] - rhs(i,j);
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_columns();

    for (unsigned i = 0; i<rows; i++){
        for (unsigned j = 0; j<cols; i++){
            this->mat[i][j] -= rhs(i,j);
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_columns();
    Matrix<T> result(rows, cols, 0.0);

    for(unsigned i=0;i<rows;i++){
        for(unsigned j=0;j<cols;j++){
            for(unsigned k=0;k<rows;k++){
                result(i,j) += this->mat[i][k] * rhs(k,j);
            }
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T> &rhs){
    Matrix<T> result = (*this) * rhs;
    this = result;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> result(colums, rows, 0.0);
    for(unsigned i=0;i<rows;i++){
        for(unsigned j=0;j<colums;j++){
            result(j,i) = this->mat[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T &rhs) {
    Matrix<T> result(rows, colums, 0.0);
    for (unsigned i=0; i<rows; i++){
        for (unsigned j=0; j<colums; j++){
            result(i,j) = this->mat[i][j] + rhs;
        }
    }
    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const T &rhs) {
    Matrix<T> result(rows, colums, 0.0);
    this = result + rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T &rhs) {
    Matrix<T> result(rows, colums, 0.0);
    for (unsigned i =0; i<rows; i++){
        for (unsigned j=0; j<colums; j++){
            result(i,j) = this(i,j) - rhs;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &rhs) {
    Matrix<T> result(rows, colums, 0.0);
    for (unsigned i =0; i<rows; i++){
        for (unsigned j=0; j<colums; j++){
            result(i,j) = this(i,j) * rhs;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &rhs) {
    Matrix<T> result(rows, colums, 0.0);
    for (unsigned i =0; i<rows; i++){
        for (unsigned j=0; j<colums; j++){
            result(i,j) = this(i,j) / rhs;
        }
    }
    return result;
}

template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T> &rhs){
    std::vector<T> result(rhs.size(), 0.0);
    for (unsigned i=0;i<rows; i++){
        for (unsigned j=0;j<colums; j++){
            result[i] += this->mat[i][j] * rhs[j];
        }
    }
    return result;
}

template<typename T>
std::vector<T> Matrix<T>::diag_vec() {
    if(rows != colums){
        throw std::invalid_argument("received non quadratic matrix");
    }
    std::vector<T> result(rows, 0.0);

    for (unsigned i=0; i<rows; i++) {
        result[i] = this->mat[i][i];
    }

    return result;
}

template<typename T>
T& Matrix<T>::operator()(const unsigned &row, const unsigned &col){
    return this->mat[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned &row, const unsigned &col) const{
    return this->mat[row][col];
}

template<typename T>
unsigned Matrix<T>::get_rows() const {
    return this->rows;
}

template<typename T>
unsigned Matrix<T>::get_columns() const {
    return this->colums;
}

#endif