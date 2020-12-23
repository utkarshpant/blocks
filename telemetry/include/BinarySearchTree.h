#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cstdlib>
#include "../exceptions/EmptyContainerException.h"
#include "../exceptions/DuplicateValueException.h"
#include "Tree.h"

/*
*   The BinarySearchTree class has an 'is-a' relationship with the parent Tree class.
*   It implements the specific insertion, deletion and manipulation strategies 
*   used in Binary Search Trees.
*/

template <class T>
class BinarySearchTree : public Tree<T> {    
// no private members/methods needed yet;
// private:

public:
    TreeNode<T>* insert(T arg);
    void remove(T arg);
    bool search(T arg);

    BinarySearchTree() : Tree<T>() {
        // ID = ++tree_count;
        // root = nullptr;
    }

private:
    T inOrderSuccessor(TreeNode<T>* node);
};

template <class T>
TreeNode<T>* BinarySearchTree<T>::insert(T arg) {
    if (this->root == nullptr) {
        this->root = this->createNode(arg);
        return this->root;
    } 

    TreeNode<T>* current = this->root;
    std::cout << "Root data " << current->data << std::endl;
    std::cout << "Left:\t" << current->left->data << "\tRight:\t" << current->right->data << std::endl;
    while (current != nullptr) {
        std::cout << "Entered the while section." << std::endl;
        if (arg == current->data) {
            // discovering a duplicate value;
            throw DuplicateValueException(std::to_string(arg), std::to_string(this->ID));
        } else if (arg < current->data) {
            std::cout << arg << " is less than " << current->data << std::endl;
            current = current->left;
        } else {
            std::cout << arg << " is greater than " << current->data << std::endl;
            current = current->right;
        }
    }
    current = this->createNode(arg);
    std::cout << "Inserted:\t" << current->data << std::endl << std::endl;
    return current;
}

/*
    There are 3 cases for deletion:
    1. Node has no children -> delete node;
    2. Node has only left child or right child -> store child data in temp,
        delete child and set node data to temp data
    3. Node has both children -> replace node with its in-order successor as before;
*/

template <class T>
void BinarySearchTree<T>::remove(T arg) {
    if (this->root == nullptr) {
        throw EmptyContainerException(std::to_string(this->ID));
    } else {
        TreeNode<T>* current = this->root;
        while (current->data != arg) {
            if (current == nullptr) {
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

        //the three cases must be checked now;
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
        }
        else if (current->left == nullptr) {
            T temp = (current->right)->data;
            remove(current->right->data);
            current->data = temp;
        } else if (current->right == nullptr) {
            T temp = (current->left)->data;
            remove(current->left->data);
            current->data = temp;
        }
        T data = inOrderSuccessor(current->right);
        remove(data);
        current->data = data;
    }
}

// recursive implementation to find inorder successor of a node
template <class T>
T BinarySearchTree<T>::inOrderSuccessor(TreeNode<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->data;
}

#endif