#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "EmptyListException.h"

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

class List {
private:
    static int listCount;
    int ID;
    int count;
    Node *head;
    Node *tail;
    // Node* createNode();
    Node* createNode(int arg = 0);

public:
    // Manipulation functions;
    void pushBack(int arg = 0);
    void pushFront(int arg = 0);
    int pop();
    int popBack();

    // traverse functions;
    void printList(std::string sep = "\n", std::string end_sep = "\n");
    void printListReverse(std::string sep = "\n", std::string end_sep = "\n");
    
    // Utility functions;
    int getSize();
    bool isEmpty();

    List() {
        ID = ++listCount;
        head = NULL;
        tail = NULL;
    }
};

int List::listCount = 0;

// Defitions of member functions of the Node struct;

Node* List::createNode(int arg) {
    Node *newNode = new Node(arg);
    return newNode;
}

// Definitions of member functions of the List class;

void List::pushFront(int arg) {
    Node *tempNode = createNode(arg);
    
    if (head == NULL) {
        // Changing head target;
        head = tempNode;

        // Setting linkages;
        tempNode->next = NULL;
        tempNode->prev = NULL;
        tail = tempNode;
    } else {
        tempNode->next = head;
        head->prev = tempNode;
        head = tempNode;
    }
    // std::cout << "Incrementing count on call to create node with data " << arg << "." << std::endl;
    count++;

}

void List::pushBack(int arg) {
    Node *tempNode = createNode(arg);
    if (head == NULL) {
        // Changing head target;
        head = tempNode;

        // Setting linkages;
        tempNode->next = NULL;
        tempNode->prev = NULL;
        tail = tempNode;
    } else {
        //  Use tail directly;
        tail->next = tempNode;
        tempNode->prev = tail;
        tail = tempNode;
    }
    // std::cout << "Incrementing count on call to create node with data " << arg << "." << std::endl;
    count++;
}

void List::printList(std::string sep, std::string end_sep) {
    Node *current = head;
    if (current == NULL) {
        throw EmptyListException(std::to_string(ID));
    } else {
        do {
                if (current->next == NULL) {
                    // last element;
                    std::cout << current->data << end_sep;
                    break;
                } else {
                    std::cout << current->data << sep;
                    current = current->next;
                }
            }
        while (current != NULL);
    }
    
}

void List::printListReverse(std::string sep, std::string end_sep) {
    Node *current = tail;
    if (current == NULL) {
        throw EmptyListException(std::to_string(ID));
    } else {
        do {
            if (current->prev == NULL) {
                // last element;
                std::cout << current->data << end_sep;
                break;
            } else {
                std::cout << current->data << sep;
                current = current->prev;
            }
        } 
        while (current != NULL);
    }
}

int List::pop() {
    int result;
    if (head == NULL) {
        // std::cout << "EMPTY LIST!" << "\n";
        // throw EmptyListException(std::to_string(ID));
        std::cout << "EMPTY LIST!\n"; 
    } else {
        result =  head->data;
        head = head->next;
        head->prev = NULL;
        count--;
    }
    return result;
}

int List::popBack() {
    int result;
    if (tail == NULL) {
        throw EmptyListException(std::to_string(ID));
    } else {
        result = tail->data;
        tail = tail->prev;
        tail->next = NULL;
        count--;    
    }
    return result;
}

int List::getSize() {
    return count;
}

bool List::isEmpty() {
    if (head ==  NULL) {
        return true;  
    } else {
        return false;
    }
}

#endif