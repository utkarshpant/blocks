#ifndef QUEUE_H
#define QUEUE_H

/*
    This header file defines:
    1. Queues
    2. Priority Queues

    along with their standard behaviors and operations. Queues can be
    implemented using Lists, but Priority Queues function differently
    and do not exhibit FIFO behaviour entirely. They are implemented
    using Arrays, along with a follow up when we implement Trees.
*/

#include "List.h"

template <class T>
class Queue {
private:
    static int queue_count;
    int ID;
    List<T> queue;

public:
    // utility functions;
    void push(T arg);
    T pop();
    T front();
    T back();
    int size();
    bool empty();
    static int get_queue_count();
    std::string get_ID();

    //constructors;
    Queue() {
        ID = ++queue_count;
    }
};


template <class T>
int Queue<T>::queue_count = 0;

// push arg into the queue from the rear;
template <class T>
void Queue<T>::push(T arg) {
    queue.push_back(arg);
}

// pop arg from the queue from the front;
template <class T>
T Queue<T>::pop() {
    if (queue.empty()) {
        //throw Exception
        throw EmptyContainerException(std::to_string(ID));
    } else {
        return queue.pop();
    }
}

// accesses the first element in the queue but does not remove it;
template <class T>
T Queue<T>::front() {
    if (queue.empty()) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        return (queue.get_head())->data;
    }
}

// access the last element in the queue but does not remove it;
template <class T>
T Queue<T>::back() {
    if (queue.empty()) {
        throw EmptyContainerException(std::to_string(ID));
    } else {
        return (queue.get_tail())->data;
    }
}

template <class T>
int Queue<T>::size() {
    return queue.size();
}

template <class T>
bool Queue<T>::empty() {
    if (queue.empty()) {
        return true;
    } else {
        return false;
    }
}

template <class T>
int Queue<T>::get_queue_count() {
    return queue_count;
}

template <class T>
std::string Queue<T>::get_ID() {
    return std::to_string(ID);
}

#endif