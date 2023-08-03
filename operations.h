#ifndef HANDIN5_OPERATIONS_H
#define HANDIN5_OPERATIONS_H

template <typename T, typename U = T>
struct Multiply {
    T operator()(T a, U b) const {
        return a * b;
    }
};

template <typename T, typename U = T>
struct Addition {
    T operator()(T a, U b) const {
        return a + b;
    }
};

template <typename T, typename U = T>
struct Subtraction {
    T operator()(T a, U b) const {
        return a - b;
    }
};

template <typename T, typename U = T>
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

#endif //HANDIN5_OPERATIONS_H
