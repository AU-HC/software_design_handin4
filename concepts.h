#ifndef HANDIN5_CONCEPTS_H
#define HANDIN5_CONCEPTS_H

#include <vector>

template<typename T, typename U>
concept addition = requires (T a, U b) {
    { a + b } -> std::convertible_to<T>;
    { b + a } -> std::convertible_to<T>;
};

template<typename T, typename U>
concept subtraction = requires (T a, U b) {
    { a - b } -> std::convertible_to<T>;
    { b - a } -> std::convertible_to<T>;
};

template<typename T, typename U>
concept multiplication = requires (T a, U b) {
    { a * b } -> std::convertible_to<T>;
    { b * a } -> std::convertible_to<T>;
};

template<typename T, typename U>
concept division = requires (T a, U b) {
    { a / b } -> std::convertible_to<T>;
    { b / a } -> std::convertible_to<T>;
};

template<typename T, typename U = int>
concept modulo = requires (T a, U b) {
    { a % b } -> std::convertible_to<T>;
};

#endif //HANDIN5_CONCEPTS_H
