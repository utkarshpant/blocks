#include <iostream>
#include "..\include\BinarySearchTree.h"

int main() {
    BinarySearchTree<int> tree;
    BinarySearchTree<int> tree2;
    BinarySearchTree<int> tree3;


    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(20);

    return 0;
}