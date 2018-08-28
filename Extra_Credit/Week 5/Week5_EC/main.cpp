/*
Katrina Siegfried
CSCI 2270 - Data Structures
Week 5 - Extra Credit
main.cpp, bst_class.cpp, bst_class.h
*/



// include necessary libraries and namespaces
#include <fstream>				
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "bst_class.h"
using namespace std;


int main () {

	// define the class and the class member we will use to build our BST - myBST
	BST();
	BST myBST;


	/****************BUILD A TREE TO TEST TREE VALIDITY****************/
	/*	Comment/uncomment the lines below to use the addNode function to print
	 *	a BST of the form:
	 *
										6
									/	     \
								2				7
							  /   \				  \
							1		4				13
								  	  \			  /
										5		9
												  \
													11
	 *
	 *	used for testing and debugging.
	*/
	myBST.addNode(6);
	myBST.addNode(2);
	myBST.addNode(2);
	myBST.addNode(7);
	myBST.addNode(13);
	myBST.addNode(2);
	myBST.addNode(9);
	myBST.addNode(1);
	myBST.addNode(4);
	myBST.addNode(5);
	myBST.addNode(11);
	myBST.addNode(7);


	/****************BUILD A TREE TO TEST TREE VALIDITY****************/
	/*	Comment/uncomment the lines below to use the addNodeRecursive
	 *	function to print a BST of the form:
	 *
										6
									/	     \
								2				7
							  /   \				  \
							1		4				13
								  	  \			  /
										5		9
												  \
													11
	 *
	 *	used for testing and debugging.
	*/
	// myBST.addNodeRecursive(6);
	// myBST.addNodeRecursive(2);
	// myBST.addNodeRecursive(2);
	// myBST.addNodeRecursive(7);
	// myBST.addNodeRecursive(13);
	// myBST.addNodeRecursive(2);
	// myBST.addNodeRecursive(9);
	// myBST.addNodeRecursive(1);
	// myBST.addNodeRecursive(4);
	// myBST.addNodeRecursive(5);
	// myBST.addNodeRecursive(11);
	// myBST.addNodeRecursive(7);


	/**************BUILD A "BAD" TREE TO TEST TREE VALIDITY**************/
	/* Use a custom public function of the BST class to generate a bad
	 * tree of the form:
	 *				6
	 *			  /   \
	 *			8       4
	 *	Then, the root node will need to be retrieved (because it is a
	 *	private member of the BST class) using a public function called
	 *	getRoot, which generates a pointer to the root that can be
	 *	accessed from the main. The root will be passed to the print
	 *	function which will "print the nodes in order" to demonstrate
	 *	the tree is not  valid. Finally, the function isBSTValid is called
	 *	which will check is the tree is valid and return false (0) if
	 *	not valid, and true (1) if valid. Uncomment the following lines
	 *	to execute code.
	*/
	// BST badBST;
	// badBST.buildBadTree();
	// // in order print the bad tree
	// Node *rootNode = new Node;
	// rootNode = badBST.getRoot(badBST);
	// cout << "The root of badBST is: " << rootNode -> key << endl;
	// cout << "\nPRINT IN ORDER" << endl;
	// badBST.printNodesInOrder(rootNode);
	// // verify the tree is bad
	// bool valid = badBST.isBSTValid();
	// cout << "\nIs badBST a valid BST? " << valid << endl;


	/*************************PRINTING SCHEMES*************************/
	/*
	 *	Uncomment the lines below to print the BST using the three different
	 *	printing schemes. The print functions are preceeded by a getRoot function
	 *	that is a public member of the BST class that allows us to return a node
	 *	that points to the root which is private, and otherwise inaccessible from
	 *	the main.cpp file.
	*/
	// Node *rootNode = new Node;
	// rootNode = myBST.getRoot(myBST);
	// cout << "\nThe root node is: " << 
	// rootNode -> key << endl;
	// // in order
	// cout << "\nPRINT IN ORDER" << endl;
	// myBST.printNodesInOrder(rootNode);
	// // pre order
	// cout << "\nPRINT PRE ORDER" << endl;
	// myBST.printNodesPreOrder(rootNode);
	// // post order
	// cout << "\nPRINT POST ORDER" << endl;
	// myBST.printNodesPostOrder(rootNode);


	/**************************VERIFYING BST**************************/
	/*	Uncomment the following code to verify that a given BST built
	 *	using the built in functions is in fact a BST. Uses the public
	 *	function isValidBST and then a helper function which checks the
	 *	values in the tree against one another recursively.
	*/
	// bool valid = myBST.isBSTValid();
	// cout << "\nIs myBST a valid BST? " << valid << endl;


	/**************************DELETING NODES**************************/
	/*
	 *	Uncomment and modify the line below to delete one or more nodes
	 * 	the BST. The getRoot function will then be called to update the
	 *	root node and call the printing in order scheme to demonstrate
	 *	the node to be deleted has been removed.
	 */
	// myBST.deleteNode(6);
	// rootNode = myBST.getRoot(myBST);
	// cout << "The root is now: " << rootNode -> key << endl;
	// cout << "\nPRINT IN ORDER" << endl;
	// myBST.printNodesInOrder(rootNode);


	/****************************BST HEIGHT****************************/
	/*
	 *	Uncomment the following lines below to retriee and then print out the
	 * 	height of the BST.
	*/
	// int height = myBST.getBSTheight();
	// cout << "\nThe height of the tree is: " << height << endl;


	return 0;
}