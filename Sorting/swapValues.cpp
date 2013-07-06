/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/06/13
 *
 * File:   swapValues.cpp
 * Used in insertion sort and selection sort.
 * 
 */

#ifndef SWAPVALUES_CPP
#define SWAPVALUES_CPP

template<class T>
void swapValues(T &v1, T &v2){
    T temp = v1;
    v1 = v2;
    v2 = temp;
}
#endif