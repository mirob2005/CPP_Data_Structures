# *Graphs:*

## Usage: To run the provided test code in main.cpp, use the following commands:
### make
### ./AdjList

<table>
  <tr>
    <th>Type</th><th>Storage</th><th>Add Vertex</th><th>Add Edge</th><th>Remove Vertex</th><th>Remove Edge</th><th>Query</th>
  </tr>
  <tr>
    <td>Adjacency List</td><td>O(|V|+|E|)</td><td>O(1)</td><td>O(1)</td><td>O(|E|)</td><td>O(|E|)</td><td>O(|V|)</td>
  </tr>
  <tr>
    <td>Adjacency Matrix</td><td>O(|V|^2)</td><td>O(|V|^2)</td><td>O(1)</td><td>O(|V|^2)</td><td>O(1)</td><td>O(1)</td>
  </tr>
  <tr>
    <td>Incidence List</td><td>O(|V|+|E|)</td><td>O(1)</td><td>O(1)</td><td>O(|E|)</td><td>O(|E|)</td><td>O(|E|)</td>
  </tr>
  <tr>
    <td>Incidence Matrix</td><td>O(|V|*|E|)</td><td>O(|V|*|E|)</td><td>O(|V|*|E|)</td><td>O(|V|*|E|)</td><td>O(|V|*|E|)</td><td>O(|E|)</td>
  </tr>
</table>

## *Adjacency List:*
- Vertices are stored in a vector. Each vertex has a vector of next pointers to neighoring/adjacent vertices. 
- Supports directed graphs only (or add an edge for both direction for undirected).
- Weighted edges currently not implemented in this C++ version.

### *Operations:*
- addVertex
- addEdge
- deleteVertex
- deleteEdge
- copyGraph
- deleteVertices

### *Algorithm:*
*Breadth First Search*
- traverseBFS - runnning this gives the distance to each reachable vertex from the source vertex.

*Depth First Search*
- DAG test
- traverseDFS
- Classification of edges into (in comments): 
1)Tree Edges 
2)Back Edges 
3)Forward/Cross Edges

## *Adjacency Matrix:*
- Not Implemented

## *Incidence List:*
- Not Implemented

## *Incidence Matrix:*
- Not Implemented

