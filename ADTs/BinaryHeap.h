/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/03/13
 *
 * File:   BinaryHeap.h
 * 
 */

#include <vector>

#ifndef BINARYHEAP_H
#define	BINARYHEAP_H
template<class T>
class BinaryHeap{
    public:
        BinaryHeap();
        BinaryHeap(const BinaryHeap& copyHeap);
        ~BinaryHeap();
        void traverseBFS()const;
        void print()const;
        void insertElement(T element);
        T deleteElement();
        T peek()const;
        
    private:
        std::vector<T> elements;
        void heapifyUp();
        void heapifyDown();
        void heapifyDown(int index);
        void swapElements(int index1, int index2);
        bool validIndex(int index)const;
        int getLeftIndex(int index)const;
        int getRightIndex(int index)const;
        int getParentIndex(int index)const;
        bool isEmpty()const;
};


#endif	/* BINARYHEAP_H */

