//
//  RBT.cpp
//  
//
//  Created by cami on 7/3/18.
//
//

#include "RBT.h"

/*
The purpose of this extra credit is to have you work more on RBT and gain a better understanding on their application
 
 
Let's start off with a recap on RBTs
 
-- FIRST, WHY????
This feels such a time consuming and complex logic!
Nope, it's a lottery maker for future "transactions"! The shortest is a tree the faster is our time search.
 
-- SECOND, WHAT ARE THE STEPS TO FOLLOW?    
The idea is that we want to create a very specific BST so when we start building our ADT we insert data
as if we were to deal with a normal BST.    

Now the fun part, we need to balance! 

-- What can go wrong when we insert a new coloured node into a RBT?
We can violate one of the rules that make a RBT!

 
                    REMEMBER THE RULES OF A RBT:
 
                    1. A node is either red or black.
                    2. The root and NIL-descendants are black.
                    3. If a node is red, then its children are black.
                    4. All paths from a node to its NIL-descendants 
                       contain the same number of black nodes.


-- How many cases can we come across?
3
 
-- What are these?
Wellll, it's mostly based on the colour of the "uncle". Let's see let's see.
 
CASE 1: UNCLE IS RED
 1) Recolor Parent, Uncle and Grandparent
 2) Move up and recolour (aka, repeat for the new current node x = x->parent->parent until you reach root)

CASE 2: UNCLE IS BLACK AND RIGHT CHILD
 1) Go up to the father x = x->parent
 2) Left rotate around x
 3) Now you are in CASE 3

CASE 3: UNCLE IS BLACK AND LEFT CHILD
 1) Recolour parent and grandpa (aka x->parent->colour = black and x->parent->parent->colour = red)
 2) Right rotate around grandpa (x->parent->parent)


 */




/* !!   !!  !!  WHAT YOU HAVE TO DO:

    COMPLETE THE TO DOs AND WRITE YOUR TEST CASES IN YOUR MAIN FILE, BE SURE TO WRITE EXHAUSTIVE TEST CASES
 
 */


// TO DO: initialize root and nullnode
RBT::RBT()
{
    // Starter code for nullnode
    nullnode = createNode();

    // Starter code for root
    root = createNode();
}

RBT::~RBT()
{
    
}

// TO DO: read the questions and answer. Then act accordingly, meaning, when you create a new node
//        create it correctly
Node* RBT::createNode(int value, bool colour, Node* l, Node* r,Node* p)
{
    /* When you create a real new node what will be its left and right child? NULLNODES
        What about its colour?? RED (what does that mean in bool world?)
     */
    
    /* When you create a NULLNODE what will it be its left and right child??
         What about its colour??
     */
    
    Node *newNode = new Node;
    newNode->key = value;
    newNode->isRed = color;
    newNode->left = l;
    newNode->right = r;
    newNode->parent = p;
    
    return newNode;
    
}

// TO DO: just use what you implemented in your normal BST
Node* RBT::insertNode(int)
{
    
    
}


bool RBT::balancedInsertNode(int value)
{
    Node* x = insertNode(value);
    
    // Check if tree is valid
    bool isValid = rbValid(x);
    
    // TO DO: Time to balance! Comment your code and tell me what you are doing. Use your left and right rotate
    
}


// ALARM ALARM, HELPER FUNCTION!!!
// Returns 0 if the tree is invalid, otherwise returns the black node height.
int RBT::rbValid(Node * node)
{
    int lh = 0;
    int rh = 0;
    
    // If we are at a nil node just return 1
    if (node == nullnode)
        return 1;
    
    else
    {
        // First check for consecutive red links.
        if (node->isRed)
        {
            if(node->left->isRed || node->rightChild->isRed)
            {
                cout << "This tree contains a red violation" << endl;
                return 0;
            }
        }
        
        // Check for valid binary search tree.
        if ((node->left != nullnode && node->left->key > node->key) || (node->right != nullnode && node->right->key<node->key < 0))
        {
            cout << "This tree contains a binary tree violation" << endl;
            return 0;
        }
        
        // Deteremine the height of let and right children.
        lh = rbValid(node->left);
        rh = rbValid(node->right);
        
        // black height mismatch
        if (lh != 0 && rh != 0 && lh != rh)
        {
            cout << "This tree contains a black height violation" << endl;
            return 0;
        }
        
        // If neither height is zero, incrament if it if black.
        if (lh != 0 && rh != 0)
        {
            if (node->isRed)
                return lh;
            else
                return lh+1;
        }
        
        else
            return 0;
        
    }
}


// TO DO: COMPLETE and FIX this code
void RBT::leftRotate(x) {
    
    y = x->right;
    x->right = y->left;
    y->left->parent = x;
    y->parent = x->parent;
    
    
    if (x->parent == nullptr)
            root = y;
    else
    {
        // We need to understand if x is a left or a right child
        if(x == x->parent->left)
             x->parent->left = y;
        else
            x->parent->right = y;
    }
    
    // Set final links between x and y
    y->left = x;
    x->parent = y;
}

// TO DO: implement the right rotation
void RBT::rightRotate(y) {
    
    
}
