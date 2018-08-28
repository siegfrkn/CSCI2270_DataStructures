//
//  HashTable.cpp
//  
//
//  Created by cami on 7/19/18.
//
//

#include "HashTable.hpp"

using namespace std;

template <int ARRAY_LEN>
HashTable<ARRAY_LEN>::HashTable() {
    
    // TODO: initialize attributes
}

template <int ARRAY_LEN>
HashTable<ARRAY_LEN>::~HashTable() {
    
    // TODO: delete all the nodes. No need to delete the lookupTable because
    // it's created on the stack (thanks to our friend template we were able to
    // pass at initialization the size of the table)
}


template <int ARRAY_LEN>
int HashTable<ARRAY_LEN>::getTableSize() {
    
    // TODO: retrun the size of the table
    return -1;
}

template <int ARRAY_LEN>
int HashTable<ARRAY_LEN>::hashSum(string bookTitle){
    
    // TODO: create the hash function that will sum the ASCII values of the title
    return -1;
}

template <int ARRAY_LEN>
void HashTable<ARRAY_LEN>::insertNode(ZippedBookNode* node) {
    
    // TODO: insert the new node in the linkedlist.
    // Where will you insert the new node? How do you know that?
    // What cases should you consider?
    

    // What should you do in case of collision?

}


template <int ARRAY_LEN>
void HashTable<ARRAY_LEN>::printTitles() {
    
    // TODO: print out all the titles. Give the following output format:
    // 1) if the title is at the index it should be preceeded by '#'
    // 2) if the title is chained it should be precede by '->'
    // 3) items at the same index should be on the same line
    // example
    //          # test->test6->test12
    //          # test4->test5
    //          # test1->test11
    
}
