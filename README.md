CPP_Data_Structures
===================

## *ADTS:*
- Queue - head/tail ptrs, remove old at head, append new to the front
- Stack - push/pop at head
- Priority Queue - uses an array-based Binary Heap

### *Binary Heap:*
*Operations:*
- traverseBFS
- insert (with heapifyUp to ensure heap property)
- delete (with heapifyDown to ensure heap property)
- peek (get max value)

*Types:*
- Vector Structure

## *Hash Table Operations:*
### Usage: Run HashTable/main.cpp to test the hashTable class.
- add
- updateValue
- delete
- deleteAll
- lookUp
- getHash

### *Types:*
- Separate Chaining Collision resolution using Linked Lists

## *Sorting:*
### Usage: Run Sorting/main.cpp to run all implemented sorting methods.

### Exchange Sorts:
### QuickSort:
- not in place, not stable
- O(n log n) best/AVG, O(n^2) worst case performance
- O(n) auxiliary space
- fastest on average

### Insertion Sorts:
### Insertion Sort:
- stable, in-place
- O(n^2) - worst/AVG case, O(n) - best case (already sorted list)
- O(1) auxilary - worst case space complexity

### Merge Sorts:
### MergeSort:
- not in place, stable sort
- O(n log n) best/AVG/worst case performance
- O(n) auxiliary space

### Selection Sorts:
### Selection Sort:
- in-place, stable sort
- O(n^2) - best/AVG/worst case performance
- O(1) auxilary - worst case space complexity

## *TODO:*
- Graphs
- Trees
