/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   node.h
 * Used in BST.h
 * Not Yet Implemented
 * 
 */


#ifndef NODE_H
#define	NODE_H
template<class T>
struct Node{
    T data;
    Node *left;
    Node *right;
    Node *parent;
};


#endif	/* NODE_H */

