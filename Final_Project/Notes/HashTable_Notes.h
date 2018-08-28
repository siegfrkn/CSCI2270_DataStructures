//
//  Utils.hpp
//  
//
//  Created by cami on 7/19/18.
//
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>

/*
 
 Huffman findings/research discussion
 
 TODO: write a brief introduction on what you understood from the Huffman encoding. Make sure to explain the algorithm and the steps take for encoding and decoding.
 
 */




// The following is a stub for the nodes in your Huffman tree
struct huffNode {
    string title;
    double c_excerpt;
    *huffnode huff_root;
    huffnode *next;

    SllNode(string name, double e, *huffNode hr, )
    
    
};

class Utils {
    
public:
    // The following are stubs for you to start with. Change them accordigly to your needs. Add more elper functions and implement them.
    
    void computeFrequency();
    void huffEncode();
    void huffDecode()
    
    
    
};

class HashTable {
public:
	HashTable();
	HashTable(int tableSize);
	int HashSum(string, int); // the one we coded from lecture
	void insert();
private:
	ZippedNode *_lookupTable[tableSize];
	int tableSize = 0;
};

#endif /* Utils_hpp */
