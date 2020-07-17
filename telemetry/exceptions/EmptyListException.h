#ifndef EMPTY_LIST_EXCEPTION_H
#define EMPTY_LIST_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

class EmptyListException: std::exception {
public:
    // member functions;
    std::string what();

    // data members;
    std::string listName;

    // constructors;
    EmptyListException(std::string data) {
        listName = data;
    }
};

std::string EmptyListException::what() {
    return std::string("List " + listName + " is empty.");
}

#endif
