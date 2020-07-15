#ifndef STACK_UNDERFLOW_EXCEPTION_H
#define STACK_UNDERFLOW_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class StackUnderflowException: std::exception {
public:
    // member functions;
    std::string what();

    // data members;
    std::string ID;

    // constructors;
    StackUnderflowException(std::string identifier) {
        ID = identifier;
    }
};

std::string StackUnderflowException::what() {
    return std::string("Stack " + ID + " is empty.");
}

#endif
