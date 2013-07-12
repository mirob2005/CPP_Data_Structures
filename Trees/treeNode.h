/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/12/13
 *
 * File:   node.h
 * Used in BST.h
 * 
 */


#ifndef TREENODE_H
#define	TREENODE_H
template<class T>
struct treeNode{
    treeNode(T dataIn, treeNode<T> *leftPtr, treeNode<T> *rightPtr, treeNode<T> *parentPtr):
    data(dataIn), left(leftPtr), right(rightPtr), parent(parentPtr) {
        
    } 
    T data;
    treeNode<T> *left;
    treeNode<T> *right;
    treeNode<T> *parent;
};


#endif	/* NODE_H */

