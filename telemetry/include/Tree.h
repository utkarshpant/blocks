#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "TreeNode.h"
#include "Queue.h"


/*
*   The Tree class is an abstract base class meant to detail some basic
*   structural elements of other derived Trees like AVL or Red/Black Trees. 
*/

template <class T>
class Tree {
private:
    static int tree_count;
    int ID;
    
protected:
    TreeNode<T> *root;
    TreeNode<T>* createNode(T arg);

public:
    // Manipulation functions;
    void insert(T arg) = 0;
    T remove() = 0;

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
    TreeNode *newNode = new TreeNode<T>(arg);
    return newNode;
}

#endif