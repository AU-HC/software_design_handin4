#include "i_matrix.h"
#include "matrix.h"
#include "chess_piece.h"
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
}

// Copied tests from IMatrix
void test_general_int_matrix() {
    Matrix<int> matrix = Matrix<int>(3, 3);
    Matrix<int> matrix_two = Matrix<int>(3, 3);

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
    Matrix plus_matrix = matrix + matrix_two;
    for (int i = 0; i != plus_matrix.get_n(); ++i) {
        for (int value : plus_matrix.Column(0)) {
            assert(value == 5);
        }
    }

    Matrix minus_matrix = matrix - matrix_two;
    for (int i = 0; i != minus_matrix.get_n(); ++i) {
        for (int value : minus_matrix.Column(0)) {
            assert(value == 1);
        }
    }

    matrix.set_all_values_to(2);
    matrix_two.set_all_values_to(2);
    Matrix multiply_matrix = matrix * matrix_two;
    for (int i = 0; i != multiply_matrix.get_n(); ++i) {
        for (int value : multiply_matrix.Column(0)) {
            assert(value == 12);
        }
    }

    matrix.set_all_values_to(5);
    Matrix scalar_matrix = matrix * 2;
    for (int i = 0; i != scalar_matrix.get_n(); ++i) {
        for (int value : scalar_matrix.Column(0)) {
            assert(value == 10);
        }
    }

    matrix.set_all_values_to(5);
    Matrix plus_int_matrix = matrix + 2;
    for (int i = 0; i != plus_int_matrix.get_n(); ++i) {
        for (int value : plus_int_matrix.Column(0)) {
            assert(value == 7);
        }
    }
}

void test_general_string_matrix() {

}

Matrix<Chess_piece> setup_chessboard() {
    Matrix<Chess_piece> board = Matrix<Chess_piece>(8, 8);

    // Insert pawns
    for (int i = 0; i != 8; ++i) {
        board(1, i) = Chess_piece(false, Chess_piece_type::pawn);
        board(6, i) = Chess_piece(true, Chess_piece_type::pawn);
    }

    // Insert rooks
    board(0, 0) = Chess_piece(false, Chess_piece_type::rook);
    board(0, 7) = Chess_piece(false, Chess_piece_type::rook);
    board(7, 7) = Chess_piece(true, Chess_piece_type::rook);
    board(7, 0) = Chess_piece(true, Chess_piece_type::rook);

    // Insert bishops
    board(0, 1) = Chess_piece(false, Chess_piece_type::knight);
    board(0, 6) = Chess_piece(false, Chess_piece_type::knight);
    board(7, 6) = Chess_piece(true, Chess_piece_type::knight);
    board(7, 1) = Chess_piece(true, Chess_piece_type::knight);

    // Insert knights
    board(0, 2) = Chess_piece(false, Chess_piece_type::bishop);
    board(0, 5) = Chess_piece(false, Chess_piece_type::bishop);
    board(7, 5) = Chess_piece(true, Chess_piece_type::bishop);
    board(7, 2) = Chess_piece(true, Chess_piece_type::bishop);

    // Insert queens
    board(0, 3) = Chess_piece(false, Chess_piece_type::queen);
    board(7, 3) = Chess_piece(true, Chess_piece_type::queen);

    // Insert kings
    board(0, 4) = Chess_piece(false, Chess_piece_type::king);
    board(7, 4) = Chess_piece(true, Chess_piece_type::king);

    return board;
}

int main() {
    test_integer_matrix();
    test_general_int_matrix();
    test_general_string_matrix();

    std::cout << "all tests passed\n\nPrinting chessboard and moving piece";

    Matrix<Chess_piece> chessboard = setup_chessboard();
    chessboard.Move(6, 4, 4, 4); // E4
    chessboard.print();
}
