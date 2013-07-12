/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   BST.h
 * Not Yet Implemented
 * 
 */
#include "treeNode.h"
#include "Queue.h"

#ifndef BST_H
#define	BST_H

template<class T>
class BST{
    public:
        BST();
        ~BST();
        BST(const BST<T> &copyBST);
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
        BST<T> copyTree();
    private:
        treeNode<T> *root;
        void addRec(T data, treeNode<T> *curRoot, treeNode<T> *parent);
};
template<class T>
BST<T>::BST(): root(NULL){
    
}
template<class T>
BST<T>::~BST(){
    deleteTree();
}
template<class T>
BST<T>::BST(const BST<T> &copyBST){
    
}
template<class T>
void BST<T>::addData(T data){
    if(root==NULL){
        root = new treeNode<T>(data, NULL, NULL, NULL);
    }
    else{
        addRec(data, root, NULL);
    }
}
template<class T>
void BST<T>::addRec(T data, treeNode<T> *curRoot, treeNode<T> *parent){
    if(data > curRoot->data){
        if(curRoot->right!=NULL){
            addRec(data,curRoot->right, curRoot);
        }
        else{
            curRoot->right = new treeNode<T>(data, NULL, NULL, curRoot);
        }
    }
    else if(data < curRoot->data){
        if(curRoot->left!=NULL){
            addRec(data,curRoot->left, curRoot);
        }
        else{
            curRoot->left = new treeNode<T>(data, NULL, NULL, curRoot);
        }
    }
    else{
        std::cout << "Data " << data << " already exists in BST!\n";
    }
    
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
    Queue< treeNode<T>* > q;
    q.enQueue(root);
    treeNode<T> *curNode = q.deQueue();
    while(curNode!=NULL){
        std::cout << curNode->data << " ";
        if(curNode->left!=NULL)
            q.enQueue(curNode->left);
        if(curNode->right!=NULL)
            q.enQueue(curNode->right);
        try{
            curNode = q.deQueue();
        }
        catch(EmptyQueue e){
            break;
        }
    }
    std::cout << std::endl;
    
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

