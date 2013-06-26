/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 6/26/13
 *
 * File:   Stack.h
 * 
 */
#include "Node.h"

#ifndef STACK_H
#define	STACK_H
template<class T>
class Stack
{
    public:
        Stack();
        Stack(const Stack& copystack);
        ~Stack();
        void push(T element);
        T pop();
        bool empty() const;
        void print() const;
    private:
        Node<T>* top;
};


#endif	/* STACK_H */

