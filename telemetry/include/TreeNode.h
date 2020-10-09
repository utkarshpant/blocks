#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>

template <class T>
struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    T data;

public:

    Node(T arg) {
        left = NULL;
        right = NULL;
        data = arg;
    }

    //every node initialised without a data argument gets initialised to NULL by default;
    Node() {
        left = NULL;
        right = NULL;
        data = NULL;
    }
};

#endif