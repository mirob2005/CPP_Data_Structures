/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/11/13
 *
 * File:   hashTable.h
 * 
 * Hash Table is built using an array of buckets or entries.
 * When an entry is added to a given bucket, the bucket stores the entries in a linked list.
 * The bucket used is decided using the defined getHash() method which returns an index
 *   based off a hashing value modulo number of buckets in the hash table defined at
 *   object initialization.
 * The hashing value is calculated as follows:
 *   (int)character-32*95^placement
 *   where (int)character is the decimal value of the ASCII character
 * The printable ASCII chars are decimal 32 to 126, by subtracting 32 we get: 0 to 94
 * Example: key  = 'test'
 * (int)'t'-32 = 84 *95 ^0 = 84
 * (int)'e'-32 = 69 *95 ^1 = 6555
 * (int)'s'-32 = 83 *95 ^2 = 749075
 * (int)'t'-32 = 84 *95 ^3 = 72019500
 * Hashing Value = 72019500 + 749075 + 6555 + 84 = 72775214
 * Index = Hashing Value % numBuckets
 *
 * Results in a unique hashing value for any key
 *
 * Collisions are dealt using separate chaining.  Each bucket contains a 
 * linked list of entries with that index.
 * hash[hashCode] denotes the head of the linked list in that given bucket.
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
    hash = new entry<K,V>[copy.numBuckets];
    numBuckets = copy.numBuckets;
    for(int i=0;i<numBuckets;i++){
        hash[i].addEntries(copy.hash[i]);
    }
}
template<class K,class V>
hashTable<K,V>::~hashTable(){
    deleteAll();
    delete [] hash;
}
template<class K,class V>
void hashTable<K,V>::addEntry(K key, V value){
    unsigned int hashCode = getHash(key);
    hash[hashCode].addEntry(key,value);
}
template<class K,class V>
void hashTable<K,V>::deleteEntry(K key){
    unsigned int hashCode = getHash(key);
    try{
        hash[hashCode].deleteEntry(key);
    }
    catch(KeyDoesNotExist e){
        std::cout << e.getMessage();
    }
}
template<class K,class V>
void hashTable<K,V>::deleteAll(){
    for(int i=0;i<numBuckets;i++){
        hash[i].deleteEntries();
    }
}
template<class K,class V>
V hashTable<K,V>::lookUp(K key){
    unsigned int hashCode = getHash(key);
    return hash[hashCode].getEntry(key);
}
template<class K,class V>
void hashTable<K,V>::updateValue(K key, V value){
    unsigned int hashCode = getHash(key);
    hash[hashCode].updateEntry(key,value);
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

