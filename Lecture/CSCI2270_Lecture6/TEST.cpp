#include <iostream>
#include <stddef.h> // includes NULL
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// node implementation for a singly-linked list, use capital letter for major declaration
struct SingleNode {
	int key;
	SingleNode *next = NULL;

	SingleNode(){


	}; // give the constructor a body
	SingleNode(int value){
		key = value;
	}

	// If you want to be elastic and overload multiple things
	// you need to define the default constructor WITH a body
};

int main(){

	SingleNode *n = new SingleNode();
	SingleNode *head = new SingleNode();
	SingleNode *tmpNode = new SingleNode();
	head -> next = NULL;

	for (int i=0; i<5; i++){
		SingleNode *n = new SingleNode(i);

		if (head -> next == NULL){
			head -> next = n;
		}

	while (tmpNode -> next != NULL){
		tmpNode = head-> next;

	}

	n = tmpNode -> next;
	n -> next = NULL;

	}

	SingleNode *printNode = head; // dummy node to print it by traversing it
	while (printNode != NULL){
		cout << "This is the value of current Node: " << head -> key << endl;
	printNode = printNode -> next;
	}

}