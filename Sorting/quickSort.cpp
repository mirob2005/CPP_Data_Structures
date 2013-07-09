/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 07/08/13
 *
 * File:   quickSort.cpp
 * Recursively calls quickSort with sublists until the sublist is 0 or 1
 *  elements long.
 * Pivot value is chosen to be the middle element of the given sublist.
 * Uses 2 temp arrays to store the elements less/more than the pivot which is
 *  then copied over to the preexisting array in the correct location.
 * 
 */

template<class T>
void quickSort(T array[], int start, int pivotIndex, int end){
    T pivot = array[pivotIndex]; 
    T less[end-start],more[end-start];
    int lessCount = 0, moreCount = 0;
    for(int i = start; i < pivotIndex; i++){
        if(array[i] <= pivot){
            less[lessCount] = array[i];
            lessCount++;
        }
        else if(array[i] > pivot){
            more[moreCount] = array[i];
            moreCount++;
        }
    }
    for(int i = pivotIndex+1; i < end; i++){
        if(array[i] <= pivot){
            less[lessCount] = array[i];
            lessCount++;
        }
        else if(array[i] > pivot){
            more[moreCount] = array[i];
            moreCount++;
        }
    }
    //Copy less/more arrays back into the original array at the correct locations.
    memcpy(&array[start],less,lessCount*sizeof(T));
    array[lessCount+start] = pivot;
    memcpy(&array[lessCount+start+1],more,moreCount*sizeof(T));
    
    //Recurse if sublist contains more than one element.
    if(lessCount>1){
        quickSort(array,start,start+static_cast<int>(lessCount/2),start+lessCount);
    }
    if(moreCount>1){
        int moreStart = start+lessCount+1;
        quickSort(array,moreStart,moreStart+static_cast<int>((end-moreStart)/2),moreStart+moreCount);
    }
}

template<class T>
void quickSort(T array[], int size){
    if(size <=1)
        return;
    
    int pivot = static_cast<int>(size/2);
    quickSort(array, 0, pivot, size);
}