#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.h"
#include "EmptyListException.h"
#include "OutOfBoundsException.h"

template <class T>
class List {
private:
    static int listCount;
    int ID;
    int count;
    Node<T>  *head;
    Node<T> *tail;
    // Node* createNode();
    Node<T>* createNode(T arg);

public:
    // Manipulation functions;
    void pushBack(T arg);
    void pushFront(T arg);
    T pop();
    T popBack();
    void deleteAtPosition(int pos);

    // traverse functions;
    void printList(std::string sep = "\n", std::string end_sep = "\n");
    void printListReverse(std::string sep = "\n", std::string end_sep = "\n");
    
    // Utility functions;
    int getSize();
    bool isEmpty();
    void sort();
    void search(T key);
    template<typename Predicate>
    void remove_if(Predicate pred);

    List() {
        ID = ++listCount;
        count = -1;
        head = NULL;
        tail = NULL;
    }
};

template <class T>
int List<T>::listCount = 0;

// Defitions of member functions of the Node struct;
template <class T>
Node<T>* List<T>::createNode(T arg) {
    Node<T>* newNode = new Node<T>(arg);
    return newNode;
}

// Definitions of member functions of the List class;
template <class T>
void List<T>::pushFront(T arg) {
    Node<T>* tempNode = createNode(arg);
    
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

template <class T>
void List<T>::pushBack(T arg) {
    Node<T>* tempNode = createNode(arg);
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

template <class T>
void List<T>::deleteAtPosition(int arg) {
    /*  The argument supplied is the exact position deleted, indexed from 0.
    For example, in 0 -> 1 -> 2 -> 3 -> 4 -> 5, arg == 3 will result in: 0 -> 1 -> 2-> 4 -> 5
    */
    if (arg > getSize()) {
        throw OutOfBoundsException(arg);
    } else {
        // Relative pointers;
        Node<T>* current = head;
        Node<T>* prevNode = current->prev;
        Node<T>* nextNode = current->next;
            
        // edge case: position = (list size) - 1, i.e. tail node;
        if (arg == getSize()) {
            throw OutOfBoundsException(arg);
        }
        else if (arg == getSize() - 1) {
            current = tail;
            prevNode = current->prev;
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

template <class T>
void List<T>::printList(std::string sep, std::string end_sep) {
    Node<T>* current = head;
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

template <class T>
void List<T>::printListReverse(std::string sep, std::string end_sep) {
    Node<T>* current = tail;
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

template <class T>
T List<T>::pop() {
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

template <class T>
T List<T>::popBack() {
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

template <class T>
int List<T>::getSize() {
    return count + 1;
}

template <class T>
bool List<T>::isEmpty() {
    if (head ==  NULL) {
        return true;  
    } else {
        return false;
    }
}

template <class T>
void List<T>::sort() {
    // implementing insertion sort;
    if (isEmpty()) {
        throw EmptyListException(std::to_string(ID));
    } else {
        Node<T> *iPtr = head;
        Node<T>* current = head;

        while (current != NULL) {
            iPtr = head;
            while (iPtr != current) {
                if (iPtr->data > current->data) {
                    T temp = current->data;
                    current->data = iPtr->data;
                    iPtr->data = temp;
                }
                iPtr = iPtr->next;
            }
            current = current->next;
        }
    }
}

template <class T>
template <typename Predicate>
void List<T>::remove_if(Predicate pred) {
        Node<T>* current = head;
        while (current != tail) {
            if(pred(current->data) == true) {
                // std::cout <<"Pred output on " << current->data << " = " << pred(current->data);
                Node<T>* prevNode;
                Node<T>* nextNode;
                if (current == head) {
                    head = head->next;
                    count--;
                } else if(current == tail) {
                    tail = tail->prev;
                    count--;
                } else {
                    prevNode = current->prev;
                    nextNode = current->next;
                    prevNode->next = nextNode;
                    count--;
                }
            }
            current = current->next;
        }
    }

#endif