# *Trees*
## *Binary Search Tree Operations:*
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

## Use:
- Run  main.cpp to test the basic operations of the BST using ints.
- Run charTester.cpp to test the same operations using chars.
- Run deleteTester to test for 12 different types of deletes.

## Types of deletes:
1. Leaf Node (non-root)
2. No right child (non-root)
3. No left child (non-root)
4. Inorder predecessor has no children (non-root)
5. Inorder predecssor has a child (must be left) and the parent is to be removed. (non-root)
6. Inorder predecssor has a child (must be left) and an ancestor (non-parent) is to be removed. (non-root)
7. Types 1-6 applied to the root. 
