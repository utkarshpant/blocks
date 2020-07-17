#include <iostream>
#include "include\Stack.h"

int main(int argc, char **argv) {
    
    std::string arg;
    std::cin >> arg;
    // program to reverse a string using a stack;
    Stack<char> stack;
    std::string reversed;

    if (arg == "") {
        // empty argument;
        return -1;
    } else {
        // push each character in arg into the stack;
        for (char s : arg) {
            stack.push(s);
        }
    }

    while (!stack.empty()) {
        reversed += stack.pop();
    }

    std::cout << reversed;
    return 0;
}