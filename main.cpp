#include <iostream>
#include <cstdlib>
#include "List.h"

int main() {
    List<std::string> list;
    list.pushBack("ab");
    list.pushBack("ad");
    list.pushFront("fb");
    list.pushFront("jk");
    list.pushBack("jg");
    list.pushBack("hc");
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

    return 0;
}