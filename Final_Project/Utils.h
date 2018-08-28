//
//  Utils.hpp
//  
//
//  Created by cami on 7/19/18.
//  Modified by Katrina Siegfried 7/23/2018
//  CSCI 2270 - Data Structures
//  Final Project
//
//


// INCLUDE NECESSARY LIBRARIES AND NAMESPACES
#ifndef Utils_h
#define Utils_h

#include <stdio.h>
#include <iostream>
#include <queue>
#include <HashTable.h>
#include <vector>
#include <queue>

/*
 
 Huffman findings/research discussion
 
The Huffman tree algorithm, is a greedy algorithm that uses a series of optimal local choices, with
the goal of obtaining a global optimum (though it is not garunteed). The basic concept is that various
chars will be encrypted using variable bit lengths versus fixed, which means fewer total bits will be
needed for encoding. Using a set prefix, chars that appear more frequently will be encoded with shorter
bit lengths than those that appear less frequently. The encoding is done using a special binary search
tree, where all of the chars to be encoded are located on the leaf nodes, and the internal nodes are
empty values with frequencies equal to the sum of their left and right children. The tree is built be-
ginning with the least commonly appearing chars added first, and most commonly appearing added later on.
Versus traditional BST building, the Huffman tree is built using an ordered list of nodes. The lowest
frequency chars are popped off, and become the children of a null character node with a frequency equal
to the sum if their children. This node is then pushed back on to the ordered list, and the process
repeats until there is only one node left in the tree - this is the root of the new huffman tree. The
encoding occurs when reading the tree. For each char to be encypted the tree is traversed to the
leaf node containing that char. On the path from root to char, a '0' is designated for movement in one
direction on the tree (i.e. left) and a '1' designated for moving the other way (i.e. right). The con-
catenation of these 1's and 0's becomes the code for that particular char. This results in more commonly
appearing chars located higher on the tree, and thus havhing shorter encryption codes. It must be
considered that a certain length of file is required to justify this encryption algorithm. Furthermore,
the tree-building algorithm or the tree itself must also be transmitted in order to decide the info,
which also takes up space.
 */


// Tell the following objects and instances, there is this thing called a ZippedBookNode that
// is a user defined struct. It's not important what it is right now, but know that it does
// exist
struct ZippedBookNode;

// The following is a stub for the nodes in your Huffman tree
// Define the basic structure of a HuffNode
struct HuffNode {
    int frequency;
    char value = char(176);
    HuffNode *left;
    HuffNode *right;
    
};


// Define the overload for '()' that when passed two HuffNode pointers, compares
// the both of them and returns true if one is bigger than the other, false
// otherwise.
struct compare {
    bool operator () (HuffNode *n1, HuffNode *n2) {
        return n1->frequency > n2->frequency;
    }
};


// define a new struct called HuffmanEncodeStruct where we can temporarily store the
// value of the char and its huffman code from the tree. This is used to encode the
// string. 
struct HuffmanEncodeStruct {
	char value;
	std::string code;
};


// Create a class called Utils with the following properties
class Utils {
    
public:
    // The following are stubs for you to start with. Change them accordigly to your needs. Add more elper functions and implement them.
    Utils(); // default constructor for Utils object
    ~Utils(); // default destructor for the Utils object
    void huffDecode(ZippedBookNode*); // decodes the encrypted string using the pointer to root of huff tree
	void printHuffTree(HuffNode*); // uses recursion to print a tree in order
    bool addHuffNode(std::string*, ZippedBookNode*); // build a huff tree, encrypt the excerpt, and point the excerpt to its ZippedBookNode
private:
    void huffEncode(char); // uses the vector with the huffman code to encrypt the excerpt
    void computeQueue(HuffNode*); // this "builds a little pseudo tree" with the excerpt of the node passed and pushes them to priority queue
    HuffNode* createNode(char, int, HuffNode*, HuffNode*); // gives birth to a node given information
    void huffEncodeHelper(ZippedBookNode*, std::string); // builds the huffman code
    HuffNode *hr; // create a pointer to HuffNode that can be called between functions of this class
	bool checkTreeQueue(HuffNode*, char); // helper function to addHuffNode that checks if the char is already in helper "pseudo-tree" and if so increases frequency
    bool checkTreeHuffman(HuffNode*); // helper function to addHuffNode that generates the code for each char
	std::vector<HuffmanEncodeStruct*> huffmanCodeVector; // instantiate an object called huffmanCodeVector that is a vector of HuffmanEncodeStruct pointers
};

#endif /* Utils_hpp */
