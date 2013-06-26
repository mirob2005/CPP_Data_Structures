/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 6/26/13
 *
 * File:   Stack.cpp
 * 
 */

#include "Stack.h"
#include <iostream>
#include <stdlib.h>

template<class T>
Stack<T>::Stack() : top(NULL) {
    
}
template<class T>
Stack<T>::Stack(const Stack& copyStack){
    if(copyStack.top == NULL){
        top = NULL;
    }
    else{
        Node<T>* copyCurrent = copyStack.top;
        Node<T>* newCurrent = new Node<T>;
        
        newCurrent->value = copyCurrent->value;
        top = newCurrent;
        
        copyCurrent = copyCurrent->next;
        while(copyCurrent != NULL){
            newCurrent->next = new Node<T>;
            newCurrent = newCurrent->next;
            newCurrent->value = copyCurrent->value;
            copyCurrent = copyCurrent->next;
        }
        newCurrent->next = NULL;
    }
}
template<class T>
Stack<T>::~Stack(){
    T next;
    while(!empty())
        next = pop();
}
template<class T>
bool Stack<T>::empty() const{
    return top==NULL;
}
template<class T>
void Stack<T>::push(T element){
    Node<T>* newTop = new Node<T>;

    newTop->value = element;
    newTop->next = top;
    top = newTop;
}
template<class T>
T Stack<T>::pop(){
    if(empty()){
        std::cout << "Error: The stack is empty, cannot pop!\n";
        exit(1);
    }
    else{
        T result = top->value;
        Node<T>* tempPtr;
        tempPtr = top;
        top = top->next;
        
        delete tempPtr;
        
        return result;
    }
}
template<class T>
void Stack<T>::print() const{
    if(empty()){
        std::cout << "The stack is empty\n";
    }
    else{
        Node<T>* temp = top;
        std::cout << "TOP of stack:\n";
        while(temp!=NULL){
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
        std::cout << "BOTTOM of stack\n";
    }
}