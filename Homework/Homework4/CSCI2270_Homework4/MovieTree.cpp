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
};

// define our default destructor
MovieTree::~MovieTree() {
	root = nullptr;
}


/* FUNCTION: readInFileFunc
 * CLASS MEMBER: Public
 * INPUTS: string fileNameString, MovieTree myMovieTree
 * PURPOSE: Reads in the comma delimited data from the txt passed when the program began,
 * pulled as argv[]. Uses a helper function called LLhelperFunction to create the
 * structure.
 * OUTPUTS: void
*/
void MovieTree::readInFileFunc(string fileNameString, MovieTree myMovieTree){
	string word, line;	
	bool test = false;																		
	ifstream fileStreamString(fileNameString);
	if (!fileStreamString.is_open()){							
		cout << "Ignore Words file failed to open." << endl;
	}
	while(fileStreamString.good()){
		getline(fileStreamString, line, '\n');
		LLhelperFunction(line);												// to build a linked list node, pass the entire line to the helper function
		if (fileStreamString.eof()){						
				break;									
			}
	}
	fileStreamString.close();									
	cout << "\n \n" << endl;
}


/* FUNCTION: checkTree
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeBST *node and char *title
 * PURPOSE: This is a helper function for BSTaddNodeRecursive that checks the
 * value at all the nodes in the tree and compares them to pre-existing nodes.
 * OUTPUTS: true if new node is added, false otherwise.
*/
bool MovieTree::checkTree(MovieNodeBST* node, char *title){
    if (root){
         if (node -> letter < *title ) {
            if (node -> rightChild){
                checkTree(node->rightChild, title);								// if value is already in the tree, start a linked list
            }
            else{
            	MovieNodeLL *head = NULL;
                node -> rightChild = createNodeBST(*title, node, nullptr, nullptr, head);
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
                return true;
            }
        }
    }
        return false;
}


/* FUNCTION: BSTaddNodeRecursive
 * CLASS MEMBER: Private
 * INPUTS: char *letter
 * PURPOSE: This function uses recursion to add the next BST node to
 * the tree. It uses a char pointer to the first letter of the movie
 * in question to create it.
 * OUTPUTS: true if new node is added, false otherwise.
*/
bool MovieTree::BSTaddNodeRecursive(char *letter){
    if (!root) {
    	MovieNodeLL *head = NULL;
        root =  createNodeBST(letter[0], root, nullptr, nullptr, head);
        return true;
    }
    checkTree(root, letter);
    return true;
}


/* FUNCTION: createNodeBST
 * CLASS MEMBER: Private
 * INPUTS: char letter, MovieNodeBST *parent, MovieNodeBST *leftChild, MovieNodeBST *rightChild, MovieNodeLL *head
 * PURPOSE: This function uses the values passed as inputs to populate a new BST node.
 * OUTPUTS: returns the new BSTnode created
*/
MovieNodeBST* MovieTree::createNodeBST(char letter, MovieNodeBST *parent, MovieNodeBST *leftChild, MovieNodeBST *rightChild, MovieNodeLL *head) {
   	MovieNodeBST *myBSTNode = new MovieNodeBST;
    myBSTNode -> letter = letter;
    myBSTNode -> parent = parent;
    myBSTNode -> leftChild = leftChild;
    myBSTNode -> rightChild = rightChild;
    myBSTNode -> head = head;
    return myBSTNode;
}


