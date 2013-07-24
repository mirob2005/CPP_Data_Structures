/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/24/13
 *
 * File:   main.cpp
 * Tests AdjList
 * 
 */
#include <iostream>
#include "AdjList.h"
using namespace std;

int main(int argc, char** argv) {
    AdjList *al = new AdjList;
    cout << "Adding Vertices 1,2,3,4,5,6\n";
    al->addVertex("1");
    al->addVertex("2");
    al->addVertex("3");
    al->addVertex("4");
    al->addVertex("5");
    al->addVertex("6");
    cout << "\nAdding duplicate vertex:\n";
    al->addVertex("1");
    
    cout << "\nAdding valid edges 1->2,1->3,2->4,2->5,3->2,3->5,5->4,4->6,5->6\n";
    al->addEdge("1","2");
    al->addEdge("1","3");
    al->addEdge("2","4");
    al->addEdge("2","5");
    al->addEdge("3","2");
    al->addEdge("3","5");
    al->addEdge("5","4");
    al->addEdge("4","6");
    al->addEdge("5","6");
    cout << "\nAdding invalid edges:\n";
    al->addEdge("1","A");
    al->addEdge("A","4");
    
    cout << "\nPrinting Graph:\n";
    al->printGraph();
    
    cout << "\nTraversing Graph in BFS from valid source:\n";
    al->traverseBFS("1");
    
    cout << "\nTraversing Graph in BFS from invalid source:\n";
    al->traverseBFS("A");
    
    cout << "\nTraversing Graph in DFS:\n";
    al->traverseDFS();
    
    if(al->isDAG()){
        cout << "Graph is a DAG\n";
    }else{
        cout << "Graph is NOT a DAG\n";
    }
    
    cout << "\nMaking a copy graph\n";
    AdjList *copy = al->copyGraph();
    
    cout << "\nDeleting valid vertex 2 from original\n";
    al->deleteVertex("2");
    
    cout << "\nDeleting invalid vertex from original:\n";
    al->deleteVertex("2");
    
    cout << "\nPrinting Copied Graph:\n";
    copy->printGraph();
    
    cout << "\nPrinting Original Graph:\n";
    al->printGraph();
    
    cout << "\nTraversing Original Graph in BFS from valid source:\n";
    al->traverseBFS("1");
    
    cout << "\nTraversing Original Graph in BFS from invalid source:\n";
    al->traverseBFS("2");
    
    cout << "\nTraversing Original Graph in DFS:\n";
    al->traverseDFS();
    
    cout << "\nDeleting valid edge 4->6 from Original Graph\n";
    al->deleteEdge("4","6");
    
    cout << "\nDeleting invalid edge 4->6 from Original Graph\n";
    al->deleteEdge("4","6");
    cout << "\nDeleting invalid edge 1->2 from Original Graph\n";
    al->deleteEdge("1","2");
    
    cout << "\nPrinting Original Graph:\n";
    al->printGraph();
    
    cout << "\nPrinting Copied Graph:\n";
    copy->printGraph();
    
    cout << "\nTraversing Copied Graph in BFS from valid source:\n";
    copy->traverseBFS("1");
    
    cout << "\nTraversing Copied Graph in DFS:\n";
    copy->traverseDFS();
    
    cout << "\nDeleting Vertices from original graph:\n";
    al->deleteVertices();
    
    cout << "\nAdding Vertices and edges to form cycle to original graph:\n";
    al->addVertex("1");
    al->addVertex("2");
    al->addEdge("1","2");
    al->addEdge("2","1");
    
    cout << "\nPrinting original Graph:\n";
    al->printGraph();
    
    cout << "\nTraversing Original Graph in BFS from valid source:\n";
    al->traverseBFS("1");
    
    cout << "\nTraversing Original Graph in BFS from invalid source:\n";
    al->traverseBFS("3");
    
    cout << "\nTraversing Original Graph in DFS:\n";
    al->traverseDFS();
    
    if(al->isDAG()){
        cout << "Original Graph is a DAG\n";
    }else{
        cout << "Original Graph is NOT a DAG\n";
    }
    
    cout << "\nPrinting Copied Graph:\n";
    copy->printGraph();
    
    if(copy->isDAG()){
        cout << "Copied Graph is a DAG\n";
    }else{
        cout << "Copied Graph is NOT a DAG\n";
    }
    
    cout << endl;
    
    delete al;
    delete copy;
    
    return 0;
}

