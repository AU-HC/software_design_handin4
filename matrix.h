#ifndef HANDIN5_MATRIX_H
#define HANDIN5_MATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include "exceptions.h"
#include "operations.h"
#include "concepts.h"

template <typename T>
class Matrix {
private:
    int _n{}, _m{};
    std::vector<std::vector<T>> matrix;
    void check_out_of_bounds(int n, int m) const;

    template<typename Oper, typename U>
    Matrix<T> perform_generic_operation_on_matrices(Matrix<U>& m1, Oper op);

    template<typename Oper, typename U>
    Matrix<T> perform_generic_operation_with_value(U value, Oper op);
public:
    Matrix(int n, int m);
    Matrix& operator=(const Matrix& other); // assignment
    Matrix(const Matrix& other);            // copy
    Matrix(Matrix&& other);                 // move

    template<typename U>
    requires addition<T,U>
    Matrix<T> operator+(Matrix<U>& m1);

    template<typename U>
    requires addition<T,U>
    Matrix<T> operator+(U value);

    template<typename U>
    requires subtraction<T,U>
    Matrix<T> operator-(Matrix<U>& m1);

    template<typename U>
    requires subtraction<T,U>
    Matrix<T> operator-(U value);

    template<typename U>
    requires multiplication<T,U>
    Matrix<T> operator*(const Matrix<U>& m1);

    template<typename U>
    requires multiplication<T,U>
    Matrix<T> operator*(U value);

    template<typename U>
    requires division<T,U>
    Matrix<T> operator/(U value);

    template<typename U = int>
    requires modulo<T,U>
    Matrix<T> operator%(int value);

    T& operator()(int x, int y);

    // General methods
    std::vector<T> Row(int n);
    std::vector<T> Column(int m);
    void print();
    void check_is_same_dimension(int n, int m);
    int get_n() { return _n; }
    int get_m() { return _m; }

    // Methods used for easier testing
    void set_all_values_to(T value);

    void Move(int from_row, int from_column, int to_row, int to_column);
};

template<typename T>
template<typename U>
requires subtraction<T, U>
Matrix<T> Matrix<T>::operator-(Matrix<U> &m1) {
    return this->perform_generic_operation_on_matrices(m1, SubtractionTwo<T, U>());
}

template<typename T>
template<typename U>
requires subtraction<T, U>
Matrix<T> Matrix<T>::operator-(U value) {
    return this->perform_generic_operation_with_value(value, SubtractionTwo<T, U>());
}

template<typename T>
template<typename U>
requires multiplication<T, U>
Matrix<T> Matrix<T>::operator*(const Matrix<U> &m1) {
    if (this->_n != m1._m || this->_m != m1._n)
        throw MatrixNotSameDimensionException();

    Matrix result = Matrix(this->_n, m1._m);
    for (int i = 0; i < this->_n; ++i) {
        for (int j = 0; j < m1._m; ++j) {
            for (int k = 0; k < this->_m; ++k) {
                result.matrix[i][j] += this->matrix[i][k] * m1.matrix[k][j];
            }
        }
    }

    return result;
}

template<typename T>
template<typename U>
requires multiplication<T, U>
Matrix<T> Matrix<T>::operator*(U value) {
    return this->perform_generic_operation_with_value(value, MultiplyTwo<T, U>());
}

template<typename T>
template<typename U>
requires division<T, U>
Matrix<T> Matrix<T>::operator/(U value) {
    return this->perform_generic_operation_with_value(value, DivisionTwo<T, U>());
}

template<typename T>
template<typename U>
requires modulo<T, U>
Matrix<T> Matrix<T>::operator%(int value) {
    return this->perform_generic_operation_with_value(value, Modulo<T>());
}

template<typename T>
template<typename U>
requires addition<T, U>
Matrix<T> Matrix<T>::operator+(U value) {
    return this->perform_generic_operation_with_value(value, AdditionTwo<T, U>());
}

template<typename T>
template<typename U>
requires addition<T, U>
Matrix<T> Matrix<T>::operator+(Matrix<U> &m1) {
    return this->perform_generic_operation_on_matrices(m1, AdditionTwo<T, U>());
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
void Matrix<T>::check_is_same_dimension(int n, int m) {
    bool is_not_same_dimension = n != this->_n || m != this->_m;
    if (is_not_same_dimension)
        throw MatrixNotSameDimensionException();
}

template<typename T>
void Matrix<T>::check_out_of_bounds(int n, int m) const {
    bool is_out_of_bounds = n >= this->_n || m >= this->_m;
    if (is_out_of_bounds)
        throw MatrixIndexOutOfBoundsException();
}

template<typename T>
Matrix<T>::Matrix(int n, int m) {
    this->_n = n;
    this->_m = m;
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

template<typename T>
void Matrix<T>::set_all_values_to(T value) {
    for (int i = 0; i != this->_n; ++i) {
        for (int j = 0; j != this->_m; ++j) {
            this->matrix[i][j] = value;
        }
    }
}

template<typename T>
std::vector<T> Matrix<T>::Column(int m) {
    this->check_out_of_bounds(0, m);

    auto column = std::vector<T>(0);
    for (int i = 0; i != this->_n; ++i) {
        column.push_back(this->matrix[i][m]);
    }

    return column;
}

template<typename T>
std::vector<T> Matrix<T>::Row(int n) {
    this->check_out_of_bounds(n, 0);
    return this->matrix[n];
}

template<typename T>
template<typename Oper, typename U>
Matrix<T> Matrix<T>::perform_generic_operation_on_matrices(Matrix<U> &m1, Oper op) {
    // Check if matrices are compatible
    this->check_is_same_dimension(m1.get_n(), m1.get_n());

    Matrix<T> result = Matrix<T>(m1.get_n(), m1.get_m());
    for (int i = 0; i != m1.get_n(); ++i) {
        for (int j = 0; j != m1.get_m(); ++j) {
            result(i, j) = op(this->matrix[i][j], m1(i, j));
        }
    }

    return result;
}

template<typename T>
template<typename Oper, typename U>
Matrix<T> Matrix<T>::perform_generic_operation_with_value(U value, Oper op) {
    Matrix<T> result = Matrix<T>(this->_n, this->_m);

    for (int i = 0; i != this->_n; ++i) {
        for (int j = 0; j != this->_m; ++j) {
            result(i, j) = op(this->matrix[i][j], value);
        }
    }

    return result;
}

#endif //HANDIN5_MATRIX_H
