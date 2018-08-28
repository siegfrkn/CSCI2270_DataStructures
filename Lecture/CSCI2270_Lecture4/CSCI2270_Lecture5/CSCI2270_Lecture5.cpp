// QUICK SORT
// Pre-Conditions: A is an array and left and right are valid
// integers that index array
// Post-Conditions: Array is sorted in ascending order
// To use quickSort uncomment the code below

#include <iostream>

using namespace std;

int quickSort(int A[], int left, int right){
	int i = left;
	int j = right;
	int pivot = A[(left+right)/2];
	while (i < j){
		while (A[i] < pivot){
		i = i+1;
		}
		while (A[j] > pivot){
		j =j-1;
		}
		if (i <= j){
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i =i+1;
		j = j-1;
		}
	}
	if (left < j){
		quickSort (A, left, j);
	}
	if (i < right){
		quickSort (A, i, right);
	}
	return *A;
}

int main(){
	int A[5] = {5,8,9,3,6};
	int left = 0;
	int right = sizeof(A[5]);
	quickSort(A, left, right);
	for (int i = 0; i <= right; i++){
		cout << A[i] << endl;
	}
}


/* LINKED LISTS
   - nodes - the data we want, the value
   - pointers - to something else we want, another node w/
     the same structure
   - head and tail nodes - head node is first
   - linked lists have nodes with data nad pointers, dynamic
     size, good for unknown sizes
   - arrays have data, occupy a lot of space if we don't know
     the size of what we are dealing with
   - downside is we have to traverse linked lists (no indexing)
   - classes are better than structs for private/public and 
     structs are limited to attributes usually
*/ 


// BUILD A LINKED LIST
// Can be implemented using a class or struct where the next
// and/or previous pointers in the node reference another instance
// of the node
// To use, uncomment the following code

// #include <iostream>
// #include <stddef.h> // includes NULL
// #include <fstream>
// #include <string>
// #include <sstream>

// using namespace std;

// // node implementation for a singly-linked list, use capital letter for major declaration
// struct SingleNode {
// 	int key;
// 	SingleNode *next;
// };

// int main() {
// 	SingleNode *head; // intialize the node
// 	head = new SingleNode; // intializing the node
// 	head -> next = NULL; // dynamic allocation of the pointer
// 	head -> key = 10; // add node

// 	SingleNode *n1;
// 	n1 = new SingleNode;
// 	n1 -> key = 8;
// 	n1 -> next = NULL;
// 	head -> next = n1;

// 	SingleNode *n2;
// 	n2 = new SingleNode;
// 	n2 -> key = 7;
// 	n2 -> next = NULL;
// 	n1 -> next = n2;

// 	// syntaxes we can use
// 	// n1.value or n1 -> value

// 	// to print out new complex object I need to tell me
// 	// streaming operator how to understand it
// 	// does not know how to do * with complex object
// 	// be aware sometimes you run into errors bc your computer
// 	// does not understand new syntax - need to overload, i.e.
// 	// create another definition of that standard symbol
// 	cout << "This is n1 value: " << n1 -> key << endl;
// 	cout << "This is n1 pointer for next: "<< n1 -> next << endl;
// 	cout << "This is n2 address: " << n2 << endl;
// 	cout << "This is n2 value from n1: " << n1 -> next -> key << endl;
// 	// we were able to access the value of n2 from something far away
// 	// from n2
// }


// HOMEWORK 1
// need to pass stuff from the common line
// ./a.out 5

// int main(int argc, char *argv[]){
// 	cout << "This is argc " << argc << endl;

// 	string myStr = "fff";
// 	if (typeid(myStr).name() == typeid(string)name()){
// 	cout << "String" << endl;
// }
// if (typeid(to_string(2)).name() == typeid(int).name()){
// 	cout << "int" << endl;  +
// }
// cout << typeid(string).name() << endl;

// // would be cool if you....
// int*myArray = new int [10];
// quickSort(int *A, int left, int right);
// // how do I pass values from the command line?
// return 0;
// }


// QUIZ 5 KEY: hannibal