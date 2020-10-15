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

    list.print_list();
    std:: cout << list.contains(30);
}