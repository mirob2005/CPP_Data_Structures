/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/11/13
 *
 * File:   main.cpp
 * Testing hashTable.h
 * 
 */

#include <cstdlib>
#include <string>
#include "hashTable.h"
#include <iostream>

using namespace std;

template<class K, class V>
void testCopyConstructor(hashTable<K,V> copy){
    cout << "Adding key 'seven' to copy hash in function:\n";
    copy.addEntry("seven",7);
    cout << "Printing hashed values in function\n";
    copy.printHash();
    cout << "\nPrinting bucket organization in function\n";
    copy.printTable();
    cout << endl;
}

int main(int argc, char** argv) {
    hashTable<string,int> ht(11);
    ht.addEntry("first",1);
    //Testing update value via duplicate key add
    ht.addEntry("first",2);
    ht.addEntry("second",2);
    ht.addEntry("third",3);
    ht.addEntry("four",4);
    ht.addEntry("five",5);
    ht.addEntry("six",6);
    cout << "Printing hashed values\n";
    ht.printHash();
    cout << "\nPrinting bucket organization\n";
    ht.printTable();
    
    cout << "\nLooking up existing key:\n";
    try{
        cout << ht.lookUp("first") << endl;
    }
    catch(KeyDoesNotExist e){
        cout << e.getMessage();
    }
    cout << "\nLooking up missing key:\n";
    try{
        cout << ht.lookUp("first1") <<endl;
    }
    catch(KeyDoesNotExist e){
        cout << e.getMessage();
    }
    
    cout << "\nDeleting existing entry head of link:\n";
    ht.deleteEntry("first");
    cout << "Printing hashed values\n";
    ht.printHash();
    cout << "\nPrinting bucket organization\n";
    ht.printTable();
    cout << "\nDeleting missing entry:\n";
    ht.deleteEntry("first");
    cout << "\nDeleting existing entry head with no link:\n";
    ht.deleteEntry("third");
    cout << "Printing hashed values\n";
    ht.printHash();
    cout << "\nPrinting bucket organization\n";
    ht.printTable();
    
    cout << "\nAdding new keys in previous emptied bucket:\n";
    ht.addEntry("third",3);
    ht.addEntry("first",1);
    cout << "Printing hashed values\n";
    ht.printHash();
    cout << "\nPrinting bucket organization\n";
    ht.printTable();
    
    cout << "\nUpdating key:third to a value of 7\n";
    ht.updateValue("third",7);
    cout << "Printing hashed values\n";
    ht.printHash();
    cout << "\nPrinting bucket organization\n";
    ht.printTable();
    
    cout << "\nCalling function to test copy constructor:\n";
    testCopyConstructor(ht);
    cout << "\nPrinting hashed values after function call\n";
    ht.printHash();
    cout << "\nPrinting bucket organization after function call\n";
    ht.printTable();
    return 0;
}

