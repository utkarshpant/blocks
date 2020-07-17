#ifndef OUT_OF_BOUNDS_EXCEPTION_H
#define OUT_OF_BOUNDS_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class OutOfBoundsException: std::exception {
public:
    // member functions;
    std::string what();

    // data members;
    int index;

    // constructors;
    OutOfBoundsException(int data) {
        index = data;
    }
};

std::string OutOfBoundsException::what() {
    return std::string("Index " + std::to_string(index) + " is out of bounds.");
}

#endif
