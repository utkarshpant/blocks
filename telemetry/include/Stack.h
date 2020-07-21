#ifndef STACK_H
#define STACK_H

#include "..\exceptions\StackUnderflowException.h"
#include "List.h"


template <class T>
class Stack {
private:
    static int stack_count;
    int ID;
    int count;
    List<T> stack;

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
    }
};

template <class T>
int Stack<T>::stack_count = 0;

// Push arg into the stack;
template <class T>
void Stack<T>::push(T arg) {
    stack.push(arg);
    // top = stack.get_head();
}

template <class T>
T Stack<T>::pop() {
    if (stack.empty()) {
        throw StackUnderflowException(std::to_string(ID));
    } else {
        // std::cout << "CAME HERE\t" << std::endl;
        return stack.pop();
        // top = stack.get_head();
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
    return (stack.get_head())->data;
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