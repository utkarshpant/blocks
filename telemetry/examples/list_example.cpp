#include <iostream>
#include "List.h"

int main() {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.print_list();
}