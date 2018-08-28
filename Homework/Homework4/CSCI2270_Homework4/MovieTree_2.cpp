// include necessary libraries and standard namespace
#include <fstream>                                                         
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctype.h>
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


MovieNodeBST* MovieTree::readInFileFunc(string fileNameString, MovieTree myMovieTree){
	string word, line;	
	bool test = false;											// define the string variable line
	// string fileNameString = argv; 							// read in the message.txt file
	ifstream fileStreamString(fileNameString);
	if (!fileStreamString.is_open()){							// spit out an erro if it doesn't open
		cout << "Ignore Words file failed to open." << endl;
	}

	while(fileStreamString.good()){
		getline(fileStreamString, line, '\n');
		// build a linked list node, pass the entire line to the helper function
		LLhelperFunction(line);

		if (fileStreamString.eof()){							// check to see if the file is at he end
				break;												// break;
			}
	}

	fileStreamString.close();									// close the file when we are done with it
	cout << "\n \n" << endl;
	return root;
}



// this is a helper function for addNodeRecursive that checks the value at
// all the nodes in the tree to find where to add
bool MovieTree::checkTree(MovieNodeBST* node, char *title){
    if (root){
         if (node -> letter < *title ) {
            if (node -> rightChild){
            	// if value is already in the tree, start a linked list
                checkTree(node->rightChild, title);
            }
            else{
            	MovieNodeLL *head = NULL;
                node -> rightChild = createNodeBST(*title, node, nullptr, nullptr, head);
                // cout << "Value added recursively: " << title << endl;
                return true;
            }

         }
         if (node -> letter > title[0]) {
            if (node -> leftChild) {
                checkTree(node -> leftChild, title);
            }
            else{
            	MovieNodeLL *head = NULL;
                node -> leftChild = createNodeBST(title[0], node, nullptr, nullptr, head);
                // cout << "Value added recursively: " << title << endl;
                return true;
            }
        }

    }
        return false;
}

// this function uses recursion to add a node to the tree
bool MovieTree::BSTaddNodeRecursive(char *letter){
// TO DO: add helper functions if you need them
    if (!root) {
    	MovieNodeLL *head = NULL;
        root =  createNodeBST(letter[0], root, nullptr, nullptr, head);
        cout << "Root added recursively: " << letter << endl;
        return true;
    }
    // bool isAlreadyInBST = true;
    checkTree(root, letter);
    
    return true;
    // return isAlreadyInBST;
}


MovieNodeBST* MovieTree::createNodeBST(char letter, MovieNodeBST *parent, MovieNodeBST *leftChild, MovieNodeBST *rightChild, MovieNodeLL *head) {
   	MovieNodeBST *myBSTNode = new MovieNodeBST;
    myBSTNode -> letter = letter;
    myBSTNode -> parent = parent;
    myBSTNode -> leftChild = leftChild;
    myBSTNode -> rightChild = rightChild;
    myBSTNode -> head = head;
    return myBSTNode;
}


// this function allows the user to get a pointer to the root node of the BST outside of the BST class because
// the node is private.
MovieNodeBST* MovieTree::getRoot(MovieTree bst){
    MovieNodeBST *rootNode = bst.root;
    return rootNode;
}


 void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
 	// // TO DO: add helper functions if you need them
  //   MovieNodeLL * newNode = new MovieNodeLL;
  //   newNode -> ranking = ranking;
  //   newNode -> title = title;
  //   newNode -> year = releaseYear;
  //   newNode -> quantity = quantity;
  //   newNode -> next = nullptr;
  //   cout << newNode -> title << endl;
 	createNodeLL(ranking, title , releaseYear, quantity , nullptr);
 }


 MovieNodeLL* MovieTree::createNodeLL(int ranking, string title , int releaseYear, int quantity , MovieNodeLL *next){
 	// TO DO: add helper functions if you need them
    MovieNodeLL * newNode = new MovieNodeLL;
    newNode -> ranking = ranking;
    newNode -> title = title;
    newNode -> year = releaseYear;
    newNode -> quantity = quantity;
    newNode -> next = next;
    cout << newNode -> title << endl;

    return newNode;
 }


 // this is a helper function for addNodeRecursive that checks the value at
// all the nodes in the tree to find where to add
bool MovieTree::LLhelperFunction(string line){
	int itemPerLine = 4;
	string temp;
	// cout << line << endl;
	stringstream ss(line);
	string *word = new string[itemPerLine];
	for (int i=0; i<itemPerLine; i++) {
		getline(ss, temp, ',');
		word[i] = temp;
    }
    
    // int ranking = stoi(word[0]);
    string rankingS = word[0];
    int ranking = stoi(rankingS);
    // cout << ranking << endl;

    string title = word[1];
    // cout << title << endl;

    // int releaseYear = stoi(word[2]);
    string releaseYearS = word[2];
    int releaseYear = stoi(releaseYearS);
    // cout << releaseYear << endl;

    // int quantity = stoi(word[3]);
    string quantityS = word[3];
    int quantity = stoi(quantityS);
    // cout << quantity << endl;

	// addMovieNode(ranking, title, releaseYear, quantity);

	char *ptrline = &title[0];
	BSTaddNodeRecursive(ptrline);

	MovieNodeBST *searchNode = searchBST(root, title);
	cout << searchNode -> letter << endl;
	if (searchNode){
		if (searchNode -> letter == *ptrline){
			MovieNodeLL *traverse = searchNode -> head;
			while (traverse){
				traverse = traverse -> next;
			}
			traverse = createNodeLL(ranking, title , releaseYear, quantity , nullptr);
			// cout << "here" << endl;
			return true;
		}
	}
	else {
		return false;
	}
	
	// char *ptrline = &title[0];
	// BSTaddNodeRecursive(ptrline);

    return false;
}



void MovieTree::printMovieInventory() {
	printMovieInventory(root);
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



//use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, string title) {
	// Sanity check
	char titleChar = title[0];
    if(root) {
        if(node -> letter == titleChar){
            return node;
        }
        else if(node->letter > titleChar && node->leftChild){
            return searchBST(node->leftChild, title);
        }
        else if(node->letter < titleChar && node->rightChild){
            return searchBST(node->rightChild, title);
        }
        else{
            return NULL;
        }
    }
    return root;
}




//use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title){
	if (head){
		MovieNodeLL *tmp = new MovieNodeLL;
		tmp = head;
		while(tmp -> next && tmp -> title != title) {
			cout << tmp -> title << endl;
			tmp =tmp -> next;
		}
		return tmp;
	}
	return NULL;
}




void MovieTree::findMovie(string title) {
	cout << "Entering the search" << endl;
	MovieNodeBST *findMovieNode = searchBST(root, title);
	if (findMovieNode) {
		cout << "The movie title category was found!" << endl;
		MovieNodeLL *findMovieLL = searchLL(findMovieNode -> head, title);
		if (findMovieLL){
			cout << "The movie was found: " <<findMovieLL -> title <<  endl;
			cout << findMovieLL -> title << endl;
		}
	}

}