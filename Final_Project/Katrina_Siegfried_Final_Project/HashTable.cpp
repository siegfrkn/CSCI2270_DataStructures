//
//  HashTable.cpp
//  
//
//  Created by cami on 7/19/18.
//  Modified by Katrina Siegfried 7/23/2018
//  CSCI 2270 - Data Structures
//  Final Project
//
//


// INCLUDE NECESSARY LIBRARIES AND NAMESPACE
#include <string>
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include <queue>
#include "Utils.h"

using namespace std;


/* FUNCTION: default constructor for HashTable
 * CLASS MEMBER: Public
 * INPUTS: none, but takes default template of hash table length
 * PURPOSE: When a HashTable object is instantiated it will be "born" with
 * these default properties; the title will be "empty", the excerpt will be
 * "0", and the huff_node and next pointers will be "nullptr"
 * OUTPUTS: none
*/
template <int ARRAY_LEN>
HashTable<ARRAY_LEN>::HashTable() {
    tableSize = ARRAY_LEN;
    for (int i=0; i<tableSize; i++) {
        lookupTable[i] = new ZippedBookNode;
        lookupTable[i]->title = "empty";
        lookupTable[i]->c_excerpt = "0";
        lookupTable[i]->huff_root = nullptr;
        lookupTable[i]->next = nullptr;
    }
}


/* FUNCTION: default destructor for HashTable
 * CLASS MEMBER: Public
 * INPUTS: none, but takes default template of hash table length
 * PURPOSE: When a HashTable object is "destroyed" by calling the destructor,
 * the destructor will iterate through the array and empty it out by pointing
 * each entry of the array to NULL.
 * OUTPUTS: none
*/
template <int ARRAY_LEN>
HashTable<ARRAY_LEN>::~HashTable() {
    for (int i=0; i<ARRAY_LEN; i++) {
        lookupTable[i] = NULL;
    }
}


/* FUNCTION: getTableSize
 * CLASS MEMBER: Public
 * INPUTS: none, but takes default template of hash table length
 * PURPOSE: The tableSize variable, which is set in the constructor using the
 * template variable passed, is a private function. In order to pass this out
 * to the user, the user will need to call this function which will return the
 * value of the table size.
 * OUTPUTS: none
*/
template <int ARRAY_LEN>
int HashTable<ARRAY_LEN>::getTableSize() {
    return tableSize;
}


/* FUNCTION: hashSum
 * CLASS MEMBER: Public
 * INPUTS: string bookTitle to hash, takes default template of hash table length
 * PURPOSE: Takes a string and converts each letter of the string to its ASCII
 * value, adds them up, and takes the modular remainder of the sum and the tableSize
 * which it returns as the index for that item in the lookupTable
 * OUTPUTS: the index of that given string in the lookupTable
*/
template <int ARRAY_LEN>
int HashTable<ARRAY_LEN>::hashSum(string bookTitle){
    int sum = -1;
    for (int i=0; i<bookTitle.length(); i++) {
        sum +=bookTitle[i];
    }
    return sum % tableSize;
}


/* FUNCTION: insertNode
 * CLASS MEMBER: Public
 * INPUTS: node to be inserted, takes default template of hash table length
 * PURPOSE: Takes a node to add to the lookup table, calls the hashSum function
 * to find which index the node will be inserted at. It checks to see if there
 * is currently anything at the index, if not it just adds it in, if there is,
 * it chains it to the end of the exisiting singly-linked list of data.
 * OUTPUTS: none
*/
template <int ARRAY_LEN>
void HashTable<ARRAY_LEN>::insertNode(ZippedBookNode* node) {
    // get the index by passing the title into the hashSum function
    int index = hashSum(node->title);
    if (lookupTable[index]->title == "empty") {
        // if that index is empty, put the node here
        lookupTable[index]->title = node->title;
        lookupTable[index]->c_excerpt = node->c_excerpt;
        lookupTable[index]->huff_root = node->huff_root;
        lookupTable[index]->next = node->next;
    }
    else {
        // if there is stuff at the index, traverse the index's linked list
        // using a traversing node, and when at the end of the linked list,
        // i.e. the pointer to *next is nullptr, link the new node to the end.
        // This negates the collision issue.
        ZippedBookNode *tmp = lookupTable[index];
        while (tmp->next != NULL) {
            if (tmp->title == node->title) {
                return;
            }
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}


/* FUNCTION: printTitles
 * CLASS MEMBER: Public
 * INPUTS: none, but takes default template of hash table length
 * PURPOSE: Iterates through the lookupTable indices and prints the record
 * stored there. For each index it checks to see if there are any other records linked
 * to the primary record, and if so prints it out too.
 * OUTPUTS: none
*/
template <int ARRAY_LEN>
void HashTable<ARRAY_LEN>::printTitles() {
    cout << endl;
    int length = tableSize;
    for (int i=0; i<length; i++) {
        ZippedBookNode *tmp = lookupTable[i];
        if (lookupTable[i]->title != "empty") {
            cout << i << " # ";
            cout << tmp->title;
            if (tmp->next) {
                while (tmp->next != nullptr) {
                    cout << " -> " << tmp->next->title;
                    tmp = tmp->next;
                }
            }
            cout << endl;
        }
    }   
}