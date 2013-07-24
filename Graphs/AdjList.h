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

class VertexNotFound{
public:
    std::string name;
    VertexNotFound(std::string nameIn): name(nameIn){
        
    }
    ~VertexNotFound(){
        
    }
    void printMsg(){
        std::cout << "Vertex: " << name << " does not exist!\n";
    }
};

class AdjList{
public:
    AdjList();
    ~AdjList();
    void addVertex(std::string name);
    void deleteVertex(std::string name);
    void addEdge(std::string src, std::string dest);
    void deleteEdge(std::string src, std::string dest);
    void traverseBFS(std::string src)const;
    void traverseDFS();
    void printGraph()const;
    void deleteVertices();
    bool isDAG();
    AdjList* copyGraph();
private:
    std::vector<Vertex*> vertexList;
    bool cycleExists;
    Vertex* findVertex(std::string name)const;
    void DFS(Vertex *src);
    void traverseCopy(Vertex *src, Vertex *copyV, AdjList *copy);
};


#endif	/* ADJLIST_H */

