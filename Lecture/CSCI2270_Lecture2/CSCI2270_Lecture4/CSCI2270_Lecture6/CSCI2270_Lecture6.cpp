/* LINKED LIST
   -nodes (value/key)
   -pointers
   -head and tail nodes
   -use when we deal with the unknown
   -arrays are safer but can use only when we know what we are dealing with
   -arrays have an access time of O(1) (indexing)
   -linked list have to traverse the whole list O(n)
   -Singly or Doubly Linked
   -create by abstract the data using struct or class'

   */

// BUILD A LINKED LIST
// Can be implemented using a class or struct where the next
// and/or previous pointers in the node reference another instance
// of the node
// To use, uncomment the following code

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

int main() {

	// SingleNode *head; // intialize the node
	// head = new SingleNode; // intializing the node
	// head -> next = NULL; // dynamic allocation of the pointer
	// head -> key = 10; // add node
	// could also do
	// SingleNode *head = new SingleNode(value, *next)
	// int value = 5;
	// SingleNode *head = new SingleNode(value);
	// head -> next = NULL; // dynamic allocation of the pointer

	// SingleNode *n1;
	// n1 = new SingleNode;
	// n1 -> key = 8;
	// n1 -> next = NULL;
	// head -> next = n1;

	// SingleNode *n2;
	// n2 = new SingleNode;
	// n2 -> next = NULL;
	// n1 -> next = n2;

	// Automate adding of node with routine/algorithm
	SingleNode *head = new SingleNode();

	for (int i=0; i<5; i++){

		// Create a new node everytime
		SingleNode *n = new SingleNode((i+5)*2);
		n -> next = NULL;

		// set head node
		if (head == NULL){
			head = n;
		}
		else
		{
			SingleNode *tmpNode = head;

			while (tmpNode -> next != NULL)
			{
				tmpNode = tmpNode -> next;
			}

			tmpNode -> next = n;
		}
		//SingleNode *tmpNode = head; // is head pointing to something or not?

		// debug
		//cout << head -> next >> endl;
		

	// out here i can only access the last index of my node as soon as I am
	// "out of scope" or out of the loop - that's why we need to connect the
	// pattern using pointers
	//cout << "This is the value of n1: " << n->key << endl;
	// The beginning of this path that we have access to is the head
	SingleNode *printNode = head; // dummy node to print it by traversing it
	while (printNode != NULL){
		cout << "This is the value of current Node: " << printNode -> key << endl;
		printNode = printNode -> next;
	}
// int search(int value, SingleNode storage){
// 	SingleNode tmp = storage; // initialize tmp node as head node
// 	while (tmp != NULL){
// 		cout << tmp.key << endl;
// 		cout << tmp.next << endl;
// 	}
}
}

//QUIZ KEY: BUBA