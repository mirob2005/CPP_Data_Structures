/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   AdjList.cpp
 * 
 */

#include "AdjList.h"
#include "Queue.h"
#include <iostream>
using namespace std;

AdjList::AdjList(): cycleExists(false){
    
}
AdjList::~AdjList(){
    cout << "Deconstructor Called!\n";
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
    try{
        Vertex *s = findVertex(src);
        Vertex *d = findVertex(dest);
        s->next.push_back(d);
    }
    catch(VertexNotFound e){
        cout << "Cant add edge from " << src << " to " << dest << ": ";
        e.printMsg();
    }
}
void AdjList::deleteVertex(string name){
    
}
void AdjList::deleteEdge(string src, string dest){
    
}
void AdjList::deleteGraph(){
    
}
void AdjList::traverseBFS(string src)const{
    try{
        if(vertexList.empty()){
            cout << "Graph is Empty!\n";
            return;
        }
        Vertex *source = findVertex(src);
        for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
            (*p)->visit = Undiscovered;
        }
        
        Queue<Vertex*> bfsq;
        bfsq.enQueue(source);
        source->visit = Discovered;
        source->distance = 0;
        Vertex *curVertex = bfsq.deQueue();
        while(curVertex!=NULL){
            for(vector<Vertex*>::const_iterator p = curVertex->next.begin(); p!=curVertex->next.end(); ++p){
                if((*p)->visit==Undiscovered){
                    (*p)->visit = Discovered;
                    (*p)->distance = curVertex->distance + 1;
                    bfsq.enQueue(*p);
                }
            }
            curVertex->visit = Explored;
            cout << "Vertex: " << curVertex->name << " Distance: " << curVertex->distance << endl;
            try{
                curVertex = bfsq.deQueue();
            }
            catch(EmptyQueue e){
                break;
            }
        }
    }
    catch(VertexNotFound e){
        cout << "Can't traverse graph BFS from source: " << src << ", ";
        e.printMsg();
    }    
}
void AdjList::traverseDFS(){
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        (*p)->visit = Undiscovered;
    }
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        if((*p)->visit==Undiscovered){
            DFS(*p);
        }
    }
    cout << endl;
}
void AdjList::DFS(Vertex* src){
    src->visit = Discovered;
    cout << src->name << " ";
    for(vector<Vertex*>::const_iterator p = src->next.begin(); p!=src->next.end(); ++p){
        //Tree Edge
        if((*p)->visit==Undiscovered){
            DFS(*p);
        }
        //Back Edge
        else if((*p)->visit = Discovered){
            cycleExists = true;
        }
        //Forward/Cross Edge
        else{
            //Do Nothing
        }
    }
    src->visit = Explored;
}
void AdjList::printGraph()const{
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        cout << *(*p);
    }
}
Vertex* AdjList::findVertex(string name)const{
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        if(name.compare((*p)->name)==0)
            return *p;
    }
    throw VertexNotFound(name);
}