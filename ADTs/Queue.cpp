/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 06/30/13
 *
 * File:   Queue.cpp
 * 
 */

#include "Queue.h"
#include <iostream>
#include <stdlib.h>

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
    T next;
    while(!empty())
        next = deQueue();
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
        std::cout << "Error: The Queue is empty, cannot deQueue!\n";
        exit(1);
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
