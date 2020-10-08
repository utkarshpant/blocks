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
        next = NULL;
        prev = NULL;
        data = arg;
    }

    //every node initialised without a data argument gets initialised to NULL by default;
    Node() {
        next = NULL;
        prev = NULL;
        data = NULL;
    }
   virtual ~Node(){
        next = NULL;
        prev = NULL;
        
    }
};

#endif
