
#ifndef HANDIN5_EXCEPTIONS_H
#define HANDIN5_EXCEPTIONS_H

#include <exception>

class MatrixIndexOutOfBoundsException : public std::exception {
public:
    char * what() {
        return "Index out of bounds";
    }
};

class MatrixNotSameDimensionException : public std::exception {
public:
    char * what() {
        return "Matrices do not have the same dimensions";
    }
};


#endif //HANDIN5_EXCEPTIONS_H