/* FUNCTION: addMovieNode
 * CLASS MEMBER: Public
 * INPUTS: int ranking, string title, int releaseYear, int quantity
 * PURPOSE: This function uses the values passed to add new movie nodes to the linked
 * list by comparing values already in the structure so duplicates are not added,
 * and otherwise finds the right place to add the node in and calls create function
 * to add.
 * OUTPUTS: void
*/
 void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
	char *ptrline = &title[0];
	BSTaddNodeRecursive(ptrline);											// make sure there is a BST node ready to receive this linked list node
	MovieNodeBST *findMovieNode = searchBST(root, title);		
	if (findMovieNode) {													// make sure it isn't already in the list
		MovieNodeLL *findMovieLL = searchLL(findMovieNode -> head, title);
		if (findMovieLL != NULL && findMovieLL -> title == title){
			cout << "\nThe movie is already in the database. Would you" << endl;
			cout << "like to overwrite the existing node or add to the" << endl;
			cout << "existing quantity?" << endl;
			cout << "O: Overwrite" << findMovieLL -> title << endl;
			cout << "E: Add to existing" << endl;
			string userInputAdd;
			getline(cin, userInputAdd);
			if (userInputAdd == "O") {
				findMovieLL -> ranking = ranking;
				findMovieLL -> title = title;
				findMovieLL -> ranking = ranking;
				findMovieLL -> year = releaseYear;
				findMovieLL -> quantity = quantity;
				cout << "\nMovie node successfully overwritten." << endl;
				return;
			}
			else if (userInputAdd == "E") {
				int newQuantity = findMovieLL -> quantity;
				newQuantity = newQuantity + quantity;
				findMovieLL -> quantity = newQuantity;
				cout << "\nMovie quantity successfully updated." << endl;
				return;
			}
			else {
				cout << "\nInvalid Selection." << endl;
				return;
			}
		}
	}
	MovieNodeBST *searchNode = searchBST(root, title);
	if (searchNode){															// if it isn't already in the structure, add it in!
		if (searchNode -> letter == *ptrline){
			MovieNodeLL *start = searchNode -> head;
			MovieNodeLL *traverse = createNodeLL(searchNode -> head, ranking, title , releaseYear, quantity , NULL);
			searchNode -> head = traverse;
			if (!start) {
				start = traverse;
				searchNode -> head = traverse;
			}
			else {
				while (start -> next){
					start = start -> next;
				}
				traverse = createNodeLL(searchNode -> head, ranking, title , releaseYear, quantity , start);
			}
			MovieNodeBST *tmp = searchNode;
			sortLL(tmp -> head);
		}
	}
}


/* FUNCTION: createNodeBST
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeLL *head, int ranking, string title, int releaseYear, int quantity,
 * MovieNodeLL *next
 * PURPOSE: This function uses the values passed as inputs to populate a new singly
 * linked list at the head.
 * OUTPUTS: returns the new LLnode created
*/
 MovieNodeLL* MovieTree::createNodeLL(MovieNodeLL *head, int ranking, string title , int releaseYear, int quantity , MovieNodeLL *next){
    MovieNodeLL * newNode = new MovieNodeLL;
    newNode -> ranking = ranking;
    newNode -> title = title;
    newNode -> year = releaseYear;
    newNode -> quantity = quantity;
    newNode -> next = head;
    return newNode;
 }


/* FUNCTION: LLhelperFunction
 * CLASS MEMBER: Private
 * INPUTS: string line
 * PURPOSE: This function uses a single line from the text file that is being
 * read in and parsed into pieces so that it can be stored in a single linked
 * list using the addMovieNode function. This function COULD be improved by
 * making the itemPerLine variable dynamic. This is a helper function to
 * BSTaddNodeRecursive
 * OUTPUTS: void
*/
void MovieTree::LLhelperFunction(string line){
	int itemPerLine = 4;
	string temp;
	stringstream ss(line);
	string *word = new string[itemPerLine];
	for (int i=0; i<itemPerLine; i++) {
		getline(ss, temp, ',');
		word[i] = temp;
    }
    string rankingS = word[0];
    int ranking = stoi(rankingS);
    string title = word[1];
    string releaseYearS = word[2];
    int releaseYear = stoi(releaseYearS);
    string quantityS = word[3];
    int quantity = stoi(quantityS);
    addMovieNode(ranking, title, releaseYear, quantity);
}


/* FUNCTION: printMovieInventory
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: Public function that calls the private overloaded function printMovieInventory(root)
 * that can access the root of the BST, which is private.
 * OUTPUTS: void
*/
void MovieTree::printMovieInventory() {
	printMovieInventory(root);
}


/* FUNCTION: printMovieInventory - overloaded
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeBST *node
 * PURPOSE: Private function which is the overloaded version of the public function.
 * take a pointer to a BST node, presumably the root, which will use recursion to go
 * through the BST structure and print the BST node letter and then all of the list movie
 * nodes at that node and their quantity.
 * OUTPUTS: void
*/
void MovieTree::printMovieInventory(MovieNodeBST * node) {
	if(node) {
        if(node->leftChild) {
            printMovieInventory(node->leftChild);
        }
        if (node -> letter != NULL) {
	        cout << "===========================================" << endl;
	        cout << "" << node->letter << "" << endl;
	        cout << "===========================================\n" << endl;
	            MovieNodeLL *tmp = node -> head;
	            while (tmp){
	            	cout << "Title: " << tmp -> title << endl;
	            	cout << "Quantity: " << tmp -> quantity << endl;
	            	cout << "" << endl;
	            	tmp = tmp -> next;
	            }
        }
        if(node->rightChild) {
            printMovieInventory(node->rightChild);
        }
    }
    else {
    	cout << "\nDude, all the movies are like, gone?\n" << endl;
    }
    return;
}


