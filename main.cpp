#include <iostream>
#include <cstdlib>
#include "List.h"

int main() {
    List<int> list;
    list.pushBack(10);
    list.pushBack(21);
    list.pushFront(32);
    list.pushFront(45);
    list.pushBack(54);
    list.pushBack(63);
    // std::cout << "The number of elements in the list is:\t" << list.getSize() << std::endl;
    list.printList(", ", ".");
    try {
        list.sort();
    } catch (EmptyListException ex) {
        std::cout << ex.what();
    }
    std::cout << "\n";
    list.printList(", ", ".");

    // for(int i = 0; i < 50; i++) {
    //     list.pushBack(rand() % 50);
    // }


    // demo of predicates/pointers to functions; 
    bool isEven(int a);
    list.remove_if(isEven);
    list.printList(", ");
    return 0;
}

bool isEven(int a) {
    if (a % 2 == 0) {
        return true;
    } else {
        return false;
    }
}