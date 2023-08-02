#ifndef HANDIN5_MATRIX_H
#define HANDIN5_MATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include "exceptions.h"

template<typename T, typename U>
concept addition = requires (T a, U b) {
    { a + b } -> std::same_as<T>;
    { b + a } -> std::same_as<T>;
};

template<typename T, typename U>
concept subtraction = requires (T a, U b) {
    { a - b } -> std::same_as<T>;
    { b - a } -> std::same_as<T>;
};

template<typename T, typename U>
concept multiplication = requires (T a, U b) {
    { a * b } -> std::same_as<T>;
    { b * a } -> std::same_as<T>;
};

template<typename T, typename U>
concept division = requires (T a, U b) {
    { a / b } -> std::same_as<T>;
    { b / a } -> std::same_as<T>;
};

template<typename T, typename U = int>
concept modulo = requires (T a, U b) {
    { a % b } -> std::same_as<T>;
};

template <typename T>
class Matrix {
private:
    int n, m;
    std::vector<std::vector<T>> matrix;
    void check_out_of_bounds(int n, int m) const;
    void check_is_same_dimension(Matrix m) const;
public:
    void Move(int from_row, int from_column, int to_row, int to_column);
    Matrix(int n, int m);
    Matrix& operator=(const Matrix& other); // assignment
    Matrix(const Matrix& other);            // copy
    Matrix(Matrix&& other);                 // move

    template<typename U>
    requires addition<T,U>
    Matrix<T> operator+(const Matrix<U>& m1);     // plus

    template<typename U>
    requires addition<T,U>
    Matrix<T> operator-(const Matrix<U>& m1);     // minus

    template<typename U>
    requires multiplication<T,U>
    Matrix<T> operator*(const Matrix<U>& m1);     // times

    template<typename U>
    requires division<T,U>
    Matrix<T> operator/(const Matrix<U>& m1);     // division

    template<typename U = int>
    requires modulo<T,U>
    Matrix<T> operator%(int value);     // modulo

    T& operator()(int x, int y);            // subscript

    // General methods
    std::vector<T> Row(int n);
    std::vector<T> Column(int m);
    void print();

    // Methods used for easier testing
    void set_all_values_to(T value);
};

template<typename T>
template<typename U>
requires modulo<T, U>
Matrix<T> Matrix<T>::operator%(int value) {
    Matrix result = Matrix(this->n, this->m);

    for (int i = 0; i != this->n; ++i) {
        for (int j = 0; j != this->m; ++j) {
            result.matrix[i][j] = this->matrix[i][j] % value;
        }
    }

    return result;
}

template<typename T>
template<typename U>
requires addition<T, U>
Matrix<T> Matrix<T>::operator+(const Matrix<U> &m1) {
    return Matrix<T>(0, 0);
}

template<typename T>
void Matrix<T>::Move(int from_row, int from_column, int to_row, int to_column) {
    this->matrix[to_row][to_column] = this->matrix[from_row][from_column];
    this->matrix[from_row][from_column] = T{};
}

template<typename T>
T &Matrix<T>::operator()(int x, int y) {
    this->check_out_of_bounds(x, y);
    return this->matrix[x][y];
}

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
