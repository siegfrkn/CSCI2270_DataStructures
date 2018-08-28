//
//  HashTable.hpp
//  
//
//  Created by cami on 7/19/18.
//
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include <iostream>
#include "Utils.hpp"

struct ZippedBookNode {
    // Book's title
    std::string title;
    // Book's body compressed and encoded in 0s and 1s according to Huffman encoding
    double c_excerpt;
    // Root of the huffman tree. Note that this is a HuffNode!
    // Where is the HuffNode decleared?
    // How can we access it? (look at the top of the file)
    HuffNode* huff_root;
    // Pointer to the next node.
    // Why do we need this?
    // What should it be initialized to?
    ZippedBookNode* next;
    
    ZippedBookNode()
    {
        
    }
    
    ZippedBookNode(std::string name, double e, HuffNode* hr, ZippedBookNode* n)
    {
        //TODO: initialize attributes
    }
};


template <int ARRAY_LEN>
class HashTable {
    
public:
    // Default constructor
    HashTable();
    
    ~HashTable();
    
    int getTableSize();
    // Compute the index. This will be the location where you will place the new node (not quite, right?)
    int hashSum(std::string bookTitle);
    
    // Add new node to the table
    void insertNode(ZippedBookNode* node);
    
    void printTitles();

    // What are we doing here?
    ZippedBookNode* lookupTable[ARRAY_LEN];
    
private:
    
    int tableSize;
};



#endif /* HashTable_hpp */
