/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/08/13
 *
 * File:   main.cpp
 * Sorts the array using the implemented sorting algorithms.
 * Merge, quick, selection, and insertion sorts are implemented.
 * 
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include "insertionSort.cpp"
#include "selectionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"

using namespace std;

const unsigned int size = 100;

int main(int argc, char** argv) {
    srand(time(NULL));
    
    int original[size];
    int numbers[size];
    int sorted[size];
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
    
    memcpy(sorted,numbers,sizeof(numbers));
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
    
    if(memcmp(sorted,numbers,sizeof(sorted))==0)
        cout << "Selection sort matches sorted array from insertion sort!\n\n";
    else
        cout << "Selection sort DOES NOT match the sorted array from insertion sort!\n\n";
    memcpy(numbers,original,sizeof(original));
    
    cout << "Numbers Before Merge Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    mergeSort(numbers, size);
    
    cout << "Numbers After Merge Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    if(memcmp(sorted,numbers,sizeof(sorted))==0)
        cout << "Merge sort matches sorted array from insertion sort!\n\n";
    else
        cout << "Merge sort DOES NOT match the sorted array from insertion sort!\n\n";    
    memcpy(numbers,original,sizeof(original));
    
    cout << "Numbers Before Quick Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    quickSort(numbers, size);
    
    cout << "Numbers After Quick Sort:\n";
    for(int i = 0; i < size; i++){
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    
    if(memcmp(sorted,numbers,sizeof(sorted))==0)
        cout << "Quick sort matches sorted array from insertion sort!\n\n";
    else
        cout << "Quick sort DOES NOT match the sorted array from insertion sort!\n\n";
    
    int s = 18;
    char def[] = {'Z','B','E','C','K','D','B','U','I','O','Q','E','T','R','Y','U','I','O'};
    char c[s];
    memcpy(c,def,sizeof(def));
    cout << "Chars Before Insertion Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    insertionSort(c,s);
    cout << "Chars After Insertion Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    memcpy(c,def,sizeof(def));
    cout << "Chars Before Selection Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    selectionSort(c,s);
    cout << "Chars After Selection Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    memcpy(c,def,sizeof(def));
    cout << "Chars Before Merge Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    mergeSort(c,s);
    cout << "Chars After Merge Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    memcpy(c,def,sizeof(def));
    cout << "Chars Before Quick Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    quickSort(c,s);
    cout << "Chars After Quick Sort:\n";
    for(int i = 0; i<s;i++){
        cout << c[i] << " ";
    }
    cout << endl << endl;
    return 0;
}

