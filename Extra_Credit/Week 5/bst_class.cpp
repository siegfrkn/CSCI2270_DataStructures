//
//  bst_class.cpp
//
//
//  Created by cami on 6/26/18.
//  Edited by Katrina on 7/6/18
//
// This is a starter which implements some features that a tree can have!

// For Extra Credit complete the remaining funtions in the bst_class.h and all the TO DO that you find
// in this file.
// Where to find the TO DOs?
// 1) inside BST()
// 2) inside ~BST()
// 3) inside addNode()
// 4) check out .h file and you'll find the remaining TO DOs.


// include necessary libraries and standard namespace
#include <fstream>                                                         
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// include the header file
#include "bst_class.h"


// define our default constructor
BST::BST() {
    
    // !! TO DO: what can we do here?
    root = NULL; // don't want our tree pointing to anything when it is created
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
}

// define our default destructor
BST::~BST() {
    
    // !! TO DO: what can we do here?
    root = NULL; // don't want our tree pointing to anything when we remove it
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
}

// use this function to assign parameters to a new node in the BST, return the node
Node* BST::createNode(int itemToAdd, Node* parentNode, Node* leftChild, Node* rightChild) {
    Node* newNode = new Node;
    newNode->key = itemToAdd;
    newNode->parent = parentNode;
    newNode->left = leftChild;
    newNode->right = rightChild;
    return newNode;
}


// use this function to add nodes to the BST
bool BST::addNode(int value) {
    Node* tmpNode = root;
    Node* curParent = nullptr;
    // Traverse the tree and find correct place
    while(tmpNode != nullptr)
    {
        // Set the "possible future" caring Parent
        curParent = tmpNode;
        if(value > tmpNode->key)
        {
            tmpNode = tmpNode->right;
        }
        else
        {
            tmpNode = tmpNode->left;
        }
        // !! TO DO: What if the value is already in the tree?
        // If the value is already in the tree we do NOT add it
        if(curParent -> key == value){
            cout << "Node NOT added, value already in tree" << endl; // debug statement
            return false; // returns false when the node is not added
        }
    }
    // !! TO DO: it is not great practice to print out stuff in methods that have other purposes,
    //           however, for debugging and checks it is usefull (especially in dev enviornments).
    //           Print out meaningful information after "meaningful" actions are performed.
    // When found the right parent to add the new child to, add the new child either to the left or the right
    // Wait wait wait...... what if null?
    if (curParent == nullptr) {
        root =  createNode(value, nullptr, nullptr, nullptr);
        cout << "\nNEW TREE CREATED:\nvalue added as root node in BST: " << value <<  endl;
    }
    // Ok phew it's not null, now what? should it go right or left?
    else if (value < curParent->key)
      // else if (value > curParent->key)
    {
        curParent->left =  createNode(value, curParent, nullptr, nullptr);
        cout << "Node added as left child: " << value << endl;
    }
    else
    {
        curParent->right = createNode(value, curParent, nullptr, nullptr);
        cout << "Node added as right child: " << value << endl;
    }
    return true; //  needs to return true if the node was added
}


// Now we dive into hard core good recursion, understand it by creating simple trees
// print BST in order from least to greatest (according to rules of our BST)
void BST::printNodesInOrder(Node* nodeToPrint) {
    if(nodeToPrint) {
        if(nodeToPrint->left) {
            printNodesInOrder(nodeToPrint->left);
        }
        cout<<nodeToPrint->key<<endl;
        if(nodeToPrint->right) {
            printNodesInOrder(nodeToPrint->right);
        }
    }
    return;
}

// print BST preorder
void BST::printNodesPostOrder(Node* nodeToPrint) {
    if(nodeToPrint) {    
        cout<<nodeToPrint->key<<endl;
        if(nodeToPrint->left)
            printNodesInOrder(nodeToPrint->left);
        if(nodeToPrint->right)
            printNodesInOrder(nodeToPrint->right);
    }
    return;
}

// print BST post order
void BST::printNodesPreOrder(Node* nodeToPrint) {
    
    if(nodeToPrint) {
        
        if(nodeToPrint->left)
            printNodesInOrder(nodeToPrint->left);
        
        
        if(nodeToPrint->right)
            printNodesInOrder(nodeToPrint->right);
        
        cout<<nodeToPrint->key<<endl;
        
    }
    
    return;
}

// I had to fix the search function
// This searches for a value in the BST given a starter node and returns the root
Node* BST::search(Node* searchNode, int value) {
    // Sanity check
    if(root) {
        if(searchNode->key == value){
            return searchNode;
        }
        else if(searchNode->key > value && searchNode->left){
            return search(searchNode->left, value);
        }
        else if(searchNode->key < value && searchNode->right){
            return search(searchNode->right, value);
        }
        else{
            return NULL;
        }
    }
    return root;
}

