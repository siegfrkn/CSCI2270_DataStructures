#include <stdio.h>
//#include bst_class.hpp
#include "myBST.hpp"

int main(){
	//BST *binarysearchTree....

	return 0;
}



BST::BST() { // go to BST and access BST

}

BST::~BST(){

}

Node *BST::createNode(int value) { //go to the BST class and access the function createNode
	Node *myNode = new Node; // as soon as i instantiate it will have left and right set to nullptr
	myNode -> key = value;
}


void BST::createNode(int value) {
	Node *newNode = createNode(value);
	
	// if there is nothing in the tree...
	if (!root){
		root = newNode;
		cout <, "new root created" << endl; // for debug purposes, not needed or encouraged
		return;
	}

	Node *traverseNode = root;

	// FYI THIS IS NOT COMPLETE ADDNODE
	// is traverseNode -> key > value?
	if (traverseNode->key > value && != traverseNode->right){ // not going to add this node to the left of this value but let's see if there is a node there
		traverseNode->right = newNode;
	}
		// is traverseNode -> key < value?
	if (traverseNode->key < value && != traverseNode->left){ // not going to add this node to the right of this value but let's see if there is a node there
		traverseNode->right = newNode;
	}

	// does it have a right child
	if (traverseNode->right){ // more data safe than  == or !=

	}
}


void insertNode (Node *root, int data)
{
	if (root == NULL){
		Node * n = new Node();
		// create new node
		if (data < root -> key){
			// insert the node at the end of the search tree
		}
	}
}


int main{
	
	return 0
}



/* THIS IS MY HEADER */
#ifndef myBST_hpp // need a compiling time while
#define myBST_hpp

#include <stdio.h>

using namespace std;


struct Node{
	int key;
	Node *left;
	Node *right;
	Node() {
		key = -;
		left = nullptr;  // data type safe, vs NULL is ambiguous and translated as 0
		right = nullptr;
	}
};

class BST {
private: // accessible only to me
	Node *root = nullptr;
	Node *createNode(int key); // only I need to access createNode so it goes here
public:
	BST();
	~BST();

	void addNode(int value);
	// can use root in my addNode
protected: // inheritble to children but not to other classes

};

class child: BST{
public:
	void useAdd(); // this function will ne aware of addnode
	// does not have access to root - does not have 
}




//quiz key: bingo
// check out Xcode and download
// hpp is another way to say h - its a header file
// macros - static predefined things such that the compiler will quickly go over - templates
// don't put a main in a header file - it's where you define stuff

/*
g++ -std=c++11 myBST.cpp main.cpp

*/

// does not match declaration error - not defined the same way in the header file that it is used in the main file