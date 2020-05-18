#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.h"
#include "EmptyListException.h"
#include "OutOfBoundsException.h"

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
    void deleteAtPosition(int pos);

    // traverse functions;
    void printList(std::string sep = "\n", std::string end_sep = "\n");
    void printListReverse(std::string sep = "\n", std::string end_sep = "\n");
    
    // Utility functions;
    int getSize();
    bool isEmpty();
    void sort();
    void search(int key);

    List() {
        ID = ++listCount;
        count = -1;
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
    count++;
}

void List::deleteAtPosition(int arg) {
    /*  The argument supplied is the exact position deleted, indexed from 0.
    For example, in 0 -> 1 -> 2 -> 3 -> 4 -> 5, arg == 3 will result in: 0 -> 1 -> 2-> 4 -> 5
    */
    if (arg > getSize()) {
        throw OutOfBoundsException(arg);
    } else {
        // Relative pointers;
        Node *current = head;
        Node *prevNode = current->prev;
        Node *nextNode = current->next;
            
        // edge case: position = (list size) - 1, i.e. tail node;
        if (arg == getSize()) {
            throw OutOfBoundsException(arg);
        }
        else if (arg == getSize() - 1) {
            current = tail;
            Node *prevNode = current->prev;
            prevNode->next = NULL;
        } else {
            int counter = 0;
            while (counter != arg) {
                current = current->next;
                counter++;
            }        
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }        


    }
}

void List::printList(std::string sep, std::string end_sep) {
    Node *current = head;
    if (isEmpty()) {
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
    if (isEmpty()) {
        throw EmptyListException(std::to_string(ID));
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
    if (isEmpty()) {
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
    return count + 1;
}

bool List::isEmpty() {
    if (head ==  NULL) {
        return true;  
    } else {
        return false;
    }
}

void List::sort() {
    // implementing insertion sort;
    if (isEmpty()) {
        throw EmptyListException(std::to_string(ID));
    } else {
        Node *iPtr = head;
        Node *current = head;

        while (current != NULL) {
            iPtr = head;
            while (iPtr != current) {
                if (iPtr->data > current->data) {
                    int temp = current->data;
                    current->data = iPtr->data;
                    iPtr->data = temp;
                }
                iPtr = iPtr->next;
            }
            current = current->next;
        }
    }
}

#endif