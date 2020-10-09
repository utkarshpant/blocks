#include <iostream>
#include "List.h"

int main() {
    List<int> list;
    List<int> list2;  
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    std::cout << "Printing List 1:\n";
    try{
        list.print_list(",");
    } catch(EmptyContainerException e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "ID List 2:\t" << list2.getID() << std::endl;

    try{
        list.erase(3);
    } catch (OutOfBoundsException e) {
        std::cout << e.what() << std::endl;
    } catch(EmptyContainerException e) {
        std::cout << e.what() << std::endl;
    }

    list.print_list();


    // list.print_list();
}