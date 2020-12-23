#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "TreeNode.h"
// #include "Queue.h"


/*
*   The Tree class is an abstract base class meant to detail some basic
*   structural elements of other derived Trees like Binary Search Trees. 
*   AVL/Red-Black Trees will require a different node structure.
*/

template <class T>
class Tree {
private:
    static int tree_count;
    
protected:
    TreeNode<T> *root;
    TreeNode<T>* createNode(T arg);
    int ID;

public:
    // Manipulation functions;
    virtual TreeNode<T>* insert(T arg) = 0;
    virtual void remove(T arg) = 0;

    // constructor for the base class; 
    Tree() {
        ID = ++tree_count;
        root = nullptr;
    }

    virtual ~Tree() {
        root = nullptr;
        tree_count--;
    }
    
    // Utility functions;
    int size();
    bool empty();
    bool search(T key);
};

template <class T>
int Tree<T>::tree_count = 0;

template <class T>
TreeNode<T>* Tree<T>::createNode(T arg) {
    TreeNode<T> *newNode = new TreeNode<T>(arg);
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

#endif