/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: --/--/--
 *
 * File:   ADTs.h
 * Only Stack and Queue Implemented
 */

/* 
 * Run this to run all implemented ADT's
 */
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"

template<class T>
void testStackCopyConstructor(Stack<T> aStack){
    std::cout << "Adding 6 to copy stack in function\n";
    aStack.push(6);
    aStack.print();
}
void testStack(){
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
}
template<class T>
void testQueueCopyConstructor(Queue<T> aQueue){
    std::cout << "Adding 6 to copy queue in function\n";
    aQueue.enQueue(6);
    aQueue.print();
}
void testQueue(){
    std::cout << "\n****Testing Queue****" << std::endl;
    
    Queue<int> qint;
    std::cout << "Printing Empty int Queue\n";
    qint.print();
    std::cout << "Adding ints: 1,2,3,4,5\n";
    qint.enQueue(1);
    qint.enQueue(2);
    qint.enQueue(3);
    qint.enQueue(4);
    qint.enQueue(5);
    qint.print();
    std::cout << "DeQueue returned: " << qint.deQueue() << std::endl;
    qint.print();
    testQueueCopyConstructor(qint);
    std::cout << "Printing original queue after function call\n";
    qint.print();
    
    std::cout << std::endl;
    
    Queue<char> qchar;
    std::cout << "Printing Empty char Queue\n";
    qchar.print();
    std::cout << "Adding chars: A,B,C,D,E\n";
    qchar.enQueue('A');
    qchar.enQueue('B');
    qchar.enQueue('C');
    qchar.enQueue('D');
    qchar.enQueue('E');
    qchar.print();
    char returned = qchar.deQueue();
    std::cout << "DeQueue returned: " << returned << std::endl;
    qchar.print();
}
int main(int argc, char** argv) {
	testStack();
	testQueue();

    return 0;
}

