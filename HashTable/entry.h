/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/--/13
 *
 * File:   entry.h
 * Used in hashTable.h
 * 
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include <iostream>

template<class K,class V>
class entry{
    public:
        entry();
        void addEntry(K k, V v);
        void printEntries() const;
        void printTable() const;
    private:
        K key;
        V value;
        entry *next;
        bool empty;
};
template<class K,class V>
entry<K,V>::entry():empty(true){
    
}
template<class K,class V>
void entry<K,V>::addEntry(K k, V v){
    if(empty){
        key = k;
        value = v;
        empty = false;
        next = NULL;
    }
    else{
        if(next==NULL){
            next = new entry<K,V>;
            next->key = k;
            next->value = v;
            next->next = NULL;
        }
        else{
            entry<K,V> *curEntry = next;
            while(curEntry->next!=NULL){
                curEntry = curEntry->next;
            }
            curEntry->next = new entry<K,V>;
            curEntry->next->key = k;
            curEntry->next->value = v;
            curEntry->next->next = NULL;
        }
    }
}
template<class K,class V>
void entry<K,V>::printEntries() const{
    if(!empty){
        std::cout << "{"<<key<<":"<<value<<"} ";
        entry<K,V> *curEntry = next;
        while(curEntry!=NULL){
            std::cout << "{"<<curEntry->key<<":"<<curEntry->value<<"} ";
            curEntry = curEntry->next;
        }
    }
}
template<class K,class V>
void entry<K,V>::printTable() const{
    if(empty){
        std::cout << "Empty Bucket\n";
    }
    else{
         std::cout << "{"<<key<<":"<<value<<"}->";
        entry<K,V> *curEntry = next;
        if(next!=NULL){
            do{
                std::cout << "{"<<curEntry->key<<":"<<curEntry->value<<"}->";
                curEntry = curEntry->next;
            }while(curEntry!=NULL);
        }
        std::cout << "NULL\n";
    }
}
#endif	/* ENTRY_H */