/* FUNCTION: searchBST
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeBST *node, string title
 * PURPOSE: Private function which uses recursion to find a pointer to the node in
 * the BST that matches the first letter of the title of the movie to be added.
 * OUTPUTS: MovieNodeBST pointer to match or NULL
*/
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, string title) {
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
    return NULL;
}


/* FUNCTION: searchLL
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeLL *head, string title
 * PURPOSE: Private function which uses recursion to find a pointer to the node in
 * the LL at a given BST node that matches the title of the movie to be added.
 * OUTPUTS: MovieNodeLL pointer to match or NULL
*/
MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title){
	if (head){
		MovieNodeLL *tmp = new MovieNodeLL;
		tmp = head;
		while(tmp -> next && tmp -> title != title) {
			tmp =tmp -> next;
		}
		return tmp;
	}
	return NULL;
}


/* FUNCTION: findMovie
 * CLASS MEMBER: Public
 * INPUTS: string title
 * PURPOSE: Public function that allows a user to find a movie in the BST/list
 * structure.
 * OUTPUTS: cout statement of movie info if found, otherwise cout statemnt that
 * movie is not found.
*/
void MovieTree::findMovie(string title) {
	MovieNodeBST *findMovieNode = searchBST(root, title);
	if (findMovieNode) {
		MovieNodeLL *findMovieLL = searchLL(findMovieNode -> head, title);
		if (findMovieLL -> title == title){
			cout << "\nMovie Info: " << endl;
			cout << "===========" << endl;
			cout << "Ranking: " << findMovieLL -> ranking << endl;
			cout << "Title: " << findMovieLL -> title << endl;
			cout << "Year: " << findMovieLL -> year << endl;
			cout << "Quantity: " << findMovieLL -> quantity << endl;
		}
		else {
		cout << "Movie not found." << endl;
		}
	}
	else {
		cout << "Movie not found." << endl;
	}
}


/* FUNCTION: sortLL
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeLL *head
 * PURPOSE: Private function that takes the head of a linked list (which because the node
 * is always added at the head will always be the most recent node) and uses a bubble sort
 * algorithm to move recursively through the list and comare the current node to the next
 * node. If the values are out of order, the swapLL function will be called to change out
 * the values.
 * OUTPUTS: MovieNodeLL pointer to head of the sorted linked list
*/
MovieNodeLL* MovieTree::sortLL(MovieNodeLL* head){
	int swap;
	MovieNodeLL* uphillNode = new MovieNodeLL;
	MovieNodeLL* downhillNode = new MovieNodeLL;
	downhillNode = NULL;
	if(head -> next == NULL){
		return head;
	}
	uphillNode = head;
	do {
		swap = 0;
		while (uphillNode -> next != downhillNode && uphillNode -> next != NULL) {
			if (uphillNode -> title > uphillNode -> next -> title) {
				swapLL(uphillNode, uphillNode -> next);
				swap = 1;
			}
			uphillNode = uphillNode -> next;
		}
		downhillNode = uphillNode;
	}
	while (swap > 0);
	return head;
}


/* FUNCTION: swapLL
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeLL *uphill, MovieNodeLL *downhill
 * PURPOSE: Private function that replaces the value from one node with the values of
 * another node.
 * OUTPUTS: void
*/
void MovieTree::swapLL(MovieNodeLL*uphill, MovieNodeLL* downhill) {
	MovieNodeLL *tmpNode = new MovieNodeLL;			
	tmpNode -> title = uphill -> title;											// stores the uphill node data in tmp
	tmpNode -> ranking = uphill -> ranking;
	tmpNode -> year = uphill -> ranking;
	tmpNode -> quantity =uphill -> quantity;
	uphill -> ranking = downhill -> ranking;									// stores the downhill node data in uphill node
	uphill -> title = downhill -> title;
	uphill -> year = downhill -> year;
	uphill -> quantity = downhill -> quantity;
	downhill -> ranking = tmpNode -> ranking;									// store the orignial uphill node data in downhill
	downhill -> title = tmpNode -> title;
	downhill -> year = tmpNode -> year;
	downhill -> quantity = tmpNode -> quantity;
}


