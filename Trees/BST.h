/*
 * Michael Robertson
 * mirob2005@gmail.com
 * Completed: 7/17/13
 *
 * File:   BST.h
 * 
 */

#ifndef BST_H
#define	BST_H

#include "treeNode.h"
#include "Queue.h"

template<class T>
class BST{
    public:
        BST();
        ~BST();
        BST(const BST<T> &copyBST);
        void addData(T data);
        void deleteData(T data);
        bool findData(T data);
        T findMin();
        T findMax();
        void traverseBFS();
        void traverseDFSpreorder();
        void traverseDFSinorder();
        void traverseDFSpostorder();
        void printBranches();
        void deleteTree();
        BST<T> copyTree();
    private:
        treeNode<T> *root;
        void addData(T data, treeNode<T> *curRoot);
        void deleteData(T data, treeNode<T> *curRoot);
        void deleteNode1Child(treeNode<T> *deleteMe, treeNode<T> *replace, treeNode<T> *parent);
        void deleteNode2Children(treeNode<T> *curRoot);
        treeNode<T>* returnInorderPredescessor(treeNode<T> *curRoot);
        bool findData(T data, treeNode<T> *curRoot);
        void traverseDFSpreorder(treeNode<T> *curRoot);
        void traverseDFSinorder(treeNode<T> *curRoot);
        void traverseDFSpostorder(treeNode<T> *curRoot);
        void deleteTree(treeNode<T> *curRoot);
        void copyTree(treeNode<T> *curRoot, treeNode<T> *newRoot);
};
template<class T>
BST<T>::BST(): root(NULL){
    
}
template<class T>
BST<T>::~BST(){
    std::cout << "Deconstructor Called\n";
    deleteTree();
}
template<class T>
BST<T>::BST(const BST<T> &copyBST){
    if(copyBST.root!=NULL){
        root = new treeNode<T>(copyBST.root->data,NULL,NULL,NULL);
        copyTree(copyBST.root,root);
    }
}
template<class T>
void BST<T>::addData(T data){
    if(root==NULL){
        root = new treeNode<T>(data, NULL, NULL, NULL);
    }
    else{
        addData(data, root);
    }
}
template<class T>
void BST<T>::addData(T data, treeNode<T> *curRoot){
    if(data > curRoot->data){
        if(curRoot->right!=NULL){
            addData(data,curRoot->right);
        }
        else{
            curRoot->right = new treeNode<T>(data, NULL, NULL, curRoot);
        }
    }
    else if(data < curRoot->data){
        if(curRoot->left!=NULL){
            addData(data,curRoot->left);
        }
        else{
            curRoot->left = new treeNode<T>(data, NULL, NULL, curRoot);
        }
    }
    else{
        std::cout << "Data " << data << " already exists in BST!\n";
    }
    
}
template<class T>
void BST<T>::deleteData(T data){
    if(root!=NULL)
        deleteData(data, root);
}
template<class T>
void BST<T>::deleteData(T data, treeNode<T> *curRoot){
    if(data > curRoot->data){
        if(curRoot->right!=NULL){
            deleteData(data,curRoot->right);
        }
        else{
            std::cout << "Data: " << data << " does not exist!\n";
        }
    }
    else if(data < curRoot->data){
        if(curRoot->left!=NULL){
            deleteData(data,curRoot->left);
        }
        else{
            std::cout << "Data: " << data << " does not exist!\n";
        }        
    }
    else{
        //Root Node
        if(curRoot->parent==NULL){
            //No Children
            if(curRoot->left == NULL && curRoot->right == NULL){
                delete root;
                root = NULL;
            }
            //1 Child
            else if(curRoot->left==NULL){
                treeNode<T> *replace = root->right;
                delete root;
                root = replace;
            }
            else if(curRoot->right==NULL){
                treeNode<T> *replace = root->left;
                delete root;
                root = replace;
            }
            //2 Children
            else{
                deleteNode2Children(root);
            }
        }
        //Leaf Node
        else if(curRoot->left == NULL && curRoot->right == NULL){
            treeNode<T> *parent = curRoot->parent;
            if(parent->left == curRoot){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            delete curRoot;
        }
        //Internal node with 1 child
        else if(curRoot->left == NULL){
            deleteNode1Child(curRoot,curRoot->right,curRoot->parent);
        }
        else if(curRoot->right == NULL){
            deleteNode1Child(curRoot,curRoot->left,curRoot->parent);
        }
        //Internal node with 2 children
        else{
            deleteNode2Children(curRoot);
        }
    }
}
template<class T>
void BST<T>::deleteNode1Child(treeNode<T> *deleteMe, treeNode<T> *replace, treeNode<T> *parent){
    if(parent->left == deleteMe){
        parent->left = replace;
    }
    else{
        parent->right = replace;
    }
    replace->parent = parent;
    delete deleteMe;
}
template<class T>
void BST<T>::deleteNode2Children(treeNode<T>* curRoot){
    treeNode<T> *replace = returnInorderPredescessor(curRoot);
    // Inorder predescessor has no children
    if(replace->left == NULL && replace->right == NULL){
        T temp = curRoot->data;
        curRoot->data = replace->data;
        replace->data = temp;
        if(replace->parent->left == replace){
            replace->parent->left = NULL;
        }
        else{
            replace->parent->right = NULL;
        }
        delete replace;
    }
    // Inorder predescessor has a child (MUST be a left child)
    else{
        //If it's parent is node to be deleted (simpler case)
        if(replace->parent == curRoot){
            treeNode<T> *right = curRoot->right;
            //Root
            if(curRoot->parent == NULL){
                delete curRoot;
                root = replace;
                root->parent = NULL;
                root->right = right;
            }
            else{
                treeNode<T> *parent = curRoot->parent;
                if(parent->left == curRoot){
                    delete curRoot;
                    parent->left = replace;
                }
                else{
                    delete curRoot;
                    parent->right = replace;
                }
                replace->parent = parent;
                replace->right = right;
            }
        }
        else{
            treeNode<T> *repPar = replace->parent;
            T temp = curRoot->data;
            curRoot->data = replace->data;
            replace->data = temp;
            treeNode<T> *repLeft = replace->left;
            repPar->right = repLeft;
            repLeft->parent = repPar;
            delete replace;
        }
    }
}
template<class T>
treeNode<T>* BST<T>::returnInorderPredescessor(treeNode<T>* curRoot){
    treeNode<T> *pred = curRoot->left;
    while(pred->right!=NULL){
        pred = pred->right;
    }
    return pred;
}
template<class T>
bool BST<T>::findData(T data){
    findData(data, root);
}
template<class T>
bool BST<T>::findData(T data, treeNode<T> *curRoot){
    if(curRoot==NULL){
        return false;
    }
    if(data > curRoot->data){
        findData(data, curRoot->right);
    }
    else if(data < curRoot->data){
        findData(data, curRoot->left);
    }
    else{
        return true;
    }
}
template<class T>
T BST<T>::findMin(){
    if(root==NULL)
        return 0;
    treeNode<T> *curRoot = root;
    while(curRoot->left!=NULL)
        curRoot = curRoot->left;
    return curRoot->data;
}
template<class T>
T BST<T>::findMax(){
    if(root==NULL)
        return 0;
    treeNode<T> *curRoot = root;
    while(curRoot->right!=NULL)
        curRoot = curRoot->right;
    return curRoot->data;    
}
template<class T>
void BST<T>::traverseBFS(){
    std::cout << "BFS: ";
    if(root==NULL){
        std::cout << "Tree Empty\n";
        return;
    }
    Queue< treeNode<T>* > q;
    q.enQueue(root);
    treeNode<T> *curNode = q.deQueue();
    while(curNode!=NULL){
        std::cout << curNode->data << " ";
        if(curNode->left!=NULL)
            q.enQueue(curNode->left);
        if(curNode->right!=NULL)
            q.enQueue(curNode->right);
        try{
            curNode = q.deQueue();
        }
        catch(EmptyQueue e){
            break;
        }
    }
    std::cout << std::endl;
}
template<class T>
void BST<T>::traverseDFSpreorder(){
    std::cout << "DFS preorder: ";
    if(root==NULL){
        std::cout << "Tree Empty\n";
        return;
    }
    traverseDFSpreorder(root);
    std::cout << std::endl;
}
template<class T>
void BST<T>::traverseDFSpreorder(treeNode<T> *curRoot){
    std::cout << curRoot->data << " ";
    if(curRoot->left!=NULL){
        traverseDFSpreorder(curRoot->left);
    }
    if(curRoot->right!=NULL){
        traverseDFSpreorder(curRoot->right);
    }
}
template<class T>
void BST<T>::traverseDFSinorder(){
    std::cout << "DFS inorder: ";
    if(root==NULL){
        std::cout << "Tree Empty\n";
        return;
    }
    traverseDFSinorder(root);
    std::cout << std::endl;
}
template<class T>
void BST<T>::traverseDFSinorder(treeNode<T> *curRoot){
    if(curRoot->left!=NULL){
        traverseDFSinorder(curRoot->left);
    }
    std::cout << curRoot->data << " ";
    if(curRoot->right!=NULL){
        traverseDFSinorder(curRoot->right);
    }
}
template<class T>
void BST<T>::traverseDFSpostorder(){
    std::cout << "DFS postorder: ";
    if(root==NULL){
        std::cout << "Tree Empty\n";
        return;
    }
    traverseDFSpostorder(root);
    std::cout << std::endl;
}
template<class T>
void BST<T>::traverseDFSpostorder(treeNode<T> *curRoot){    
    if(curRoot->left!=NULL){
        traverseDFSpostorder(curRoot->left);
    }
    if(curRoot->right!=NULL){
        traverseDFSpostorder(curRoot->right);
    }
    std::cout << curRoot->data << " ";
}
template<class T>
void BST<T>::printBranches(){
    std::cout << "BST Branches:\n";
    if(root==NULL){
        std::cout << "Tree Empty\n";
        return;
    }
    Queue< treeNode<T>* > q;
    q.enQueue(root);
    treeNode<T> *curNode = q.deQueue();
    while(curNode!=NULL){
        if(curNode->parent==NULL)
            std::cout << "NULL->";
        else
            std::cout << curNode->parent->data << "->";
        std::cout << curNode->data << "->(";
        if(curNode->left!=NULL){
            q.enQueue(curNode->left);
            std::cout << curNode->left->data << "|";
        }
        else{
            std::cout << "NULL|";
        }
        if(curNode->right!=NULL){
            q.enQueue(curNode->right);
            std::cout << curNode->right->data << ")";
        }
        else{
            std::cout << "NULL)";
        }
        std::cout << std::endl;
        try{
            curNode = q.deQueue();
        }
        catch(EmptyQueue e){
            break;
        }
    }
    std::cout << std::endl;
}
template<class T>
void BST<T>::deleteTree(){
    if(root!=NULL){
        deleteTree(root);
        root = NULL;
    }
}
template<class T>
void BST<T>::deleteTree(treeNode<T> *curRoot){
    if(curRoot->left!=NULL){
        deleteTree(curRoot->left);
    }
    if(curRoot->right!=NULL){
        deleteTree(curRoot->right);
    }
    delete curRoot;
}
template<class T>
BST<T> BST<T>::copyTree(){
    BST<T> copy;
    if(root!=NULL){
//        std::cout << "Copying Root: "<< root->data << std::endl;
        copy.root = new treeNode<T>(root->data,NULL,NULL,NULL);
        
        copyTree(root,copy.root);
    }
    return copy;
}
template<class T>
void BST<T>::copyTree(treeNode<T> *curRoot, treeNode<T> *newRoot){
    if(curRoot->left!=NULL){
//        std::cout << "Copying: " << curRoot->left->data << std::endl;
        newRoot->left = new treeNode<T>(curRoot->left->data,NULL,NULL,newRoot);
        copyTree(curRoot->left,newRoot->left);
    }
    if(curRoot->right!=NULL){
//        std::cout << "Copying: " << curRoot->right->data << std::endl;
        newRoot->right = new treeNode<T>(curRoot->right->data,NULL,NULL,newRoot);
        copyTree(curRoot->right,newRoot->right);
    }
}
#endif	/* BST_H */
