/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   AdjList.h
 * 
 */

#ifndef ADJLIST_H
#define	ADJLIST_H
#include <string>
#include <vector>
#include "Vertex.h"
using namespace std;

class VertexNotFound{
public:
    string name;
    VertexNotFound(string nameIn): name(nameIn){
        
    }
    ~VertexNotFound(){
        
    }
    void printMsg(){
        cout << "Vertex: " << name << " does not exist!\n";
    }
};

class AdjList{
public:
    AdjList();
    ~AdjList();
    void addVertex(string name);
    void deleteVertex(string name);
    void addEdge(string src, string dest);
    void deleteEdge(string src, string dest);
    void traverseBFS()const;
    void traverseDFS()const;
    void printGraph()const;
    void deleteGraph();
private:
    vector<Vertex*> vertexList;
    Vertex* findVertex(string name)const;
};


#endif	/* ADJLIST_H */