/* FUNCTION: deleteMovieNodeBST
 * CLASS MEMBER: Private
 * INPUTS: string value
 * PURPOSE: Private function that uses the searchBST and findMinimum functions as
 * helper that deletes a node in a BST
 * OUTPUTS: MovieNodeBST pointer to BST root
*/
MovieNodeBST* MovieTree::deleteMovieNodeBST(string value) {
    if(root) {																	// we are not deleting the root
        MovieNodeBST* nodeToDelete = searchBST(root, value);
        if(nodeToDelete != root) {												// NO children
            if (!nodeToDelete->leftChild && !nodeToDelete->rightChild) {
                if (nodeToDelete-> parent -> leftChild){
                    nodeToDelete-> parent -> leftChild = NULL;
                }
                else if (nodeToDelete -> parent -> rightChild) {
                    nodeToDelete-> parent -> rightChild = NULL;
                }
                delete nodeToDelete;
                return root;
            }
            else if (nodeToDelete->leftChild && nodeToDelete->rightChild){		// 2 CHILDREN
                MovieNodeBST *min = treeMinimum(nodeToDelete->rightChild);
                if (min == nodeToDelete -> rightChild) {
                        nodeToDelete -> parent -> leftChild = min;
                        min -> parent = nodeToDelete -> parent;
                        min -> leftChild = nodeToDelete -> leftChild;
                        min -> leftChild -> parent = min;
                    }
                else{
                    min -> parent -> leftChild = min -> rightChild;
                    min -> rightChild -> parent = min -> parent;
                    min ->parent = nodeToDelete -> parent;
                    nodeToDelete -> parent -> leftChild = min;
                    min -> leftChild = nodeToDelete -> leftChild;
                    min -> rightChild = nodeToDelete -> rightChild;
                    nodeToDelete -> rightChild -> parent = min;
                    nodeToDelete -> leftChild -> parent = min;
                }
                delete nodeToDelete;
                return root;
            }
            else {																// 1 CHILD
                if (nodeToDelete -> parent -> leftChild == nodeToDelete){
                    if (nodeToDelete->leftChild){
                        nodeToDelete -> parent -> leftChild = nodeToDelete -> leftChild;
                    }
                    else if (nodeToDelete -> rightChild){
                        nodeToDelete -> parent -> leftChild = nodeToDelete -> rightChild;
                    }
                }
                else{
                    if (nodeToDelete -> leftChild){
                        nodeToDelete -> parent -> rightChild = nodeToDelete -> leftChild;
                    }
                    else if (nodeToDelete -> rightChild){
                        nodeToDelete -> parent -> rightChild = nodeToDelete -> rightChild;
                    }
                }
                delete nodeToDelete;
                return root;
            }
        }
        else{																	//we are deleting the root!
            if (!nodeToDelete -> rightChild && !nodeToDelete -> leftChild){
                root = NULL;
                delete nodeToDelete;
                return root;
            }
            else if (nodeToDelete->leftChild && nodeToDelete->rightChild){		// 2 CHILDREN
                MovieNodeBST *min = treeMinimum(nodeToDelete->rightChild);
                if (min == nodeToDelete -> rightChild) {
                    root = min;
                    min -> parent = NULL;
                    nodeToDelete -> leftChild -> parent = min;
                    min -> leftChild = nodeToDelete -> leftChild;
                }
                else{
                    root = min;
                    if (min -> rightChild) {
                        min -> rightChild -> parent = min -> parent;
                    }
                    min -> parent -> leftChild = min -> rightChild;
                    min -> parent = NULL;
                    min -> leftChild = nodeToDelete -> leftChild;
                    if (nodeToDelete -> leftChild) {
                        nodeToDelete -> leftChild -> parent = min;
                    }
                    min -> rightChild = nodeToDelete -> rightChild;
                    if (nodeToDelete -> rightChild) {
                        nodeToDelete -> rightChild -> parent = min;
                    }
                }
                delete nodeToDelete;
                return root;
            }
            else if (nodeToDelete -> rightChild || nodeToDelete -> leftChild) {	// 1 CHILD
                if (nodeToDelete-> leftChild){
                    nodeToDelete -> leftChild -> parent = NULL;
                    root = nodeToDelete -> leftChild;
                }
                else if (nodeToDelete -> rightChild){
                    nodeToDelete -> rightChild -> parent = NULL;
                    root = nodeToDelete -> rightChild;
                }
                delete nodeToDelete;
                return root;
            }
        }
    }
    else {
        cout << "\nDude, all the movies are like, gone?\n" << endl;
    }
    return root;
}


