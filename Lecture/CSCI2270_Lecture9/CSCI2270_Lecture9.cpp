/* Midterm
 * - during recitation time
 * - includes binary search trees
 * - study guide will be up tomorrow
 * - Fri/Sat post practice midterm!

 * - Will have insert/delete node code up by tomorrow


/******************LECTURE SPRINT*****************/
/*
Write a C++ functions to check whether the stack is empty.
		bool isEmpty()
Write a C++ functions to check whether the stack is full.
		bool isFull();
The structure of the stack is declared as follows:
		struct node{
		    int value;
		    struct node* next; // next element points to another element of type node
		}
		*top = nullptr; // top is the top of the stack.
The following functions/variables are already defined:
int maxSize; //Global variable which defines the maximum size of your stack
void push(int value);// adding element in the stack
void pop();// poping element from the stack
bool isFull();  // check if the stack is full
int stackCounter; //the variable to be incremented/decremented based on push or pop
void display(); // display the current stack. (It does not print out underflow or overflow which should be handled by your function).

class Stack { // complex object with attributes and features (skills)
	public:
		int stackCounter;		// this is an attribute
		int maxSize;			// this is another attribute
	void push(int value); 		// feature/skill
	void pop();					// feature/skill
	bool isFull();				// feature/skill
	void display();				// feature/skill

}

bool isEmpty(){

    if (stackCounter == 0){
        return 1;
    else{
        return 0;
    }

    // another way
    // bool isEmpty(){
	//	  return top == nullptr;
	//}
}

bool isFull(){
    
    if (stackCounter >= maxSize){
        return 1;
    }
    else{
        return 0;
    }
}


/******************LECTURE NOTES*****************/

/*
Doubly Linked Lists (DLL)
- point forwards and backwards
- struct dnode{
	int key;
	dnode *n;
	dnode *p;
};
- point forwards and backwards
- walked through logic of inserting and adding in front, middle, end
- order is impt
- for example, inserting a d-node in middle
	1. link inserting node *n to point to new "downstream"
	2. link new "upstream" *n to inserting node
	3. link inserting node *p to "upstream"
	4. link "downsteam" *p to inserting node
- big O for DLL same as SLL


 Stacks - how I allocate memory
 - FILO - first in last out - Array or SSL
 - Push - O(1)
 - Pop - O(1)

 Queues
 - FIFO - first in first out - array or SSL
 - "wait your turn"
 - Push - O(1)
 - Pop - O(1)
 - have priority that stacks do not have
 - to check if empty need to check that head = tail = NULL
 - when the queue is totally full, point the tail to the head (full if head = tail and head is not NULL)
 - everytime we pop we need to reset the head to the next element to be popped.

 - always need to check ifFull - if not do stuff, else pop() or stop

 QUIZ KEY: banana
*/