// This deletes a node from the BST and covers ALL base cases, returns root;
Node* BST::deleteNode(int value) {
    // Sanity check
    // check to make sure there is a list before we do anything
    if(root) {
        // DO GOOD STUFF!!
        cout << "\nNode to be deleted: " << value << endl;
        Node* nodeToDelete = search(root, value);
        if(nodeToDelete != root) {
            // DO I have children???
            // NO children
            if (!nodeToDelete->left && !nodeToDelete->right) {
                if (nodeToDelete-> parent -> left){
                    nodeToDelete-> parent -> left = NULL;
                }
                else if (nodeToDelete -> parent -> right) {
                    nodeToDelete-> parent -> right = NULL;
                }
                cout<<"\nLeaf node deleted\n"<<endl;
                delete nodeToDelete;
                return root;
            }
            // If yes how many? andddddd, do they have children as well? how do you deal with that?
            // 2 CHILDREN
            else if (nodeToDelete->left && nodeToDelete->right){
                // get the min to the right of nodeToDelete
                Node *min = minNode(nodeToDelete->right);
                // if min is the right child of the nodeToDelete
                if (min == nodeToDelete -> right) {
                    // is nodeToDelete a left child of anything?
                    // if (nodeToDelete -> parent -> left == nodeToDelete){
                        nodeToDelete -> parent -> left = min;
                        min -> parent = nodeToDelete -> parent;
                        min -> left = nodeToDelete -> left;
                        min -> left -> parent = min;
                    }
                    // nodeToDelete is a right child of anything
                else{
                    min -> parent -> left = min -> right;
                    min -> right -> parent = min -> parent;
                    min ->parent = nodeToDelete -> parent;
                    nodeToDelete -> parent -> left = min;
                    min -> left = nodeToDelete -> left;
                    min -> right = nodeToDelete -> right;
                    nodeToDelete -> right -> parent = min;
                    nodeToDelete -> left -> parent = min;
                }
                delete nodeToDelete;
                return root;
            }
            // 1 CHILD
            else {
                // Is it a single left child?
                if (nodeToDelete -> parent -> left == nodeToDelete){
                    // if nodeToDelete has a left child, rewire
                    if (nodeToDelete->left){
                        nodeToDelete -> parent -> left = nodeToDelete -> left;
                    }
                    else if (nodeToDelete -> right){
                        nodeToDelete -> parent -> left = nodeToDelete -> right;
                    }
                }
                // Is it a single right child?
                else{
                    if (nodeToDelete -> left){
                        nodeToDelete -> parent -> right = nodeToDelete -> left;
                    }
                    else if (nodeToDelete -> right){
                        nodeToDelete -> parent -> right = nodeToDelete -> right;
                    }
                }
                delete nodeToDelete;
                return root;
            }
                // delete nodeToDelete;
        }
        //we are deleting the root!
        else{
            // if there is only the root in the tree
            if (!nodeToDelete -> right && !nodeToDelete -> left){
                root = NULL;
                delete nodeToDelete;
                return root;
            }
            // 2 CHILDREN
            else if (nodeToDelete->left && nodeToDelete->right){
                // get the min to the right of nodeToDelete
                Node *min = minNode(nodeToDelete->right);
                cout << "Min to right is: " << min -> key << endl;
                // if min is the right child of the nodeToDelete
                if (min == nodeToDelete -> right) {
                    root = min;
                    min -> parent = NULL;
                    nodeToDelete -> left -> parent = min;
                    min -> left = nodeToDelete -> left;
                }
                    // nodeToDelete is a right child of anything
                else{
                    root = min;
                    // if stuff is connected to min right, reconnect it to list
                    if (min -> right) {
                        min -> right -> parent = min -> parent;
                    }
                    min -> parent -> left = min -> right;
                    min -> parent = NULL;
                    // nodeToDelete -> left -> parent = min;
                    min -> left = nodeToDelete -> left;
                    // if the root has stuff on the left, reconnect it
                    if (nodeToDelete -> left) {
                        nodeToDelete -> left -> parent = min;
                    }
                    min -> right = nodeToDelete -> right;
                    // if the root has stuff on the right, reconnect it
                    if (nodeToDelete -> right) {
                        nodeToDelete -> right -> parent = min;
                    }
                }
                delete nodeToDelete;
                return root;
            }
            // 1 CHILD
            else if (nodeToDelete -> right || nodeToDelete -> left) {
                // Is it a single left child?
                // if nodeToDelete has a left child, rewire
                if (nodeToDelete-> left){
                    nodeToDelete -> left -> parent = NULL;
                    root = nodeToDelete -> left;
                }
                // if the node has a right child, rewire
                else if (nodeToDelete -> right){
                    nodeToDelete -> right -> parent = NULL;
                    root = nodeToDelete -> right;
                }
                delete nodeToDelete;
                return root;
            }
        }
    }
    else {
        cout << "\nBST is empty\n" << endl;
    }
    return root;
}


