/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/17/13
 *
 * File:   charTester.cpp
 * Tests the basic operations of BST.h using chars
 * 
 */

#include <iostream>
#include "BST.h"
using namespace std;

template<class T>
void testCopyConstructor(BST<T> copyBST){
    cout << "Adding d to BST in function: \n";
    copyBST.addData('d');
    copyBST.printBranches();
}

int main(int argc, char** argv) {
    BST<char>bst;
    
    bst.addData('e');
    bst.addData('f');
    bst.addData('b');
    bst.addData('a');
    bst.addData('h');
    bst.addData('d');
    bst.addData('g');
    bst.traverseBFS();
    bst.traverseDFSpreorder();
    bst.traverseDFSinorder();
    bst.traverseDFSpostorder();
    cout << endl;
    bst.printBranches();
    cout << "Max Value: " << bst.findMax() << endl;
    cout << "Min Value: " << bst.findMin() << endl;
    cout << "Value z is present?: " << bst.findData('z') << endl;
    cout << "Value e is present?: " << bst.findData('e') << endl;
    cout << "Value f is present?: " << bst.findData('f') << endl;
    cout << "Value g is present?: " << bst.findData('g') << endl;
    
    cout << "\nCopying Tree\n";
    BST<char> copy = bst.copyTree();
    copy.printBranches();
    
    cout << "Deleting root/internal/leaf nodes from copy:\n";
    copy.deleteData('e');
    copy.deleteData('m');
    copy.deleteData('g');
    copy.deleteData('b');
    cout << "Copy after deletes:\n";
    copy.printBranches();
    cout << "Original after copy deletes:\n";
    bst.printBranches();
    
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
    bst.addData('y');
    bst.addData('b');
    bst.addData('a');
    bst.addData('c');
    bst.printBranches();
    cout << "Max Value: " << bst.findMax() << endl;
    cout << "Min Value: " << bst.findMin() << endl;
    cout << "Value a is present?: " << bst.findData('a') << endl;
    cout << "Value e is present?: " << bst.findData('e') << endl;
    cout << "Value f is present?: " << bst.findData('f') << endl;
    cout << "Value g is present?: " << bst.findData('g') << endl;
    
    cout << "\nTesting copy constructor:\n";
    testCopyConstructor(bst);
    cout << "Printing BST after function:\n";
    bst.printBranches();
    
    

    
    return 0;
}