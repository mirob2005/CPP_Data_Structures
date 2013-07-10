/* 
 * File:   main.cpp
 * Author: mike
 *
 * Created on July 9, 2013, 2:16 PM
 */

#include <cstdlib>
#include <string>
#include "hashTable.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    hashTable<string,int> ht(10);
    ht.addEntry("first",1);
    ht.addEntry("second",2);
    ht.addEntry("third",3);
    ht.addEntry("four",4);
    ht.addEntry("five",5);
    ht.addEntry("six",6);
    cout << "Printing hashed values\n";
    ht.printHash();
    cout << "Printing bucket organization\n";
    ht.printTable();
    
    return 0;
}

