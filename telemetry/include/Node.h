#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template <class T>
struct Node {
    Node *next;
    Node *prev;
    T data;

public:
    // Node  {
    //     //every node initialised without a data argument gets initialised to 0 by default.
    //     next = NULL;
    //     prev = NULL;
    //     data = 0;
    // }
    Node(T arg) {
        next = NULL;
        prev = NULL;
        data = arg;
    }
};

#endif