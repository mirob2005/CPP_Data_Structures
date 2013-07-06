/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/06/13
 *
 * File:   insertionSort.cpp
 * 
 */
#include "swapValues.cpp"

template<class T>
void insertionSort(T array[], int size){
    for(int i = 1; i < size; i++){
        int j = i-1;
        while(j >=0){
            if(array[i]<array[j]){
                swapValues(array[i],array[j]);
                j--,i--;
            }
            else
                break;
        }
    }
}

