#include <iostream>
#include <cstdlib>
#include "List.h"


int main() {
    List list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(30);
    std::cout << list.pop() << " 1" << std::endl;
    try {
        std::cout << "HERE!";
        std::cout << list.pop() << " 2";
        std::cout << list.pop() << " 3";

    } catch(EmptyListException ex) {
        std::cout << "Exception caught!";
        std::cout << ex.what();
    }
    return 0;
}