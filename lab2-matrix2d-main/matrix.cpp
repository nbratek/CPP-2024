#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix() {
    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++) {
            matrix_[i][j] = 0;
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &other) {
    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++) {
            matrix_[i][j] = other.get(i,j);
        }
    }

}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement other[size_][size_]) {
    for (size_t i = 0; i < size_; i++){
        for(size_t j = 0; j < size_; j++){
            matrix_[i][j] = other[i][j];
        }
    }

}

MatrixElement TwoDimensionMatrix::get(size_t row, size_t column) const {
    return matrix_[row][column];
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &other) {
    for(size_t i = 0; i <= size_-1; i++) {
        for(size_t j = 0; j <= size_-1; j++){
            matrix_[i][j] = other.matrix_[i][j];
        }
}
    return *this;


}

std::ostream &operator<<(std::ostream &stream, const TwoDimensionMatrix &matrix) {
    for(size_t i = 0; i < TwoDimensionMatrix::size(); i++){
        for(size_t j = 0; j < TwoDimensionMatrix::size(); j++){
             stream << matrix.get(i,j);
        }
    }
    return stream;
}

std::istream &operator>>(std::istream &stream,  TwoDimensionMatrix &matrix) {
    for(size_t i = 0; i < TwoDimensionMatrix::size(); i++){
        for(size_t j = 0; j < TwoDimensionMatrix::size(); j++){
            stream >> matrix.matrix_[i][j];
        }
    }
    return stream;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
    TwoDimensionMatrix matrix3;
    for(size_t i= 0; i < TwoDimensionMatrix::size(); i++){
        for (size_t j = 0; j < TwoDimensionMatrix::size();j++){
            matrix3[i][j] = matrix1.get(i, j) + matrix2.get(i,j);
        }
    }
    return matrix3;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(size_t i = 0; i < size_; i++){
        for (size_t j = 0; j < size_; j++){
            matrix_[i][j] *= number;
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const {
    TwoDimensionMatrix matrix1;
    for(size_t i = 0; i < TwoDimensionMatrix::size(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::size(); j++) {
            matrix1[i][j] = matrix_[i][j] && matrix.get(i, j);
        }
    }
    return matrix1;
}






