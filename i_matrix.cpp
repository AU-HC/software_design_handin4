#include "i_matrix.h"


IMatrix::IMatrix(int n, int m) {
    auto rows = std::vector<std::vector<int>>(n);
    for (int i = 0; i != m; ++i) {
        rows[i] = std::vector<int>(m);
    }

    this->matrix = rows;
    this->n = n;
    this->m = m;
}

void IMatrix::Move(int x, int y) {

}

std::vector<int> IMatrix::Row(int n) {
    return std::vector<int>();
}

std::vector<int> IMatrix::Column(int n) {
    return std::vector<int>();
}

IMatrix IMatrix::operator+(IMatrix m1) {
    return IMatrix(0, 0);
}

IMatrix IMatrix::operator-(IMatrix m1) {
    return IMatrix(0, 0);
}

IMatrix IMatrix::operator*(IMatrix m1) {
    return IMatrix(0, 0);
}

IMatrix IMatrix::operator/(IMatrix m1) {
    return IMatrix(0, 0);
}

IMatrix IMatrix::operator%(IMatrix m1) {
    return IMatrix(0, 0);
}

std::string IMatrix::to_string() {
   std::string string;

   for (const auto& row : this->matrix) {
        for (int i : row) {
            string += std::to_string(i) + " ";
        }
        string += "\n";
   }

   return string;
}

int* IMatrix::operator()(int x, int y) {
    bool is_out_of_range = x > this->m || y > this->n;
    if (is_out_of_range) {
        std::cout << "test";
    }

    return &(this->matrix[x][y]);
}

IMatrix& IMatrix::operator=(const IMatrix& other) {
    this->matrix = other.matrix;
    this->n = other.n;
    this->m = other.m;

    return *this;
}

IMatrix::IMatrix(const IMatrix &other) {
    this->matrix = other.matrix;
    this->m = other.m;
    this->n = other.n;
}

IMatrix::IMatrix(IMatrix &&other) {
    this->matrix = other.matrix; // assign data members from the source object to the object that is being constructed
    this->matrix = std::vector<std::vector<int>>(); // assign data of the source object to default values
}