// this is a helper function for addNodeRecursive that checks the value at
// all the nodes in the tree to find where to add
bool BST::checkTree(Node* node, int value){
    if (root){
         if (node -> key < value ) {
            if (node -> right){
                checkTree(node->right, value);
            }
            else{
                node -> right = createNode(value, node, nullptr, nullptr);
                cout << "Value added recursively: " << value << endl;
                return true;
            }

         }
         if (node -> key > value) {
            if (node -> left) {
                checkTree(node -> left, value);
            }
            else{
                node -> left = createNode(value, node, nullptr, nullptr);
                cout << "Value added recursively: " << value << endl;
                return true;
            }
        }

    }
        return false;
}


// this function uses recursion to add a node to the tree
bool BST::addNodeRecursive(int value){
// TO DO: add helper functions if you need them
    if (!root) {
        root =  createNode(value, nullptr, nullptr, nullptr);
        cout << "Root added recursively: " << value << endl;
        return true;
    }
    checkTree(root, value);
    
    return true;
}

// this function finds the number of nodes in the tree and returns it
int BST::sizeTree(Node* node, int count, int countL, int countR){
    if (!root){
        return 0;
    }
    else if(!node -> left && !node -> right){   
        return 1;
    }  
    else if (node -> left && node -> right) {
        if (node -> left){
            countL =sizeTree(node -> left, count, countL, countR);
        }
        count = 1 + countL;
        if (node -> right){
            countR = sizeTree(node -> right, count, countL, countR); 
        }
        count = count + countR;
        cout << count << endl;
        return count;
    }
    return count;
}

// this is the helper function for the isBSTValid function. Similar to checkTree
// it recursively iterates through the BST and checks values, returns false if
// nodes aren't where they are supposed to be
bool BST::isBSTValidHelper(Node *root) {
    if (root){
        if (root -> right){
             if (root -> key < root -> right -> key ) {
            isBSTValidHelper(root->right);
            }
            else{
                return false;
            }
        }
        if (root -> left) {
            if (root -> key > root -> left -> key) {
                isBSTValidHelper(root -> left);
            }
            else{
                return false;
            }
        }
    }
    return true;
}

// this function uses a recursive helper function to check to see if the BST
// is in fact a BST according to our rules.
bool BST::isBSTValid(){
// // private method for sanity check, call on a tree if you implement another helper function and you want to check
// // add a "bad" node as a bad test case to the right or left of a certain node
// // TO DO: implementation and comment on why we don't need to pass anything to this method
// // We don't need to pass anything to this method because we will iterate from root and root is a private
// // member of the BST class and we can access directly from within isBST which is also in the BST class.
// // Private class members can only be accessed by public class members.
// TO DO: add helper functions if you need them
    if (!root) {
        cout << "Tree is Empty" << endl;
        return true;
    }
    return isBSTValidHelper(root);
}


// this function uses recursion to get the height of the BST
int BST::getBSTheight() {
// TO DO: implementation and comment on why we don't need to pass anything to this method
// The resdon we don't need to pass anything in this method is because this method is a member of the BST class
// so it can call the private BST class member root directly from the function.
    int leftMax = 1;
    int rightMax = 1;
    // Sanity check
    if(root) {
        while (root -> left){
            root = root -> left;
            leftMax = getBSTheight();
        }
        while (root -> right){
            root = root -> right;
            rightMax = getBSTheight();
        }
    }
    else {
        return 0;
    }
    return (1+max(leftMax, rightMax));
}


// this function allows the user to get a pointer to the root node of the BST outside of the BST class because
// the node is private.
Node* BST::getRoot(BST bst){
    Node *rootNode = bst.root;
    return rootNode;
}


// this function gets the minimum value from the BST
Node* BST::minNode(Node* min){
    Node *current = min;
    while (current -> left != NULL){
        if (current -> key > current -> left -> key){
            current = current -> left;
        }
    }
    return current;
}


// this function gets the maximum value from the BST
Node* BST::maxNode(Node* max){
    Node *current = max;
    while (current -> right != NULL){
        if (current -> key < current -> right -> key){
            current = current -> right;
        }
    }
    return current;
}


// This function is for demo purposes and builds a "bad" tree
bool BST::buildBadTree(){
    root =  createNode(6, nullptr, nullptr, nullptr);
    root -> right = createNode(4, root, nullptr, nullptr);
    root -> left = createNode(8, root, nullptr, nullptr);
    return true;
}