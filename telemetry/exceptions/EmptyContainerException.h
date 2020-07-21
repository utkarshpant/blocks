#ifndef EMPTY_CONTAINER_EXCEPTION_H
#define EMPTY_CONTAINER_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class EmptyContainerException: std::exception {
public:
    // member functions;
    std::string what();

    // data members;
    std::string name;

    // constructors;
    EmptyContainerException(std::string data) {
        name = data;
    }
};

std::string EmptyContainerException::what() {
    return std::string("Container " + name + " is empty.");
}

#endif
