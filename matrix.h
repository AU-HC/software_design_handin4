#ifndef HANDIN5_MATRIX_H
#define HANDIN5_MATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include "exceptions.h"

template <typename T>
class Matrix {
private:
    int n, m;
    std::vector<std::vector<T>> matrix;
    void check_out_of_bounds(int n, int m) const;
    void check_is_same_dimension(Matrix m) const;
public:
    void Move(int x, int y);
    Matrix(int n, int m);
    Matrix& operator=(const Matrix& other); // assignment
    Matrix(const Matrix& other);            // copy
    Matrix(Matrix&& other);                 // move
    Matrix operator+(const Matrix& m1);     // plus
    Matrix operator-(const Matrix& m1);     // minus
    Matrix operator*(const Matrix& m1);     // times
    Matrix operator/(const Matrix& m1);     // division
    Matrix operator%(const Matrix& m1);     // modulo
    int& operator()(int x, int y);            // subscript

    // General methods
    std::vector<T> Row(int n);
    std::vector<T> Column(int m);
    void print();

    // Methods used for easier testing
    void set_all_values_to(T value);
};

template<typename T>
void Matrix<T>::check_is_same_dimension(Matrix m) const {
    bool is_out_of_bounds = n >= this->n || m >= this->m;
    if (is_out_of_bounds)
        throw MatrixIndexOutOfBoundsException();
}

template<typename T>
void Matrix<T>::check_out_of_bounds(int n, int m) const {
    bool is_out_of_bounds = n >= this->n || m >= this->m;
    if (is_out_of_bounds)
        throw MatrixIndexOutOfBoundsException();
}

template<typename T>
Matrix<T>::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    matrix.resize(m, std::vector<T>(n, T {}));
}

template<typename T>
void Matrix<T>::print() {
    std::cout << "\n";
    for (std::vector<T> row : this->matrix) {
        for (T value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}


#endif //HANDIN5_MATRIX_H
