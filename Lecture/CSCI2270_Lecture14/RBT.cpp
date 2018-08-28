// RBT.cpp

#include "RBT.h"

RBT::RBT::(){

}
RBT::~RBT::(){
	
}

// bool would be better
Node * BT::createNode(int value, string color Node *l, Node *r, Node *p){
	Node *newNode = new Node;
	newNode -> key = value;
	newNode -> color = color;
	newNode -> left = l;
	newNode -> right = r;
	newNode -> parent = p;

	// null node
// need to implement this better
// CAMILLA WILL POST EXTRA CREDIT REGARDING THIS
//Node *nullNode = createNode(NULL, "BLACK", nullptr, nullptr, nullptr){
// allocate one nullNode (a black fountain) to where all the leaf nodes will pooint
// does not "look" as pretty but serves the same purpose
//createnode(5, "RED", nullNNode, NullNode, NullNode);
// a null node will always be black
}



void RBT::leftRotate(x){
	y = x-> rightChild;
	x-> rightChild = y-> leftChild;
	if (y -> leftChild != nullNode){
		y-> leftChild -> parent = x;
	}
	y ->parent = x->parent;
	// are you the root?
	if (x->parent == nullptr){
		root = y;
	}
	else {
		// we need to understand if x is a left or a right child
		if (x == x -> parent -> leftChild){
			x -> parent -> leftChild = y;
		}
		else{
			x -> parent -> rightChild = y;
		}
	}
	// set final links between x and y
	y -> leftChild = x;
	x -> parent  = y;
}


bool RBT::balanceInsert(int value){
	Node *newNode = insertNode(value);
	// basically calling my new node using the logid left right bigger smaller
	// this node will be placed with respect to size - but it has a color
	// because every new node in a red-black tree will be red
	// several cases
	// 1. color of the uncle - red
		// recolor uncles black
		// call function recursively until all above nodes are black
		// know it is violation by calling parent -> color && parent -> parent -> child -> color and checking color
	// 2. color of the uncle - black
		// the node itself and the parents are red, uncle is black
		// left rotate - and will have two red's in a row
		// will then need to rebalance
	// 3. BRT Violation Case 3: Black Uncle
		// parent and grandparent recolor
		// right rotate x.parent.parent
		// remember you will always have a "nonChild" instead of nothing, that will ALWAYS BE BLACK!
}