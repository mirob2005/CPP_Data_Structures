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
    cout << "Adding Vertices 1,2,3,4,5,6\n";
    al.addVertex("1");
    al.addVertex("2");
    al.addVertex("3");
    al.addVertex("4");
    al.addVertex("5");
    al.addVertex("6");
    cout << "\nAdding duplicate vertex:\n";
    al.addVertex("1");
    
    cout << "\nAdding valid edges 1->2,1->3,2->4,2->5,3->2,3->5,5->4,4->6,5->6\n";
    al.addEdge("1","2");
    al.addEdge("1","3");
    al.addEdge("2","4");
    al.addEdge("2","5");
    al.addEdge("3","2");
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
    al.traverseBFS("A");
    
    cout << "\nTraversing Graph in DFS:\n";
    al.traverseDFS();
    
    cout << "\nDeleting valid vertex 2\n";
    al.deleteVertex("2");
    
    cout << "\nDeleting invalid vertex:\n";
    al.deleteVertex("2");
    
    cout << "\nPrinting Graph:\n";
    al.printGraph();
    
    cout << "\nTraversing Graph in BFS from valid source:\n";
    al.traverseBFS("1");
    
    cout << "\nTraversing Graph in BFS from invalid source:\n";
    al.traverseBFS("2");
    
    cout << "\nTraversing Graph in DFS:\n";
    al.traverseDFS();
    
    cout << "\nDeleting valid edge 4->6\n";
    al.deleteEdge("4","6");
    
    cout << "\nDeleting invalid edge 4->6\n";
    al.deleteEdge("4","6");
    cout << "\nDeleting invalid edge 1->2\n";
    al.deleteEdge("1","2");
    
    cout << "\nPrinting Graph:\n";
    al.printGraph();
    
    cout << endl;
    return 0;
}

