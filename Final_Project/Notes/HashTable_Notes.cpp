//
//  Utils.cpp
//  
//
//  Created by cami on 7/19/18.
//
//

#include "Utils.hpp"


HashTable::HashTable(int tSize){
	tableSize = tsize;
	_lookupTable = 
}



int HashTable::HashSum(string title, int tableSize) {
	int sum = 0;
	for (int i=0; i<myString.length(); i++) {
		cout << "This is ASCII of " << myString[i] << ":" << (int)myString[i] << endl;
		sum +=myString[i];
	}
	cout << "This is SUM: " << sum << endl;
	// maybe instead of computing the sum of all characters of the string,
	// if "% tableSize" you will be able to store your value in the table
	// because it says I will contain anything less than my max size, and will
	// expell everything else. The mod division prevents us from having to have
	// a table that of length 100's+ - not feesible.
	return sum % tableSize;
}


// should pass the zippedNode we created
void HashTable::insert(zippedNode *node) {
	int index = HashSum(node->title);
	if (!_lookupTable[index]) {// if there isnt anything at the table
		_lookupTable[index] = node;
	}
	else { // i have a collision - use chaining
		ZippedNode *temp = _lookupTable[index];
		while(temp->next) {
			temp = temp->next; // keep looking
		}
		temp->next = node; // add the node at the end of the list
	}
}

Utils::Utils(){
    
}

void Utils::~Utils(){
    
}

//TODO
void Utils::computeFrequency(){
    
    
}
//TODO
void Utils::huffEncode(){
    
    
}
//TODO
void Utils::huffDecode(){
    
    
}

// THIS SHOULD BE ITS OWN FUNCTION
int main() {
	HashTable myHashTable = new HashTable(20); // size of our hash table
}