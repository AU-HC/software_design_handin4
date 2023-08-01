#include "i_matrix.h"

template <typename T>
struct Multiply {
    T operator()(T a, T b) const {
        return a * b;
    }
};

template <typename T>
struct Addition {
    T operator()(T a, T b) const {
        return a + b;
    }
};

template <typename T>
struct Subtraction {
    T operator()(T a, T b) const {
        return a - b;
    }
};

template <typename T>
struct Division {
    T operator()(T a, T b) const {
        return a / b;
    }
};

template <typename T>
struct Modulo {
    T operator()(T a, T b) const {
        return a % b;
    }
};

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
    // TODO: implement
}

std::vector<int> IMatrix::Row(int n) {
    this->check_out_of_bounds(n, 0);

    return this->matrix[n];
}

std::vector<int> IMatrix::Column(int m) {
    this->check_out_of_bounds(0, m);

    auto column = std::vector<int>(0);
    for (int i = 0; i != this->n; ++i) {
        column.push_back(this->matrix[i][m]);
    }

    return column;
}

template <typename Oper>
IMatrix perform_operation(IMatrix m1, IMatrix m2, Oper op) {
    IMatrix result = IMatrix(3, 3);

    for (int i = 0; i != 3; ++i) {
        for (int j = 0; j != 3; ++j) {
            result(i, j) = op(m1(i, j), m2(i, j));
        }
    }

    return result;
}

IMatrix IMatrix::operator+(const IMatrix& m1) {
    this->check_is_same_dimension(m1);
    return perform_operation(*this, m1, Addition<int>());
}

IMatrix IMatrix::operator-(const IMatrix& m1) {
    this->check_is_same_dimension(m1);
    return perform_operation(*this, m1, Subtraction<int>());
}

IMatrix IMatrix::operator*(const IMatrix& m1) {
    this->check_is_same_dimension(m1);
    return perform_operation(*this, m1, Multiply<int>());
}

IMatrix IMatrix::operator/(const IMatrix& m1) {
    this->check_is_same_dimension(m1);
    return perform_operation(*this, m1, Division<int>());
}

IMatrix IMatrix::operator%(const IMatrix& m1) {
    this->check_is_same_dimension(m1);
    return perform_operation(*this, m1, Modulo<int>());
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

int& IMatrix::operator()(int x, int y) {
    this->check_out_of_bounds(x, y);

    return this->matrix[x][y];
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
    this->n = 0;
    this->m = 0;
}

void IMatrix::set_all_values_to(int value) {
    for (int i = 0; i != this->n; ++i) {
        for (int j = 0; j != this->m; ++j) {
            this->matrix[i][j] = value;
        }
    }
}

void IMatrix::check_out_of_bounds(int n, int m) const {
    bool is_out_of_bounds = n >= this->n || m >= this->m;
    if (is_out_of_bounds)
        throw IMatrixIndexOutOfBoundsException();
}

void IMatrix::check_is_same_dimension(IMatrix m) const {
    bool not_same_dimension = this->n != m.n || this->m != m.m;

    if (not_same_dimension)
        throw IMatrixNotSameDimensionException();
}

