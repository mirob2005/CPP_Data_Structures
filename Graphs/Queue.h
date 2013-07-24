/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 06/30/13
 * Modified: 07/24/13
 *
 * File:   Queue.h
 * Modified for use in AdjList.cpp (added exception and included Node struct in file)
 * Used for BFS traversal.
 * Throws an EmptyQueue exception when deQueuing an empty Queue
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include <iostream>
#include <stdlib.h>

class EmptyQueue{
    
};

template<class T>
struct Node
{
    T value;
    Node *next;
};

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

template<class T>
Queue<T>::Queue() : front(NULL), back(NULL) {
    
}
template<class T>
Queue<T>::Queue(const Queue& copyQueue){
    if(copyQueue.front == NULL){
        front = NULL;
        back = NULL;
    }
    else{
        Node<T>* copyCurrent = copyQueue.front;
        Node<T>* newCurrent = new Node<T>;
        
        newCurrent->value = copyCurrent->value;
        front = newCurrent;
        
        copyCurrent = copyCurrent->next;
        while(copyCurrent != NULL){
            newCurrent->next = new Node<T>;
            newCurrent = newCurrent->next;
            newCurrent->value = copyCurrent->value;
            copyCurrent = copyCurrent->next;
        }
        back = newCurrent;
        newCurrent->next = NULL;
    }
}
template<class T>
Queue<T>::~Queue(){
    while(!empty())
        deQueue();
}
template<class T>
bool Queue<T>::empty() const{
    return front==NULL;
}
template<class T>
void Queue<T>::enQueue(T element){
    Node<T>* newBack = new Node<T>;

    newBack->value = element;
    if(!empty()){
        back->next = newBack;
        back = newBack;
    }
    else{
        front = newBack;
        back = newBack;
    }
    back->next = NULL;
}
template<class T>
T Queue<T>::deQueue(){
    if(empty()){
        throw EmptyQueue();
    }
    else{
        T result = front->value;
        Node<T>* tempPtr;
        tempPtr = front;
        front = front->next;
        
        delete tempPtr;
        
        return result;
    }
}
template<class T>
void Queue<T>::print() const{
    if(empty()){
        std::cout << "The Queue is empty\n";
    }
    else{
        Node<T>* temp = front;
        std::cout << "FRONT of Queue< ";
        while(temp!=NULL){
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "> END of Queue\n";
    }
}

#endif	/* QUEUE_H */

