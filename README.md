CPP Data Structures
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

## *Binary Search Tree Operations:*
### Usage: Run Trees/main.cpp, Trees/charTester.cpp, or Trees/deleteTester.cpp to test the operations of BST.
- addData - recursive
- findData - recursive
- deleteData - recursive
- traverseBFS - iterative (uses a queue)
- traverseDFSpreorder - recursive
- traverseDFSinorder - recursive
- traverseDFSpostorder - recursive
- copyTree - recursive
- deleteTree - recursive
- findMin - iterative
- findMax - iterative

## *Graphs:*
### Usage: To run the provided test code in main.cpp, use the following commands:
- make
- ./AdjList

### *Adjacency List:*
- Vertices are stored in a vector. Each vertex has a vector of next pointers to neighoring/adjacent vertices. 
- Supports directed graphs only (or add an edge for both direction for undirected).
- Weighted edges currently not implemented in this C++ version.

*Operations:*
- addVertex
- addEdge
- deleteVertex
- deleteEdge
- copyGraph
- deleteVertices

*Algorithms:*

*Breadth First Search*
- traverseBFS - gives the distance to each reachable vertex (shortest path)

*Depth First Search*
- DAG test
- traverseDFS
- Classification of edges into (in comments): 
1)Tree Edges 
2)Back Edges 
3)Forward/Cross Edges

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

