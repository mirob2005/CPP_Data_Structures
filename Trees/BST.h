/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   BST.h
 * Not Yet Implemented
 * 
 */
#include "node.h"

#ifndef BST_H
#define	BST_H

template<class T>
class BST{
    public:
        BST();
        ~BST();
        BST(const BST &copyBST);
        void addData(T data);
        void deleteData(T data);
        bool findData(T data);
        T findMin();
        T findMax();
        void traverseBFS();
        void traverseDFSpreorder();
        void traverseDFSinorder();
        void traverseDFSpostorder();
        void printBranches();
        void deleteTree();
        BST copyTree();
    private:
        Node<T> *root;
};
template<class T>
BST<T>::BST(): root(NULL){
    
}
template<class T>
BST<T>::~BST(){
    deleteTree();
}
template<class T>
BST<T>::BST(const BST& copyBST){
    
}
template<class T>
void BST<T>::addData(T data){
    
}
template<class T>
void BST<T>::deleteData(T data){
    
}
template<class T>
bool BST<T>::findData(T data){
    
}
template<class T>
T BST<T>::findMin(){
    
}
template<class T>
T BST<T>::findMax(){
    
}
template<class T>
void BST<T>::traverseBFS(){
    
}
template<class T>
void BST<T>::traverseDFSpreorder(){
    
}
template<class T>
void BST<T>::traverseDFSinorder(){
    
}
template<class T>
void BST<T>::traverseDFSpostorder(){
    
}
template<class T>
void BST<T>::printBranches(){
    
}
template<class T>
void BST<T>::deleteTree(){
    
}
template<class T>
BST<T> BST<T>::copyTree(){
    
}
#endif	/* BST_H */

