#include "i_matrix.h"
#include "matrix.h"
#include <cassert>

void test_integer_matrix() {
    IMatrix matrix = IMatrix(3, 3);
    IMatrix matrix_two = IMatrix(3, 3);

    // testing that subscript works
    matrix(0, 0) = 1;
    assert(matrix(0,0) == 1);

    // testing that column works
    matrix(0, 0) = 1; matrix(1, 0) = 1; matrix(2, 0) = 1;
    for (int i : matrix.Column(0))
        assert(i == 1);

    // testing that row works
    matrix(0, 0) = 2; matrix(0, 1) = 2; matrix(0, 2) = 2;
    for (int i : matrix.Row(0))
        assert(i == 2);

    matrix.set_all_values_to(3);
    matrix_two.set_all_values_to(2);
    IMatrix five_value_matrix = matrix + matrix_two;
    for (int i = 0; i != 3; ++i) {
        for (int value : five_value_matrix.Row(0)) {
            assert(value == 5);
        }
    }

    matrix.set_all_values_to(3);
    matrix_two.set_all_values_to(2);
    IMatrix one_value_matrix = matrix - matrix_two;
    for (int i = 0; i != 3; ++i) {
        for (int value : one_value_matrix.Row(0)) {
            assert(value == 1);
        }
    }

    std::cout << "all tests passed";
}

int main() {
    test_integer_matrix();

    Matrix<std::string> matrix = Matrix<std::string>(2, 2);
    matrix.print();
}
