/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/07/13
 *
 * File:   mergeSort.cpp
 * Bottom-Up Approach
 * 
 */
#include "swapValues.cpp"

template<class T>
void merge(T array[], int leftStart,int rightStart, int rightEnd){
    //Temporary array to hold sorted sublist, copied back over to array in the 
    //  correct location upon completion of merge
    T temp[rightEnd-leftStart];
    int current = 0;
    T *leftPtr = &array[leftStart];
    T *leftEndPtr = &array[rightStart];
    T *rightPtr = &array[rightStart];
    T *rightEndPtr = &array[rightEnd];
    
    //While there is data left to be read in BOTH sublists
    while(leftPtr != leftEndPtr && rightPtr != rightEndPtr){
        if(*leftPtr < *rightPtr){
            temp[current] = *leftPtr;
            leftPtr++,current++;
        }
        else{
            temp[current] = *rightPtr;
            rightPtr++,current++;
        }
    }
    //Copy over the remaining data in the 1 non-fully read sublist
    if(leftPtr != leftEndPtr){
        memcpy(&temp[current],leftPtr,(leftEndPtr-leftPtr)*sizeof(T));
    }
    else{
        memcpy(&temp[current],rightPtr,(rightEndPtr-rightPtr)*sizeof(T));
    }
    //Copy data over from the temporary array to our preexisting array in the 
    //  correct memory location
    memcpy(&array[leftStart],temp,sizeof(temp));
}

template<class T>
void mergeSort(T array[], int size){
    if(size <=1)
        return;
    
    int leftStart,rightStart,rightEnd;
    
    //Build up sublists bottom-up
    for(unsigned int i = 1; i < size; i = 2*i){
        for(unsigned int start = 0; start < size; start = start+i*2){
            leftStart = start;
            rightStart = start+i<size?start+i:size;
            rightEnd = start+i*2<size?start+i*2:size;
            merge(array, leftStart,rightStart,rightEnd);
        }
    }
}