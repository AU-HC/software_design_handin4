#include <vector>
#include <iostream>

#ifndef HANDIN5_I_MATRIX_H
#define HANDIN5_I_MATRIX_H

class IMatrix {
private:
    int n, m;
    std::vector<std::vector<int>> matrix;
public:
    void Move(int x, int y);
    // Constructor
    IMatrix(int n, int m);

    // Assignment, copy, and move constructors
    // ...

    std::vector<int> Row(int n);
    std::vector<int> Column(int n);

    // Operators
    IMatrix& operator=(const IMatrix& other); // assignment
    IMatrix(const IMatrix& other);            // copy
    IMatrix(IMatrix&& other);                 // move
    IMatrix operator+(IMatrix m1);            // plus
    IMatrix operator-(IMatrix m1);            // minus
    IMatrix operator*(IMatrix m1);            // times
    IMatrix operator/(IMatrix m1);            // division
    IMatrix operator%(IMatrix m1);            // modulo
    int* operator()(int x, int y);            // subscript
    std::string to_string();                  // pretty print string
};

std::ostream& operator<<(std::ostream& os, const IMatrix&);

#endif //HANDIN5_I_MATRIX_H
