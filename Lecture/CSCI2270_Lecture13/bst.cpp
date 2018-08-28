//#include <stdio.h>
//#include <iostream>

using namespace std;

#include "bst_class.h"


BST::BST() { // go to BST and access BST
	Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
}

BST::~BST(){
	Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
}

Node *BST::createNode(int value, Node *parent, Node *left, Node *right) { //go to the BST class and access the function createNode
	// as soon as i instantiate it will have left and right set to nullptr
	Node *newNode = new Node;
	newNode -> key = value;
	newNode -> parent = parent;
	newNode -> left = left;
	newNode -> right = right;

	return newNode;
}


bool BST::addNode(int value){

	Node *tmpNode = root;
	Node *curParent = nullptr;
	
	// if there is nothing in the tree...
	if (!root){
		root = createNode(value, nullptr, nullptr, nullptr);
		cout << "new root created" << endl; // for debug purposes, not needed or encouraged
		return false;;
	}

	// traverse the tree and find the correct place
	// think while loop - while I don't reach the bottom of my tree
	while (tmpNode != nullptr) {
		// set the current parent
		curParent = tmpNode; // fundamental for the logic below
		// will be the parent of our new child
		if(value > tmpNode -> key) {
			tmpNode = tmpNode -> right;
		}
		else {
			tmpNode = tmpNode -> left;
		}

	}
	// When found the right parent to add the child to the new child either
	// to the left or to the right

	// if null?
	if (curParent == nullptr){
		root = createNode(value, nullptr, nullptr, nullptr);
	}

	// else add it to the left
	else if (value < curParent -> key){
		curParent -> left = createNode(value, curParent, nullptr, nullptr);
	}
	// else add it to the left
	else if (value < curParent -> key){
		curParent -> right = createNode(value, curParent, nullptr, nullptr);
	}


	return true;
}


void BST::printNodesInOrder(Node *nodeToPrint) {
	if (nodeToPrint){
		if (nodeToPrint -> left) {
			printNodesInOrder(nodeToPrint -> left);
		}
		cout << nodeToPrint -> key << endl;
		if (nodeToPrint -> right) {
			printNodesInOrder(nodeToPrint -> right);
		}
	}
}

void BST::printNodesPostOrder(Node *nodeToPrint) {
	if (nodeToPrint){
		cout << nodeToPrint -> key << endl;
		if (nodeToPrint -> left) {
			printNodesInOrder(nodeToPrint -> left);
		}
		if (nodeToPrint -> right) {
			printNodesInOrder(nodeToPrint -> right);
		}
	}
}

void BST::printNodesPreOrder(Node *nodeToPrint) {
	if (nodeToPrint){
		if (nodeToPrint -> left) {
			printNodesInOrder(nodeToPrint -> left);
		}
		if (nodeToPrint -> right) {
			printNodesInOrder(nodeToPrint -> right);
		}
		cout << nodeToPrint -> key << endl;
	}
}



Node *BST::search(Node *searchNode, int valueToDelete) {
	if (root) {
		if (searchNode -> key > valueToDelete && root -> left){
			return search(root -> left, valueToDelete);
		}
		else if (searchNode -> key < valueToDelete && root -> right) {
			return search(root -> right, valueToDelete);
		}
		else if (searchNode -> key == valueToDelete) {
			return searchNode;
		}
		else {
			return NULL;
		}
	}

	return NULL;
}



Node *BST::deleteNode(int deleteValue){
	if (root){
		Node *nodeToDelete = search(root, deleteValue);
		if (nodeToDelete) {
			// do I have any children nodes
			if (!nodeToDelete -> left && !nodeToDelete -> right){
				nodeToDelete -> parent = NULL;
				cout << "Leaf Node Deleted" << endl;
				delete nodeToDelete;
			}
			// if not, what?
			// if yes, how many?
			// if 
				// 1?
					// is it left?
					// is it right?
				// 2?
		}
	}
	


	return root;
}

// if node has no children - easiest case