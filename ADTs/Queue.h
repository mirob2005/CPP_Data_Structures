/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 06/30/13
 *
 * File:   Queue.h
 * Not Yet Implemented
 */

#include "Node.h"

#ifndef QUEUE_H
#define	QUEUE_H
template<class T>
class Queue
{
    public:
        Queue();
        Queue(const Queue& copyQueue);
        ~Queue();
        void enQueue(T element);
        T deQueue();
        bool empty() const;
        void print() const;
    private:
        Node<T>* front;
        Node<T>* back;
};

#endif	/* QUEUE_H */

