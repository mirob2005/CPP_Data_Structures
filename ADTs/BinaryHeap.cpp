/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/03/13
 *
 * File:   BinaryHeap.cpp
 * 
 */

#include "BinaryHeap.h"
#include <iostream>
#include <cmath>

template<class T>
BinaryHeap<T>::BinaryHeap(){
    
}
template<class T>
BinaryHeap<T>::BinaryHeap(const BinaryHeap& copyHeap){
    if(copyHeap.isEmpty()){
        BinaryHeap();
    }
    else{
        for(class std::vector<T>::const_iterator p = copyHeap.elements.begin(); p!= copyHeap.elements.end(); ++p){
            elements.push_back(*p);
        }
    }
}
template<class T>
BinaryHeap<T>::~BinaryHeap(){
    elements.clear();
}
template<class T>
void BinaryHeap<T>::insertElement(T element){
    elements.push_back(element);
    heapifyUp();
}
template<class T>
T BinaryHeap<T>::deleteElement(){
    if(isEmpty()){
        std::cout << "EMPTY!\n";
        return NULL;
    }
    T returnMe = elements.front();
    elements.front() = elements.back();
    elements.pop_back();
    if(!isEmpty())
        heapifyDown(0);
    return returnMe;
}
template<class T>
void BinaryHeap<T>::heapifyUp(){
    int currentIndex = elements.size()-1;
    while(currentIndex != 0){
        if(elements[currentIndex] > elements[getParentIndex(currentIndex)]){
            swapElements(currentIndex,getParentIndex(currentIndex));
            currentIndex = getParentIndex(currentIndex);
        }
        else
            break;
    }
}
template<class T>
void BinaryHeap<T>::heapifyDown(int index){
    int lChild = getLeftIndex(index);
    int rChild = getRightIndex(index);
    int compareIndex;
    if(validIndex(lChild) && validIndex(rChild)){
        compareIndex = (elements[rChild]>elements[lChild]?rChild:lChild);
    }
    else if(validIndex(lChild)){
        compareIndex = lChild;
    }
    else if(validIndex(rChild)){
        compareIndex = rChild;
    }
    else{
        return;
    }
    if(elements[compareIndex] > elements[index]){
        swapElements(compareIndex,index);
        heapifyDown(compareIndex);
    }
}
template<class T>
void BinaryHeap<T>::swapElements(int index1, int index2){
    T temp = elements[index1];
    elements[index1] = elements[index2];
    elements[index2] = temp;
}
template<class T>
T BinaryHeap<T>::peek()const{
    if(isEmpty()){
        std::cout << "EMPTY!\n";
        return NULL;
    }
    else{
        return elements.front();
    }
}
template<class T>
void BinaryHeap<T>::print()const{
    std::cout << "Elements:\n";
    for(int index = 0; index < elements.size(); index++){
        std::cout << elements[index];
        std::cout << " Parent: ";
        if(validIndex(getParentIndex(index)))
            std::cout<< elements[getParentIndex(index)];
        else
            std::cout << "NULL";
        std::cout << "\n\tLeft Child: ";
        if(validIndex(getLeftIndex(index)))
            std::cout << elements[getLeftIndex(index)];
        else
            std::cout << "NULL";
        std::cout << "\n\tRight Child: ";
        if(validIndex(getRightIndex(index)))
            std::cout << elements[getRightIndex(index)];
        else
            std::cout << "NULL";
        std::cout << std::endl;
    }
}
template<class T>
void BinaryHeap<T>::traverseBFS()const{
    std::cout << "Array = < ";
    for(class std::vector<T>::const_iterator p = elements.begin(); p!= elements.end(); ++p){
        std::cout << *p << " ";
    }
    std::cout << ">\n";
}
template<class T>
bool BinaryHeap<T>::isEmpty()const{
    return elements.empty();
}
template<class T>
int BinaryHeap<T>::getLeftIndex(int index)const{
    return (index*2 + 1);
}
template<class T>
int BinaryHeap<T>::getRightIndex(int index)const{
    return (index*2 + 2);
}
template<class T>
int BinaryHeap<T>::getParentIndex(int index)const{
    return index>0?static_cast<int>(floor((index-1)/2)):-1;
}
template<class T>
bool BinaryHeap<T>::validIndex(int index)const{
    return  index < elements.size() && index >=0;
}