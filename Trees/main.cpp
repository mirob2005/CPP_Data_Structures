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
    bst.addData(8);
    bst.addData(4);
    bst.addData(7);
    bst.traverseBFS();
    bst.traverseDFSpreorder();
    bst.traverseDFSinorder();
    bst.traverseDFSpostorder();
    cout << endl;
    bst.printBranches();
    cout << "Max Value: " << bst.findMax() << endl;
    cout << "Min Value: " << bst.findMin() << endl;
    cout << "Value 0 is present?: " << bst.findData(0) << endl;
    cout << "Value 5 is present?: " << bst.findData(5) << endl;
    cout << "Value 6 is present?: " << bst.findData(6) << endl;
    cout << "Value 7 is present?: " << bst.findData(7) << endl;
    return 0;
}

