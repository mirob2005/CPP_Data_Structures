/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: --/--/--
 *
 * File:   ADTs.h
 * Only Stack Implemented
 */

/* 
 * Run this to run all implemented ADT's
 */
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"

template<class T>
void testStackCopyConstructor(Stack<T> aStack){
    std::cout << "Adding 6 to copy stack in function\n";
    aStack.push(6);
    aStack.print();
}

int main(int argc, char** argv) {
    std::cout << "****Testing Stack****" << std::endl;
    
    Stack<int> sint;
    std::cout << "Printing Empty int Stack\n";
    sint.print();
    std::cout << "Adding ints: 1,2,3,4,5\n";
    sint.push(1);
    sint.push(2);
    sint.push(3);
    sint.push(4);
    sint.push(5);
    sint.print();
    std::cout << "Pop returned: " << sint.pop() << std::endl;
    sint.print();
    testStackCopyConstructor(sint);
    std::cout << "Printing original stack after function call\n";
    sint.print();
    
    std::cout << std::endl;
    
    Stack<char> schar;
    std::cout << "Printing Empty char Stack\n";
    schar.print();
    std::cout << "Adding chars: A,B,C,D,E\n";
    schar.push('A');
    schar.push('B');
    schar.push('C');
    schar.push('D');
    schar.push('E');
    schar.print();
    char returned = schar.pop();
    std::cout << "Pop returned: " << returned << std::endl;
    schar.print();

    return 0;
}

