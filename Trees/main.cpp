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

template<class T>
void testCopyConstructor(BST<T> copyBST){
    cout << "Adding 3 to BST in function: \n";
    copyBST.addData(3);
    copyBST.printBranches();
}

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
    
    cout << "\nCopying Tree\n";
    BST<int> copy = bst.copyTree();
    copy.printBranches();
    
    cout << "\nDeleting original Tree:\n";
    bst.deleteTree();
    cout << "\nPrinting deleted tree:\n";
    bst.traverseBFS();
    bst.traverseDFSpreorder();
    bst.traverseDFSinorder();
    bst.traverseDFSpostorder();
    bst.printBranches();
    cout << "\nPrinting copied tree:\n";
    copy.printBranches();
    
    cout <<"\nAdding new nodes: \n";
    bst.addData(11);
    bst.addData(1);
    bst.addData(2);
    bst.addData(0);
    bst.printBranches();
    cout << "Max Value: " << bst.findMax() << endl;
    cout << "Min Value: " << bst.findMin() << endl;
    cout << "Value 0 is present?: " << bst.findData(0) << endl;
    cout << "Value 5 is present?: " << bst.findData(5) << endl;
    cout << "Value 6 is present?: " << bst.findData(6) << endl;
    cout << "Value 7 is present?: " << bst.findData(7) << endl;
    
    cout << "\nTesting copy constructor:\n";
    testCopyConstructor(bst);
    cout << "Printing BST after function:\n";
    bst.printBranches();
    
    return 0;
}

