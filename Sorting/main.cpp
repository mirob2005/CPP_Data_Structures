/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/06/13
 *
 * File:   main.cpp
 * Sorts the array using the implemented sorting algorithms.
 * Only selection and insertion sorts implemented so far.
 * 
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include "insertionSort.cpp"
#include "selectionSort.cpp"

using namespace std;

const unsigned int size = 100;

int main(int argc, char** argv) {
    srand(time(NULL));
    
    int original[size];
    int numbers[size];
    for(int i = 0; i < size; i++){
        original[i] = rand()%size;
    }
    
    memcpy(numbers,original,sizeof(original));
    
    cout << "Numbers Before Insertion Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    insertionSort(numbers, size);
    
    cout << "Numbers After Insertion Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    memcpy(numbers,original,sizeof(original));
    
    cout << "Numbers Before Selection Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    selectionSort(numbers, size);
    
    cout << "Numbers After Selection Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    return 0;
}

