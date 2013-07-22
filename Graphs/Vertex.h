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

struct Vertex{
    Vertex(std::string nameIn): name(nameIn){
        
    }
    ~Vertex(){
        std::cout << "Deleting Vertex: "<< name << std::endl;
        next.clear();
    }
    std::string name;
    std::vector<Vertex*> next;
};


#endif	/* VERTEX_H */

