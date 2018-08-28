//
//  RBT.hpp
//  
//
//  Created by cami on 7/3/18.
//
//

#ifndef RBT_h
#define RBT_h

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
    int key = -1;
    bool isRed;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

class RBT {
private:
    Node* root, nullnode; // nullnode is the sentinel
    Node* createNode(int,string,Node*,Node*,Node*);
    Node* insertNode(int); // returns the node
    
    
public:
    RBT();
    ~RBT();
    
    
    bool balancedInsertNode(int);
    // Use this already implemented function to check if the tree is valid
    // after every insertion!
    int  rbValid(Node*);
    void leftRotate(Node*);
    void rightRotate(Node*);
    // Implement and use this function to print out your trees
    void printNodesInOrder(Node* nodeToPrint);

};



#endif /* RBT_hpp */
