// include necessary libraries and standard namespace
#include <fstream>                                                         
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// include the header file
#include "MovieTree.h"

// define our default BST constructor
MovieTree::MovieTree() {
	root = nullptr;
	// parent = nullptr;
 //    leftChild = nullptr;
 //    rightChild = nullptr;
 //    head = nullptr;
 //    root = nullptr;
};

// define our default destructor
MovieTree::~MovieTree() {
	root = nullptr;
	// parent = nullptr;
 //    leftChild = nullptr;
 //    rightChild = nullptr;
 //    head = nullptr;
}



//use this for the post-order traversal deletion of the tree
void MovieTree::DeleteAll(MovieNodeBST * node) {
    if(node) {
    	node -> parent = NULL;
    	delete node;
	    if(node->leftChild){
	        printMovieInventory(node->leftChild);
	    }
	    if(node->rightChild){
	        printMovieInventory(node->rightChild);
	    }
    }
    return;
}



void MovieTree::printMovieInventory(MovieNodeBST * node) {
	if(node) {
        if(node->leftChild) {
            printMovieInventory(node->leftChild);
        }
        cout<<node->letter<<endl;
        if(node->rightChild) {
            printMovieInventory(node->rightChild);
        }
    }
    return;
}




// void MovieTree::countMovieNodes(MovieNodeBST *node, int *c);
// MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title); //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
// MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title); //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
// MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node); //use this to find the left most leaf node of the BST, you'll need this in the delete function


void MovieTree::printMovieInventory() {
	printMovieInventory(root);
}






// int MovieTree::countMovieNodes();
// void MovieTree::deleteMovieNode(std::string title);



// this is a helper function for addNodeRecursive that checks the value at
// all the nodes in the tree to find where to add
bool MovieTree::checkTree(MovieNodeBST* node, string title){
    if (root){
         if (node -> letter < title[0] ) {
            if (node -> rightChild){
                checkTree(node->rightChild, title);
            }
            else{
                node -> rightChild = createNodeBST(title[0], node, nullptr, nullptr, nullptr);
                cout << "Value added recursively: " << title << endl;
                return true;
            }

         }
         if (node -> letter > title[0]) {
            if (node -> leftChild) {
                checkTree(node -> leftChild, title);
            }
            else{
                node -> leftChild = createNodeBST(title[0], node, nullptr, nullptr, nullptr);
                cout << "Value added recursively: " << title << endl;
                return true;
            }
        }

    }
        return false;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) {
    if (!root) {
        root =  createNodeBST(title[0], nullptr, nullptr, nullptr, nullptr);
        cout << "Root added recursively: " << title << endl;
        // return true;
    }
    checkTree(root, title);
    
    // return true;
}



// void MovieTree::findMovie(std::string title);
// void MovieTree::rentMovie(std::string title);
// MovieNodeBST* MovieTree::minNode(MovieNodeBST*);
// MovieNodeBST* MovieTree::maxNode(MovieNodeBST*);

MovieNodeBST* MovieTree::createNodeBST(char letter, MovieNodeBST *parent, MovieNodeBST *leftChild, MovieNodeBST *rightChild, MovieNodeLL *head) {
   	MovieNodeBST *myBSTNode = new MovieNodeBST;
    myBSTNode -> letter = letter;
    myBSTNode -> parent = parent;
    myBSTNode -> leftChild = leftChild;
    myBSTNode -> rightChild = rightChild;
    myBSTNode -> head = head;
    return myBSTNode;
}

// MovieNodeLL* BST::createNodeLL(string title, int ranking, int year, int quantity, MovieNodeLL *next) {
//     MovieNodeBST * newNode = new MovieNodeBST;
//     newNode -> ranking = ranking;
//     newNode -> title = title;
//     newNode -> year = year;
//     newNode -> quantity = quantity;
//     newNode -> next = next;
//     return newNode;
// }


