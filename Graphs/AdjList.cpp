/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   AdjList.cpp
 * 
 */

#include "AdjList.h"
#include <iostream>
using namespace std;

AdjList::AdjList(){
    
}
AdjList::~AdjList(){
    for(vector<Vertex*>::iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        delete *p;
    }
}
void AdjList::addVertex(string name){
    try{
        findVertex(name);
        cout << "Vertex: " << name << " already exists!\n";
    }
    catch(VertexNotFound e){
        vertexList.push_back(new Vertex(name));
    }
}
void AdjList::addEdge(string src, string dest){
    
}
void AdjList::deleteVertex(string name){
    
}
void AdjList::deleteEdge(string src, string dest){
    
}
void AdjList::deleteGraph(){
    
}
void AdjList::traverseBFS()const{
    
}
void AdjList::traverseDFS()const{
    
}
void AdjList::printGraph()const{
    
}
Vertex* AdjList::findVertex(string name)const{
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        if(name.compare((*p)->name)==0)
            return *p;
    }
    throw VertexNotFound(name);
}