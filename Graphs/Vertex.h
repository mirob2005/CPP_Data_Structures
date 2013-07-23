/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/--/13
 *
 * File:   Vertex.h
 * Used in AdjList.h
 * 
 */

#ifndef VERTEX_H
#define	VERTEX_H
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

enum Visited{
    Undiscovered, Discovered, Explored
};

struct Vertex{
    Vertex(std::string nameIn): name(nameIn), visit(Undiscovered){
        
    }
    ~Vertex(){
        std::cout << "Deleting Vertex: "<< name << std::endl;
        next.clear();
    }
    friend std::ostream& operator <<(std::ostream &outs, const Vertex& vertex){
    outs << "Vertex: " << vertex.name << " is adjacent to: ";
    for(std::vector<Vertex*>::const_iterator p = vertex.next.begin(); p!=vertex.next.end(); ++p){
        outs << (*p)->name << " ";
    }
    outs << std::endl;
}

    std::string name;
    std::vector<Vertex*> next;
    Visited visit;
    
};




#endif	/* VERTEX_H */
