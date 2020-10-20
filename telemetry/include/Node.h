#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template <class T>
struct Node {
    Node *next;
    Node *prev;
    T data;

public:

    explicit Node(T arg) : data(arg) {
        next = nullptr;
        prev = nullptr;
        // data = arg;
        // data gets initialised to a value in the initialization list;
    }

    //every node initialised without a data argument gets initialised to NULL by default;
    Node(): data(NULL) {
        next = nullptr;
        prev = nullptr;
        // data = NULL;
    }

    virtual ~Node(){
        next = nullptr;
        prev = nullptr;  
    }
};

#endif