/* FUNCTION: treeMinimum
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeBST *node
 * PURPOSE: Private function that finds the minimum value associated with a given
 * BST node; used for BST ndoe deletion.
 * OUTPUTS: MovieNodeBST pointer to minimum node
*/
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node){
	MovieNodeBST *current = node;
    while (current -> leftChild != NULL){
        if (current -> letter > current -> leftChild -> letter){
            current = current -> leftChild;
        }
    }
    return current;
}


/* FUNCTION: rentMovie
 * CLASS MEMBER: Public
 * INPUTS: string title
 * PURPOSE: Public function similar to findMovie function. It uses search BST and
 * searchLL to find a movie if it is in the list.
 * OUTPUTS: if found cout movie info, if not found cout that movie is not found
*/
void MovieTree::rentMovie(string title){
	MovieNodeBST *rentMovieNode = searchBST(root, title);
	if (rentMovieNode) {
		MovieNodeLL *rentMovieNodeLL = searchLL(rentMovieNode -> head, title);
		if (rentMovieNodeLL -> title == title){
			rentMovieNodeLL -> quantity = rentMovieNodeLL -> quantity - 1;
			cout << "\nMovie Info: " << endl;
			cout << "===========" << endl;
			cout << "Ranking: " << rentMovieNodeLL -> ranking << endl;
			cout << "Title: " << rentMovieNodeLL -> title << endl;
			cout << "Year: " << rentMovieNodeLL -> year << endl;
			cout << "Quantity: " << rentMovieNodeLL -> quantity << endl;
			if (rentMovieNodeLL -> quantity == 0 && rentMovieNodeLL -> next == NULL){
				deleteMovieNode(title);
			}
		}
		else {
		cout << "Movie not found." << endl;
		}
	}
	else {
		cout << "Movie not found." << endl;
	}
}

/* FUNCTION: deleteMovieNode
 * CLASS MEMBER: Public
 * INPUTS: string title
 * PURPOSE: Public function that allows user to pass a movie title of a movie they
 * would like to delete. If the movie is found in the list it deletes the linked
 * list node and/or bst node appropriately.
 * OUTPUTS: void, cout movie not found if not found
*/
void MovieTree::deleteMovieNode(string title){
	MovieNodeBST *deleteMovieNode = searchBST(root, title);
	if (deleteMovieNode == NULL){
		cout << "Movie not found." << endl;
		return;
	}
	cout << deleteMovieNode -> letter << endl;
	if(deleteMovieNode) {
		MovieNodeLL* deleteMovieNodeLL = searchLL(deleteMovieNode -> head, title);
		if (deleteMovieNodeLL -> title == title) {
			cout << deleteMovieNodeLL -> title << endl;
			bool deleteNodeBool = deleteNodeLL(deleteMovieNode -> head, title);
			if (!deleteNodeBool){
				deleteMovieNodeBST(title);
			}
		}
		else {
			cout << "Movie not found." << endl;
		}
	}
	else {
		cout << "Movie not found." << endl;
	}
}


/* FUNCTION: deleteNodeLL
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeLL *head, string title
 * PURPOSE: Private function that deletes a node in a singly linked list by excluding
 * it.
 * OUTPUTS: true if deleted, false otherwise
*/
bool MovieTree::deleteNodeLL(MovieNodeLL* head, string title) {
	if (head -> title == title) {
		MovieNodeLL *placeholder = nullptr;
		if (head -> next == NULL){
			return false;
		}
		head -> title = head -> next -> title;
		head -> ranking = head -> next -> ranking;
		head -> year = head -> next -> year;
		head -> quantity = head -> next -> quantity;
		placeholder = head -> next;
		head -> next = head -> next -> next;
		free(placeholder);
		return true;
	}
	else {
		MovieNodeLL* previous = head;
		while(previous -> next && previous -> next -> title != title) {
			previous = previous -> next;
		}
		MovieNodeLL * tmp = previous -> next;
		previous -> next = previous -> next -> next;
		free(tmp);
	}
	return true;
}


