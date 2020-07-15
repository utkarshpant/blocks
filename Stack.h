#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "StackUnderflowException.h"

template <class T>
class Stack {
private:
    static int stack_count;
    int ID;
    int count;
    List<T> stack;
    Node<T> *top;

public:
    // utility functions;
    void push(T arg);
    T pop();
    T peek();
    int size();
    bool empty();
    static int get_stack_count();
    std::string get_ID();

    // constructors;
    Stack() {
        // // call the underlying container's constructor;
        // stack();
        // increment the count of currently in-use stacks;
        ID = ++stack_count;
        // counter of nodes (always size - 1)
        count = -1;
        // bind pointer for this list adapter to underlying container;
        top = stack.get_head();
    }
};

template <class T>
int Stack<T>::stack_count = 0;

template <class T>
void Stack<T>::push(T arg) {
    stack.push(arg);
}

template <class T>
T Stack<T>::pop() {
    if (stack.empty()) {
        throw StackUnderflowException(std::to_string(ID));
    } else {
        // std::cout << "CAME HERE\t" << std::endl;
        return stack.pop();
    }
}

template <class T>
int Stack<T>::get_stack_count() {
    return stack_count;
}

template <class T>
std::string Stack<T>::get_ID() {
    return std::to_string(ID);
}

template <class T>
T Stack<T>::peek() {
    return top->data;
}

template <class T>
int Stack<T>::size() {
    return count + 1;
}

template <class T>
bool Stack<T>::empty() {
    if(stack.empty()) {
        return true;
    } else {
        return false;
    }
}

#endif