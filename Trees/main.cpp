/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   main.cpp
 * Tests the operations of BST.h
 * Not Yet Implemented
 * 
 */

#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char** argv) {
    BST<int>bst;
    
    bst.addData(5);
    bst.addData(6);
    bst.addData(2);
    bst.addData(1);
    bst.addData(7);
    bst.traverseBFS();
    return 0;
}

