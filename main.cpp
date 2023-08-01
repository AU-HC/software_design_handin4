#include "i_matrix.h"

int main() {
    IMatrix matrix = IMatrix(5, 5);
    std::cout << matrix.to_string();
    std::cout << "==================\n";

    std::cout << matrix(0, 0);

}
