#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>

template <class T>
struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    T data;

public:

    TreeNode(T arg) {
        left = nullptr;
        right = nullptr;
        data = arg;
    }

    //every node initialised without a data argument gets initialised to NULL by default;
    TreeNode() {
        left = nullptr;
        right = nullptr;
        data = nullptr;
    }
};

#endif