#include <vector>
#include <iostream>

#ifndef HANDIN5_I_MATRIX_H
#define HANDIN5_I_MATRIX_H

class IMatrixIndexOutOfBoundsException : public std::exception {
public:
    char * what() {
        return "Index out of bounds";
    }
};

class IMatrixNotSameDimensionException : public std::exception {
public:
    char * what() {
        return "Index out of bounds";
    }
};

class IMatrix {
private:
    int n, m;
    std::vector<std::vector<int>> matrix;
    void check_out_of_bounds(int n, int m) const;
    void check_is_same_dimension(IMatrix m) const;
public:
    void Move(int x, int y);
    IMatrix(int n, int m);

    // Operators
    IMatrix& operator=(const IMatrix& other); // assignment
    IMatrix(const IMatrix& other);            // copy
    IMatrix(IMatrix&& other);                 // move
    IMatrix operator+(const IMatrix& m1);     // plus
    IMatrix operator-(const IMatrix& m1);     // minus
    IMatrix operator*(const IMatrix& m1);     // times
    IMatrix operator/(const IMatrix& m1);     // division
    IMatrix operator%(const IMatrix& m1);     // modulo
    int& operator()(int x, int y);            // subscript

    // General methods
    std::vector<int> Row(int n);
    std::vector<int> Column(int m);
    std::string to_string();

    // Methods used for easier testing
    void set_all_values_to(int value);
};

std::ostream& operator<<(std::ostream& os, const IMatrix&);

#endif //HANDIN5_I_MATRIX_H
