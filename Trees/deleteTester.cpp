/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/17/13
 *
 * File:   deleteTester.cpp
 * Tests the different delete operations of BST.h (leaf,internal,root nodes,etc.)
 * 
 */

#include <iostream>
#include "BST.h"
using namespace std;

template<class T>
void testNoLeftDelete(BST<T> copyBST){
    cout << "\nTesting delete of internal node with only 1 child(right):\n";
    copyBST.deleteData(2);
    copyBST.traverseBFS();
}
template<class T>
void testNoRightDelete(BST<T> copyBST){
    cout << "\nTesting delete of internal node with only 1 child(left):\n";
    copyBST.deleteData(18);
    copyBST.traverseBFS();
}
template<class T>
void testLeafDelete(BST<T> copyBST){
    cout << "\nTesting delete of leaf node:\n";
    copyBST.deleteData(8);
    copyBST.traverseBFS();
}
template<class T>
void testPredNoChildDelete(BST<T> copyBST){
    cout << "\nTesting delete of internal node with 2 children and \n\tInorder Predescessor has no child:\n";
    copyBST.deleteData(7);
    copyBST.traverseBFS();
}
template<class T>
void testPredChildParentDelete(BST<T> copyBST){
    cout << "\nTesting delete of internal node with 2 children and \n\tInorder Predescessor has a child and is child of the node to be deleted:\n";
    copyBST.deleteData(13);
    copyBST.traverseBFS();
}
template<class T>
void testPredChildNoParentDelete(BST<T> copyBST){
    cout << "\nTesting delete of internal node with 2 children and \n\tInorder Predescessor has a child and is not the child of the node to be deleted:\n";
    copyBST.deleteData(16);
    copyBST.traverseBFS();
}
template<class T>
void testPredChildNoParentRootDelete(BST<T> copyBST){
    cout << "\nTesting delete of ROOT node with 2 children and \n\tInorder Predescessor has a child and is not the child of ROOT:\n";
    copyBST.deleteData(10);
    copyBST.traverseBFS();
}
void testRootDeletes(){
    BST<int> t;
    t.addData(10);
    cout << "**********\n";
    t.traverseBFS();
    cout << "Testing root delete with no children:\n";
    t.deleteData(10);
    t.traverseBFS();
    t.addData(10);
    t.addData(7);
    cout << "**********\n";
    t.traverseBFS();
    cout << "Testing root delete with left child:\n";
    t.deleteData(10);
    t.traverseBFS();
    t.deleteTree();
    t.addData(10);
    t.addData(12);
    cout << "**********\n";
    t.traverseBFS();
    cout << "Testing root delete with right child:\n";
    t.deleteData(10);
    t.traverseBFS();
    t.deleteTree();
    t.addData(10);
    t.addData(7);
    t.addData(12);
    t.addData(9);
    cout << "**********\n";
    t.traverseBFS();
    cout << "Testing root delete with 2 children, Inorder Predescessor has no child:\n";
    t.deleteData(10);
    t.traverseBFS();
    t.deleteTree();
    t.addData(10);
    t.addData(9);
    t.addData(12);
    t.addData(7);
    cout << "**********\n";
    t.traverseBFS();
    cout << "Testing root delete with 2 children, Inorder Predescessor has child and is child of root:\n";
    t.deleteData(10);
    t.traverseBFS();
}

int main(int argc, char** argv) {
    BST<int> fullTree;
    int size = 16;
    int array[] = {10,5,16,2,7,13,18,3,6,9,12,15,17,8,11,14};
    for(int i = 0; i < size; i++){
        fullTree.addData(array[i]);
    }
    cout << "Original Tree:\n";
    fullTree.traverseBFS();
    cout << "\nTesting 6 cases of deletes and 1 case of root delete in function using copy constructor:\n";
    testNoLeftDelete(fullTree);
    testNoRightDelete(fullTree);
    testLeafDelete(fullTree);
    testPredNoChildDelete(fullTree);
    testPredChildParentDelete(fullTree);
    testPredChildNoParentDelete(fullTree);
    testPredChildNoParentRootDelete(fullTree);
    
    cout << "\nTesting remaining 5 cases of deletes of the root:\n";
    testRootDeletes();
    return 0;
}

