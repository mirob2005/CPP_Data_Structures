/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/06/13
 *
 * File:   selectionSort.cpp
 * 
 */

#include "swapValues.cpp"

template<class T>
void selectionSort(T array[], int size){
    for(int i = 0; i < size; i++){
        int minIndex = i;
        int j = i+1;
        bool flag = false;
        while(j < size){
            if(array[j]<array[minIndex]){
                minIndex = j;
                flag = true;
            }
            j++;
        }
        if(flag)
            swapValues(array[i],array[minIndex]);
    }
}