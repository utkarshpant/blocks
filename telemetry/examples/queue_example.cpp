#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    std::cout << "The queue has elements:\n";
    while (!q.empty()) {
        std::cout << q.pop();
    }

    std::cout << "The size of the queue when empty is " << q.size() << std::endl;
    q.push(55);
    q.push(65);

    return 0;
}