cmake_minimum_required(VERSION 3.25)
project(handin5)

set(CMAKE_CXX_STANDARD 20)

add_executable(handin5 main.cpp i_matrix.cpp i_matrix.h matrix.h matrix.cpp exceptions.h chess_piece.h chess_piece.cpp concepts.h)
