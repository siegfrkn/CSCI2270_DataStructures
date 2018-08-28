//
//  bst_class.hpp
//  
//
//  Created by cami on 6/26/18.
//  Edited by Katrina on 7/6/2018
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

    // !! TO DO: what do you need to implement as well to cover all the cases?
    //    HINT: would it be useful if we had a way to find min and max? -> YES!! Implement them
    Node* minNode(Node*);
    Node* maxNode(Node*);

    Node *deleteNode(int);
    
    // !! TO DO
    bool addNodeRecursive(int);
    
    // !! TO DO: is the BST a valid tree? Who knows maaaaaan! Check it out
    bool isBSTValid();
    
    // !! TO DO: is the BST a valid tree? Who knows maaaaaan! Check it out
    int getBSTheight();

    // Left, Root, Right
    void printNodesInOrder(Node* nodeToPrint);
    // Left, Right, Root
    void printNodesPostOrder(Node* nodeToPrint);
    // Root, Left, Right
    void printNodesPreOrder(Node* nodeToPrint);

    // helper function for addNodeRecursive
    bool checkTree(Node*, int);

    // allows user to obtain pointer to root outside of BST class
    Node *getRoot(BST);

    // for demo purposes only, builds a "bad" tree for testing
    bool buildBadTree();

    // finds the number of elements in the tree and returns it
    int sizeTree(Node*, int, int, int);

    // helper function for isBSTValid
    bool isBSTValidHelper(Node*);
};


#endif 


/* bst_class_hpp */
