#include <iostream>
// #include "telemetry/include/List.h"
#include "telemetry/include/Stack.h"

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    while (stack.empty() == false) {
        std::cout << stack.pop() << std::endl;
    }
    return 0;
}