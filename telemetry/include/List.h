#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.h"
#include "../exceptions/EmptyContainerException.h"
#include "../exceptions/OutOfBoundsException.h"

template <class T>
class List {
private:
    static int list_count;
    int ID;
    int node_count;
    Node<T> *head;
    Node<T> *tail;
    Node<T>* createNode(T arg);

public:
    // Manipulation functions;
    void push_back(T arg);
    void push(T arg);
    T pop();
    T pop_back();
    void erase(int pos);

    // traverse functions;
    void print_list(const std::string &sep = "\n", const std::string &end_sep = "\n");
    void print_list_reverse(const std::string &sep = "\n", const std::string &end_sep = "\n");
    
    // Utility functions;
    Node<T>* get_head();
    Node<T>* get_tail();
    int size();
    bool empty();
    void sort();
    bool contains(T key);
    template<typename Predicate>
    void remove_if(Predicate pred);

    // Constructors and Destructors;
    List() {
        ID = ++list_count;
        node_count = -1;
        head = nullptr;
        tail = nullptr;
    }

    virtual ~List() {
        while(!empty()) {
            pop();
        }
        list_count--;
    }
};

template <class T>
int List<T>::list_count = 0;

// Definitions of member functions of the List class;
template <class T>
Node<T>* List<T>::createNode(T arg) {
    Node<T>* newNode = new Node<T>(arg);
    return newNode;
}

template <class T>
void List<T>::push(T arg) {
    Node<T>* tempNode = createNode(arg);
    
    if (head == nullptr) {
        // Changing head target;
        head = tempNode;

        // Setting linkages;
        tempNode->next = nullptr;
        tempNode->prev = nullptr;
        tail = tempNode;
    } else {
        tempNode->next = head;
        head->prev = tempNode;
        head = tempNode;
    }
    node_count++;
}

template <class T>
void List<T>::push_back(T arg) {
    Node<T>* tempNode = createNode(arg);
    if (head == nullptr) {
        // Changing head target;
        head = tempNode;

        // Setting linkages;
        tempNode->next = nullptr;
        tempNode->prev = nullptr;
        tail = tempNode;
    } else {
        //  Use tail directly;
        tail->next = tempNode;
        tempNode->prev = tail;
        tail = tempNode;
    }
    node_count++;
}

template <class T>
T List<T>::pop() {
    int result;
    if (empty()) {
        throw EmptyContainerException(std::to_string(ID));
    } else if(head->next == nullptr) {
        // only head node remains;
        result = head->data;
        delete head;
        head = nullptr;
        // node_count--;
    } else {
        result =  head->data;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }   
    node_count--;
    return result;
}

template <class T>
T List<T>::pop_back() {
    int result;
    if (empty()) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        result = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        node_count--;    
    }
    return result;
}

template <class T>
bool List<T>::contains(T key) {
    Node<T>* current = head;
    if(current==nullptr) {
        throw EmptyContainerException(std::to_string(ID));
    }
    while(current!=nullptr) {
        if(current->data==key) { 
            return true;
        }
        current=current->next;
    }
    return false;
}


template <class T>
void List<T>::erase(int arg) {
    /*  The argument supplied is the exact position deleted, indexed from 0.
    For example, in 0 -> 1 -> 2 -> 3 -> 4 -> 5, arg == 3 will result in: 0 -> 1 -> 2-> 4 -> 5
    */
    if (arg > size()) {
        throw OutOfBoundsException(arg);
    } else {
        // Relative pointers;
        Node<T>* current = head;
        Node<T>* prevNode = current->prev;
        Node<T>* nextNode = current->next;
            
        // edge case: position = (list size) - 1, i.e. tail node;
        if (arg == size()) {
            throw OutOfBoundsException(arg);
        }
        else if (arg == size() - 1) {
            current = tail;
            prevNode = current->prev;
            prevNode->next = nullptr;
        } else {
            int counter = 0;
            while (counter != arg) {
                current = current->next;
                counter++;
            }        
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }        
        node_count--;
    }
}

template <class T>
void List<T>::print_list(const std::string &sep, const std::string &end_sep) {
    Node<T>* current = head;
    if (empty()) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        do {
            if (current->next == nullptr) {
                // last element;
                std::cout << current->data << end_sep;
                break;
            } else {
                std::cout << current->data << sep;
                current = current->next;
            }
        }
        while (current != nullptr);
    }
    
}

template <class T>
void List<T>::print_list_reverse(const std::string &sep, const std::string &end_sep) {
    Node<T>* current = tail;
    if (current == nullptr) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        do {
            if (current->prev == nullptr) {
                // last element;
                std::cout << current->data << end_sep;
                break;
            } else {
                std::cout << current->data << sep;
                current = current->prev;
            }
        } 
        while (current != nullptr);
    }
}

template <class T>
int List<T>::size() {
    return node_count + 1;
}

template <class T>
bool List<T>::empty() {
    if (head ==  nullptr) {
        return true;  
    } else {
        return false;
    }
}

template <class T>
void List<T>::sort() {
    // implementing insertion sort;
    if (empty()) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        Node<T> *iPtr = head;
        Node<T>* current = head;

        while (current != nullptr) {
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
                node_count--;
            } else if(current == tail) {
                tail = tail->prev;
                node_count--;
            } else {
                prevNode = current->prev;
                nextNode = current->next;
                prevNode->next = nextNode;
                node_count--;
            }
        }
        current = current->next;
    }
}

template <class T>
Node<T>* List<T>::get_head() {
    return head;
}

template <class T>
Node<T>* List<T>::get_tail() {
    return tail;
}


#endif
