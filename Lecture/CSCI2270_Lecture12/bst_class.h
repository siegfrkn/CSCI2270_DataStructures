//
//  bst_class.hpp
//  
//
//  Created by cami on 6/26/18.
//
//

#ifndef bst_class_h
#define bst_class_h

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
    int key = -1;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

class BST {
private:
    Node* root = nullptr;
    Node* createNode(int,Node*,Node*,Node*);
    Node *search(Node*,int);
    
public:
   BST();
    ~BST();
    bool addNode(int);
    void printNodesInOrder(Node* startNode);
    void printNodesPostOrder(Node* startNode);
    void printNodesPreOrder(Node* startNode);
};


#endif 


/* bst_class_hpp */