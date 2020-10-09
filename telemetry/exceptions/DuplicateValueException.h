#ifndef DUPLICATE_VALUE_EXCEPTION_H
#define DUPLICATE_VALUE_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class DuplicateValueException: std::exception {
public:
    // member functions;
    std::string what();

    // data members;
    std::string value;
    std::string ID;

    // constructors;
    DuplicateValueException(std::string data, std::string ID) {
        value = data;
        ID = ID;
    }
};

std::string DuplicateValueException::what() {
    return std::string("The value " + value + " is already present in container " + ID + ".");
}

#endif
