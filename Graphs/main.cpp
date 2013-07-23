/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   main.cpp
 * Tests AdjList
 * 
 */
#include <iostream>
#include "AdjList.h"
using namespace std;

int main(int argc, char** argv) {
    AdjList al;
    cout << "Adding Vertices\n";
    al.addVertex("1");
    al.addVertex("2");
    al.addVertex("3");
    al.addVertex("4");
    al.addVertex("5");
    al.addVertex("6");
    cout << "\nAdding duplicate vertex:\n";
    al.addVertex("1");
    
    cout << "\nAdding valid edges\n";
    al.addEdge("1","2");
    al.addEdge("1","3");
    al.addEdge("2","4");
    al.addEdge("2","5");
    al.addEdge("3","5");
    al.addEdge("5","4");
    al.addEdge("4","6");
    al.addEdge("5","6");
    cout << "\nAdding invalid edges:\n";
    al.addEdge("1","A");
    al.addEdge("A","4");
    
    cout << "\nPrinting Graph:\n";
    al.printGraph();
    
    cout << "\nTraversing Graph in BFS from valid source:\n";
    al.traverseBFS("1");
    
    cout << "\nTraversing Graph in BFS from invalid source:\n";
    al.traverseBFS("3");
    
    cout << "\nTraversing Graph in DFS:\n";
    al.traverseDFS();
    
    cout << endl;
    return 0;
}

