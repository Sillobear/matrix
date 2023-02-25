//
// Created by silas on 24.02.23.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

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
}

#endif