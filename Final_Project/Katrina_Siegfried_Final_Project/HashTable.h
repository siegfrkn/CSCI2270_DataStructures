//
//  HashTable.hpp
//  
//
//  Created by cami on 7/19/18.
//  Modified by Katrina Siegfried 7/23/2018
//  CSCI 2270 - Data Structures
//  Final Project
//
//


// INCLUDE NECESSARY LIBRARIES AND NAMESPACES
#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#include <iostream>
#include "Utils.h"
#include <queue>


// Create the structure of a ZippedBookNode
struct ZippedBookNode {
    // Book's title
    std::string title;
    // Book's body compressed and encoded in 0s and 1s according to Huffman encoding
    std::string c_excerpt;
    // Root of the huffman tree. Note that this is a HuffNode!
    // Where is the HuffNode decleared?
    // How can we access it? (look at the top of the file) - including the utils header file
    HuffNode* huff_root;
    // Pointer to the next node.
    // Why do we need this?
    // What should it be initialized to?
    ZippedBookNode* next;
    

    // Default constructor for a ZippedBookNode object, if nothing is passed into it, be empty
    ZippedBookNode()
    {
        title = "";
        c_excerpt = "";
        huff_root = nullptr;
        next = nullptr;
    }
    
    // Overloaded default constructor for a ZippedBookNode object
    ZippedBookNode(std::string name, std::string e, HuffNode* hr, ZippedBookNode* n)
    {
        //TODO: initialize attributes
        title = name;
        c_excerpt = e;
        huff_root = hr;
        next = n;
    }
};


// create a dynamic (by size) HashTable Object with the following properties. It is not really
// dynamic, it is a static object that will live on the stack, but has the flexibility to change
// its size at declaration thanks to the template, versus being statically defined in the code
template <int ARRAY_LEN>
class HashTable {
    
public:
    HashTable(); // default constructor of HashTable object
    ~HashTable(); // default destructor of HashTable object
    int getTableSize();// return the tableSize (which is a private variable of this class, not accessible to user)
    int hashSum(std::string bookTitle); // Compute the index. This will be the location where you will place the new node (not quite, right?)
    void insertNode(ZippedBookNode* node); // Add new node to the table
    void printTitles();
    ZippedBookNode* lookupTable[ARRAY_LEN]; // instantiate your hashTable object which is a "static" array of ARRAY_LEN
private:
    int tableSize; // private member tableSize that is equal to ARRAY_LEN
};



#endif /* HashTable_hpp */
