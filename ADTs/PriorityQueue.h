/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/05/13
 *
 * File:   PriorityQueue.h
 * 
 */

#include <iostream>
#include "BinaryHeap.h"

#ifndef PRIORITYQUEUE_H
#define	PRIORITYQUEUE_H
template<class T>
class PriorityQueue
{
    public:
        PriorityQueue();
        PriorityQueue(const PriorityQueue &copyPQ);
        ~PriorityQueue();
        void enQueue(T element);
        T deQueue();
        void print();
        
    private:
        BinaryHeap<T> order;
        void copyHelper(BinaryHeap<T> copy);
        void printHelper(BinaryHeap<T> copy);
};


#endif	/* PRIORITYQUEUE_H */