#ifndef HANDIN5_I_MATRIX_H
#define HANDIN5_I_MATRIX_H

#include <vector>
#include <iostream>

class IMatrix {
private:
    int n, m;
    std::vector<std::vector<int>> matrix;
    void check_out_of_bounds(int n, int m) const;
    void check_is_same_dimension(IMatrix m) const;
public:
    void Move(int from_row, int from_column, int to_row, int to_column);
    IMatrix(int n, int m);
    IMatrix& operator=(const IMatrix& other); // assignment
    IMatrix(const IMatrix& other);            // copy
    IMatrix(IMatrix&& other);                 // move
    IMatrix operator+(const IMatrix& m1);     // plus
    IMatrix operator-(const IMatrix& m1);     // minus
    IMatrix operator*(const IMatrix& m1);     // times
    IMatrix operator*(int scalar);            // times
    IMatrix operator/(const IMatrix& m1);     // division
    IMatrix operator%(const IMatrix& m1);     // modulo
    int& operator()(int x, int y);            // subscript

    // General methods
    std::vector<int> Row(int n);
    std::vector<int> Column(int m);
    std::string to_string();
    int get_n() { return n; }
    int get_m() { return m; }

    // Methods used for easier testing
    void set_all_values_to(int value);
};

#endif //HANDIN5_I_MATRIX_H