/* FUNCTION: countMovieNodes - overloaded
 * CLASS MEMBER: Private
 * INPUTS: MovieNodeBST *node, int *c
 * PURPOSE: This is the private overloaded function for countMovieNodes, that
 * takes a node (presumably the root of BST) and a pointer to a integer c for
 * counting created in the Public function, and uses recursion to navigate the
 * BST and pushes through all the linked lists to cound the number of movie
 * nodes in the list. Note that this does not count the number total "quantity"
 * of movies.
 * OUTPUTS: void
*/
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c) {
	if (!node) {
		*c = 0;
		cout << "empty tree" << endl;
	}
	else {
		int *count = c;
		if (node -> leftChild != NULL) {
			*count = *count + 1;
			countMovieNodes(node -> leftChild, count);
		}
		MovieNodeLL *tmpLL = node -> head;
        while (tmpLL -> next != NULL){
        	*count = *count + 1;
        	tmpLL = tmpLL -> next;
        }

		if (node -> rightChild != NULL){
			*count = *count + 1;
			countMovieNodes(node -> rightChild, count);
		}
		return;
	}
}


/* FUNCTION: countMovieNodes
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: This is the public function (and the non-overloaded version) of
 * countMovieNodes. This function calls the countMovieNodes overloaded function
 * that uses recursion to count the number of movieNodes in the list. It also
 * creates a pointer to an integer used for counting that can be updated across
 * the two functions without passing it as an output.
 * OUTPUTS: int count
*/
int MovieTree::countMovieNodes(){
	int count = 1;
	int *c = &count;
	if (!root) {
		return 0;
	}
	else {
		countMovieNodes(root, c);
		cout << "There are " << count << " movie nodes in the tree." << endl;
	}
	return count;	
}


/* FUNCTION: DeleteAll -overloaded
 * CLASS MEMBER: Private
 * INPUTS: MovieNode *node
 * PURPOSE: This function takes the pointer to a BST node and deletes all the nodes
 * up to and including that node using a post-order recursive traversal of the tree.
 * I don't actually use this function in the program but I have it written and called
 * as a "Bonus" function uses an underloaded public function.
 * OUTPUTS: void
*/
void MovieTree::DeleteAll(MovieNodeBST * node) {
	if (node == NULL) {
		return;
		}
		DeleteAll(node -> leftChild);
		node -> leftChild = nullptr;
		DeleteAll(node -> rightChild);
		string title(1, node -> letter);
		node -> rightChild = nullptr;
		if (node -> parent -> leftChild == node) {
			node -> parent -> leftChild == NULL;
		}
		if (node -> parent -> rightChild == node) {
			node -> parent -> rightChild == NULL;
		}
		node -> head = NULL;
		node -> parent = nullptr;
		node -> letter = NULL;
		node -> rightChild = nullptr;
		node -> leftChild = nullptr;
		node = nullptr;
		delete node;
	return;
}


/* FUNCTION: DeleteAll
 * CLASS MEMBER: Public
 * INPUTS: MovieNode *node
 * PURPOSE: This function takes the pointer to a BST node and deletes all the nodes
 * up to and including that node using a post-order recursive traversal of the tree.
 * I don't actually use this function in the program but I have it written and called
 * as a "Bonus" function. This function calls the private overloaded version that
 * actually performs the deletion. This function just finds the node and passes it.
 * OUTPUTS: void
*/
void MovieTree::DeleteALL(string letterString) {
	char letter = letterString[0];
	MovieNodeBST *nodeToDelete = searchBST(root, letterString);
	if (nodeToDelete -> letter == letter) {
		if (nodeToDelete -> parent -> leftChild == nodeToDelete) {
			nodeToDelete -> parent -> leftChild == nullptr;
		}
		if (nodeToDelete -> parent -> rightChild == nodeToDelete) {
			nodeToDelete -> parent -> rightChild == nullptr;
		}
		DeleteAll(nodeToDelete);
		nodeToDelete = NULL;
		delete nodeToDelete;
		cout << "\nNot sure why you'd want to ever do that, but the BST node " << letter << endl;
		cout << "and it's children have been deleted." << endl;
	}
}