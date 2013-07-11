/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/11/13
 *
 * File:   entry.h
 * Used in hashTable.h
 * Stores entries in a linked list-type data structure.
 * 
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include <iostream>
#include <sstream>
#include <string>

//Custom Exception
class KeyDoesNotExist{
    public:
        KeyDoesNotExist();
        KeyDoesNotExist(std::string msg);
        std::string getMessage();
    private:
        std::string message;
};
KeyDoesNotExist::KeyDoesNotExist(){
    
}
KeyDoesNotExist::KeyDoesNotExist(std::string msg): message(msg){
    
}
std::string KeyDoesNotExist::getMessage(){
    return message;
}

template<class K,class V>
class entry{
    public:
        entry();
        ~entry();
        void addEntry(K k, V v);
        V getEntry(K k)const;
        void deleteEntry(K k);
        void deleteEntries();
        void updateEntry(K k, V v);
        void addEntries(entry<K,V> &copy);
        void printEntries() const;
        void printTable() const;
    private:
        K key;
        V value;
        entry *next;
        bool empty;
        void throwKeyDoesNotExistExc(K k)const;
};
template<class K,class V>
entry<K,V>::entry():empty(true){
    
}
template<class K,class V>
entry<K,V>::~entry(){
    std::cout << "Deleted "<< key << std::endl;
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
        entry<K,V> *curEntry = this;
        if(curEntry->key==k){
            curEntry->value = v;
        }
        else{
            bool update = false;
            while(curEntry->next!=NULL){
                if(curEntry->key==k){
                    curEntry->value = v;
                    update = true;
                    break;
                }
                curEntry = curEntry->next;
            }
            if(!update){
                curEntry->next = new entry<K,V>;
                curEntry->next->key = k;
                curEntry->next->value = v;
                curEntry->next->next = NULL;
            }
        }
    }
}
template<class K,class V>
V entry<K,V>::getEntry(K k) const{
    const entry<K,V> *curEntry = this;
    while(curEntry!=NULL){
        if(curEntry->key == k){
            return curEntry->value;
        }
        curEntry = curEntry->next;
    }
    throwKeyDoesNotExistExc(k);
    return 0;
}
template<class K,class V>
void entry<K,V>::deleteEntry(K k){
    bool found = false;
    if(!empty){
        entry<K,V> *curEntry = this;
        //If we are deleting the head of a linked list that has entries behind it
        //  we swap the key and value with the following entry and then delete
        //  that following entry
        //If there are no entries behind it, we just set this bucket as 'empty'
        if(curEntry->key == k){
            if(curEntry->next!=NULL){
                K temp = curEntry->key;
                curEntry->key = curEntry->next->key;
                curEntry->value = curEntry->next->value;
                entry<K,V> *deleteMe = curEntry->next;
                curEntry->next = deleteMe->next;
                deleteMe->key = temp;
                delete deleteMe;
            }
            else{
                empty = true;
            }
            return;
        }
        //If the entry is not the head, we delete it as we normally would by 
        //  updating the next ptr and delete the entry.
        while(curEntry->next!=NULL){
            if(curEntry->next->key == k){
                found = true;
                entry<K,V> *deleteMe = curEntry->next;
                curEntry->next = deleteMe->next;
                delete deleteMe;
                break;
            }
            curEntry = curEntry->next;
        }
    }
    if(!found){
        throwKeyDoesNotExistExc(k);
    }
}
template<class K,class V>
void entry<K,V>::deleteEntries(){
    if(!empty){
        //Delete all entries except for the head and then set the empty flag
        if(next!=NULL){
            entry<K,V> *deleteMe = next;
            while(deleteMe!=NULL){
                next = deleteMe->next;
                delete deleteMe;
                deleteMe = next;
            }
        }
        empty = true;
    }
}
template<class K,class V>
void entry<K,V>::updateEntry(K k, V v){
    entry<K,V> *curEntry = this;
    while(curEntry!=NULL){
        if(curEntry->key == k){
            curEntry->value = v;
            return;
        }
        curEntry = curEntry->next;
    }
    throwKeyDoesNotExistExc(k);
}
template<class K,class V>
void entry<K,V>::addEntries(entry<K,V> &copy){
    entry<K,V> *originalPtr = &copy;
    if(!originalPtr->empty){
        entry<K,V> *curPtr = this;
        key = originalPtr->key;
        value = originalPtr->value;
        originalPtr = originalPtr->next;
        while(originalPtr!=NULL){
            curPtr->next = new entry<K,V>;
            curPtr->next->key = originalPtr->key;
            curPtr->next->value = originalPtr->value;
            originalPtr = originalPtr->next;
            curPtr = curPtr->next;
        }
        curPtr->next = NULL;
        empty = false;
    }
}
template<class K,class V>
void entry<K,V>::throwKeyDoesNotExistExc(K k) const{
    std::stringstream ss;
    ss << k;
    throw KeyDoesNotExist(ss.str() + " DOES NOT exist!\n");
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

