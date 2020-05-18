#ifndef NODE_H
#define NODE_H

#include <cstdlib>

struct Node {
    Node *next;
    Node *prev;
    int data;

public:
    // Node  {
    //     //every node initialised without a data argument gets initialised to 0 by default.
    //     next = NULL;
    //     prev = NULL;
    //     data = 0;
    // }

    Node (int arg = 0) {
        next = NULL;
        prev = NULL;
        data = arg;
    }
};

#endif