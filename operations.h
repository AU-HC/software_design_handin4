#ifndef HANDIN5_OPERATIONS_H
#define HANDIN5_OPERATIONS_H

template <typename T, typename U>
struct MultiplyTwo {
    T operator()(T a, U b) const {
        return a * b;
    }
};

template <typename T>
struct Addition {
    T operator()(T a, T b) const {
        return a + b;
    }
};

template <typename T, typename U>
struct AdditionTwo {
    T operator()(T a, U b) const {
        return a + b;
    }
};

template <typename T>
struct Subtraction {
    T operator()(T a, T b) const {
        return a - b;
    }
};

template <typename T, typename U>
struct SubtractionTwo {
    T operator()(T a, U b) const {
        return a - b;
    }
};

template <typename T>
struct Division {
    T operator()(T a, T b) const {
        return a / b;
    }
};

template <typename T, typename U>
struct DivisionTwo {
    T operator()(T a, U b) const {
        return a / b;
    }
};

template <typename T>
struct Modulo {
    T operator()(T a, T b) const {
        return a % b;
    }
};

template <typename T>
struct ModuloTwo {
    T operator()(T a, T b) const {
        return a % b;
    }
};

#endif //HANDIN5_OPERATIONS_H
