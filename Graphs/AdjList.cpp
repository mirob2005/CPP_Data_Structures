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
    cout << "Destructor Called!\n";
    if(!vertexList.empty()){
        deleteVertices();
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
    try{
        bool found = false;
        Vertex *deleteMe;
        for(vector<Vertex*>::iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
            if(name.compare((*p)->name)==0){
                deleteMe = *p;
                vertexList.erase(p);
                found = true;
                break;
            }
        }
        if(!found) throw VertexNotFound(name);
        
        for(vector<Vertex*>::iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
            for(vector<Vertex*>::iterator n = (*p)->next.begin(); n!=(*p)->next.end(); ++n){
                if(name.compare((*n)->name)==0){
                    (*p)->next.erase(n);
                    break;
                }
            }
        }
        delete deleteMe;
    }
    catch(VertexNotFound e){
        cout << "Cant delete vertex "<<name<< ": ";
        e.printMsg();
    }
}
void AdjList::deleteEdge(string src, string dest){
    try{
        bool found = false;
        Vertex *s = findVertex(src);
        Vertex *d = findVertex(dest);

        for(vector<Vertex*>::iterator p = s->next.begin(); p!=s->next.end(); ++p){
            if(*p==d){
                found = true;
                s->next.erase(p);
                break;
            }
        }
        if(!found){
            cout << "Edge from " << src << " to " << dest << " doesn't exist!\n";
        }
    }
    catch(VertexNotFound e){
        cout << "Cant delete edge from " << src << " to " << dest << ": ";
        e.printMsg();
    }
}
void AdjList::deleteVertices(){
    if(!vertexList.empty()){
        for(vector<Vertex*>::iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
            delete *p;
        }
        vertexList.clear();
    }
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
        else if((*p)->visit == Discovered){
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
bool AdjList::isDAG(){
    cout << "Traversing DFS to check for cycles:";
    cycleExists = false;
    traverseDFS();
    return (!cycleExists);
}
Vertex* AdjList::findVertex(string name)const{
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        if(name.compare((*p)->name)==0)
            return *p;
    }
    throw VertexNotFound(name);
}
AdjList* AdjList::copyGraph(){
    AdjList *copy = new AdjList;
    
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        (*p)->visit = Undiscovered;
    }
    for(vector<Vertex*>::const_iterator p = vertexList.begin(); p!=vertexList.end(); ++p){
        if((*p)->visit==Undiscovered){
            copy->vertexList.push_back(new Vertex((*p)->name));
            traverseCopy(*p,copy->vertexList.back(),copy);
        }
    }
    return copy;
}
void AdjList::traverseCopy(Vertex *orig, Vertex *copyV, AdjList *copy){
    orig->visit = Discovered;
    for(vector<Vertex*>::const_iterator p = orig->next.begin(); p!=orig->next.end(); ++p){
        //Tree Edge
        if((*p)->visit==Undiscovered){
            copy->vertexList.push_back(new Vertex((*p)->name));
            copyV->next.push_back(copy->vertexList.back());
            traverseCopy(*p,copy->vertexList.back(),copy);
        }
        else{
            copyV->next.push_back(copy->findVertex((*p)->name));
        }
    }
    orig->visit = Explored;
}