/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/05/13
 *
 * File:   PriorityQueue.cpp
 * 
 */

#include "PriorityQueue.h"

template<class T>
PriorityQueue<T>::PriorityQueue(){
    
}
template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& copyPQ){
    if(!copyPQ.order.isEmpty()){
        copyHelper(copyPQ.order);
    }
}
template<class T>
PriorityQueue<T>::~PriorityQueue(){
    
}
template<class T>
void PriorityQueue<T>::copyHelper(BinaryHeap<T> copy){
    while(!copy.isEmpty()){
        enQueue(copy.deleteElement());
    }
}
template<class T>
void PriorityQueue<T>::enQueue(T element){
    order.insertElement(element);
}
template<class T>
T PriorityQueue<T>::deQueue(){
    return order.deleteElement();
}
template<class T>
void PriorityQueue<T>::print(){
    printHelper(order);
}
template<class T>
void PriorityQueue<T>::printHelper(BinaryHeap<T> copy){
    while(!copy.isEmpty()){
        std::cout << copy.deleteElement() << " ";
    }
    std::cout << std::endl;
}
