#include <iostream>
#include <cstdlib>
#include <chrono>
#include <Windows.h>
#include "List.h"
#include "Stack.h"

int main() {
    // List<int> list;
    // // list.pushBack(101);
    // // list.pushBack(33);
    // // list.pushFront(32);
    // // list.pushFront(45);
    // // list.pushBack(54);
    // // list.pushBack(63);

    // for(int i = 0; i < 10000; i++) {
    //     list.pushBack(rand() % 10000);
    // }
    // // std::cout << "The number of elements in the list is:\t" << list.getSize() << std::endl;
    // // list.printList(", ", ".");
    // try {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     list.sort();
    //     auto stop = std::chrono::high_resolution_clock::now();
    //     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //     std::cout << "\n" << "The list took " << duration.count() << " microseconds to sort." << "\n";

    // } catch (EmptyListException ex) {
    //     std::cout << ex.what();
    // }
    // std::cout << "\n";
    // list.printList(", ", ".");
    


    // demo of predicates/pointers to functions; 
    // bool isEven(int a);
    // list.remove_if(isEven);
    // list.printList(", ");

    Stack<int> obj;
    obj.push(15);
    obj.push(20);
    obj.push(30);
    obj.push(45);

    std::cout << Stack<int>::get_stack_count() << " Stack has been created, latest with ID " << obj.get_ID() << "\n";
    
    Stack<int> obj2;

    std::cout << Stack<int>::get_stack_count() << " Stacks have been created, latest with ID " << obj2.get_ID() << "\n";

    std::cout << "Stack 1 Empty:\t" << obj.empty() << "\n" << "Stack 2 Empty:\t" << obj2.empty() << "\n";

    
    while (obj.empty() == false) {
        std::cout << obj.pop() << "\n";
    }

    return 0;
}

// bool isEven(int a) {
//     if (a % 2 == 0) {
//         return true;
//     } else {
//         return false;
//     }
// }