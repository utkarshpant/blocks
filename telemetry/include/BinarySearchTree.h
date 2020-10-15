#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cstdlib>
#include "Tree.h"
#include "../exceptions/EmptyContainerException.h"

/*
*   The BinarySearchTree class has an 'is-a' relationship with the parent Tree class.
*   It implements the specific insertion, deletion and manipulation strategies 
*   used in Binary Search Trees.
*/

template <class T>
class BinarySearchTree : public Tree {    
// no private members/methods needed yet;
// private:

public:
    TreeNode<T>* insert(T arg);
    void remove(T arg);
    bool search(T arg);

    BinarySearchTree() {
        ID = ++tree_count;
        root = NULL;
    }
};

template <class T>
TreeNode<T>* BinarySearchTree<T>::insert(T arg) {
    TreeNode<T>* current = root;
    while (current != NULL) {
        if (arg == current->data) {
            // discovering a duplicate value;
            throw DuplicateValueException(std::to_string(arg), std::to_string(ID));
        } else if (arg < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    current = createNode(arg);
    return current;
}

template <class T>
void BinarySearchTree<T>::remove(T arg) {
    if (root == NULL) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        TreeNode<T>* current = root;
        while (current->data != arg) {
            if (current == NULL) {
                // a leaf node was reached, no match found;
                // throw an InvalidKeyException (?)
                std::cout << "There is no key that matches." << std::endl;
                break;
            } else if (arg < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        /*  Now we are at the node containing the data, 
        *   which must be replaced by its inorder successor,
        *   following which the inorder successor must be deleted from
        *   its original position;
        */
    }
}

#endif