/* LECTURE SPRINt

Write a C++ function to add a node to the end of a linked list. The function takes two arguments - the head of the linked list and the value to be added. It should return the head of the linked list.
node * AddNode(node *head, int key);
The linked list structure:
struct node
{
    int key;

    node *next;
};

* You can assume that the head being passed is initialized as follow:  node *head = NULL;

*/

// node *AddNode(node *head, int key){
//     node *newNode = new node;
//     newNode -> key = key;
//     newNode -> next = NULL;
    
//     // checks to see if we have an empty list
//     if (head == NULL){
//         head = newNode;
//         return head;
//     }
    
//     // have to traverse the list, preserve the head node
//     // create a pointer that will point to same place as head
//     node *tmpNode = new node;
//     tmpNode = head;
    
//     while (tmpNode -> next != NULL){
//         tmpNode = tmpNode -> next;
//         // when tmpNode is NULL point to the new node
//     }
    
//     tmpNode -> next = newNode;
//     return head;
// }


/* LINKED LIST

*/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;



struct SingleNode {
	int k;
	SingleNode *n;
	//SingleNode *n = NULL; // easiest way to start all the nodes as pointing to NULL - slightly more efficient
};

struct DoubleNode {
	int k;
	DoubleNode *p;
	DoubleNode *n;
};




// Create a struct that will always allow me to have a head node
class LinkedList{

public:
	SingleNode *head = NULL;
	LinkedList(){};
	LinkedList(int value){
		head -> k = value;
		head -> n = NULL;
	}
};

// OR start off every new node as pointing to NULL in struct - see struct and uncomment code accordingly

// UGLY WAY IS WITH GLOBAL VARIABLES
// Define linked list as global
//SingleNode *head = new SingleNode;



// passing the node in as a reference (address) BASICALLY PSUEDOCODE AT THIS POINT
// void insertNode(SingleNode *leftNode, int value){
	
// 	// first thing we need to do is createa new node, then pass values to it
// 	SingleNode *newNode = new SingleNode; 
// 	SingleNode -> k;
// 	newNode -> n = NULL;

// 	// Find leftNode in the linked list
// 	SingleNode *tmp = head;
// 	While (tmp != NULL){
// 		if (tmp == leftNode){
// 			if (leftNode == NULL){

// 			}
// 			ifelse(leftNode.next == NULL){

// 			}
// 			else{

// 			}
// 			break;
// 		}
// 		tmp = tmp -> n;
// 	}
// }



// have to find where to insert nodes
SingleNode *searchNode(LinkedList *linkedlist, int valueToSearch){

	// first node is a tmp node because we need to traverse the list
	SingleNode *tmp = linkedlist -> head;
	while (tmp != NULL){
	// while (tmp -> n != NULL){ // I commented this out because when the linked list only has one value, the tmp->n will ALWAYS be NULL
		if (tmp -> k == valueToSearch){
			// if I find the value
			cout << "FOUNDDDDDDD!!!" << endl;
			return tmp;
		}
		tmp = tmp-> n;
	}
	cout << "NOT FOUNDDDDDDD!!!" << endl;
	return NULL;
}


// only deal with adding a node at the end of the list
void insertNode(LinkedList *linkedlist, int leftValue, int valueToInsert){

	// Create newNode
	SingleNode *newNode = new SingleNode;
	newNode -> k = valueToInsert;
	newNode -> n = NULL;

	SingleNode left = searchNode(linkedlist, leftValue);
	
	if (linkedlist -> head ==NULL){
		linkedlist -> head = newNode;
		return;
	}


	// if if if logic needs to be revised.
	// 1. If newNode will be new head
	if (left == NULL) {
		// If I don't find it let me add it at the beginning
		newNode ->n = head;
		head = newNode;
	}

	// 2. If newNode will be middle
	if (left -> n != NULL){ // middle case
		newNode -> n = left -> n;
		left -> n = newNode;
	}

	// 3. If newNode will be tail/end
	if (left -> n == NULL){
		left -> n = newNode;
	}

	SingleNode *tmp = linkedlist -> head;

	// check if my next node is null
	while (tmp -> n != NULL){
		tmp = tmp -> n;
	}
	tmp -> n = newNode;
	cout << "Value Inserted" << endl;
}



int main() {

	LinkedList *linkedlist = new LinkedList(5);

	// TO DO:
	// 1. Insert a new node after my head node manually in linkedlist
	// 2. Search it
	// 3. Print it out
	// SingleNode *n1 = new SingleNode;
	// n1 -> k = 4;
	// linkedlist -> head -> n = n1;
	// searchNode(linkedlist, 6);
	// cout << "This is the address of n1: " << n1 << endl;
	// cout << "This is the address pointed to by the head of linkedlist: " << linkedlist -> head -> n << endl;
	// cout << "This is the value in node n1: " << n1 -> k << endl;

	//insertNode(linkedlist, 7);

	searchNode(linkedlist, 7);

	// cout << linkedlist -> head << endl; // pointing where the head is stored
	// cout << linkedlist << endl; // pointing to where big linkedlist is stored
	// cout << linkedlist -> head -> k << endl; //  pointing to the value stored at the head node

	// search the list to see if 5 is found
	// searchNode(linkedlist, 5);

	return 0;
}

// PASSWORD FOR QUIZ: jenny