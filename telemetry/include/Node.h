#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template <class T>
struct Node {
    Node *next;
    Node *prev;
    T data;

public:

    Node(T arg) {
        next = nullptr;
        prev = nullptr;
        data = arg;
    }

    //every node initialised without a data argument gets initialised to NULL by default;
    Node() {
        next = nullptr;
        prev = nullptr;
        data = NULL;
    }

    virtual ~Node(){
        next = nullptr;
        prev = nullptr;  
    }
};

#endif
