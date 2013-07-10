/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/--/13
 *
 * File:   hashTable.h
 * 
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "entry.h"
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cmath>

template<class K,class V>
class hashTable{
    public:
        hashTable(int numBuckets);
        hashTable(const hashTable &copy);
        ~hashTable();
        void addEntry(K key, V value);
        void deleteEntry(K key);
        void deleteAll();
        void updateValue(K key, V value);
        V lookUp(K key);
        void printHash()const;
        void printTable()const;
    private:
        entry<K,V> *hash;
        unsigned int numBuckets;
        unsigned int getHash(K key);
};

template<class K,class V>
hashTable<K,V>::hashTable(int numBuckets): numBuckets(numBuckets){
    hash = new entry<K,V>[numBuckets];
}
template<class K,class V>
hashTable<K,V>::hashTable(const hashTable& copy){
    
}
template<class K,class V>
hashTable<K,V>::~hashTable(){
    
}
template<class K,class V>
void hashTable<K,V>::addEntry(K key, V value){
    unsigned int hashCode = getHash(key);
    //INSERT: Handle duplicates
    hash[hashCode].addEntry(key,value);
}
template<class K,class V>
void hashTable<K,V>::deleteEntry(K key){
    
}
template<class K,class V>
void hashTable<K,V>::deleteAll(){
    
}
template<class K,class V>
V hashTable<K,V>::lookUp(K key){
    
}
template<class K,class V>
void hashTable<K,V>::updateValue(K key, V value){
    
}
template<class K,class V>
void hashTable<K,V>::printHash()const{
    for(int i = 0; i < numBuckets; i++){
        hash[i].printEntries();
    }
    std::cout << std::endl;
}
template<class K,class V>
void hashTable<K,V>::printTable()const{
    for(int i = 0; i < numBuckets; i++){
        hash[i].printTable();
    }
}
template<class K, class V>
unsigned int hashTable<K,V>::getHash(K key){
    std::stringstream ss;
    ss << key;
    std::string s = ss.str();
    const char *c = s.c_str();
    unsigned long int hash = 0;
    for(int i = 0; i < strlen(c);i++){
        hash += (static_cast<int>(c[i])-32)*pow(95,i);
    }
    return static_cast<int>(hash%numBuckets);
}

#endif	/* HASHTABLE_H */

