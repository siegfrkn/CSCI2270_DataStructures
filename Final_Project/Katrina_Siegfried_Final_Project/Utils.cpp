//
//  Utils.cpp
//  
//
//  Created by cami on 7/19/18.
//  Modified by Katrina Siegfried 7/23/2018
//  CSCI 2270 - Data Structures
//  Final Project
//
//

// INCLUDE NECESSARY LIBRARIES AND NAMESPACES
#include "Utils.h"
#include "HashTable.h"
#include <string>
#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


/* OBJECT: frequencyQueue, *encode, *encryptedString, *decodedString
 * VARIABLE TYPE: Global
 * PURPOSE: Globally defines a priority_queue called frequencyQueue that is made
 * up of HuffNode pointers and uses a compare struct defined in the Utils.h file
 * to sort new indices when pushed in. Defined as global because the queue is
 * populated recursively. Also globally defines pointers that will be called between
 * the functions. In the future, the best thing for these variables would be to have
 * them live in the class as private members.
 * OUTPUTS: none
*/
priority_queue<HuffNode*, vector<HuffNode*>, compare> frequencyQueue;
string *encode = new string;
string *encryptString = new string;
string *decodedString = new string;

struct ZippedBookNode;

/* FUNCTION: default constructor for Utils class
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: Default constructor for Utils. When an object of type "Utils" is "born"
 * it will have the following attributes
 * OUTPUTS: none
*/
Utils::Utils(){

}


/* FUNCTION: default destructor for Utils class
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: Default destructor for Utils. When an object of type "Utils" is "killed"
 * it will have the following attributes
 * OUTPUTS: none
*/
Utils::~Utils(){

}


/* FUNCTION: createNode
 * CLASS MEMBER: Private
 * INPUTS: char letter, int freq HuffNode *right, HuffNode *left
 * PURPOSE: Takes the contents of what will be a new node, adds those things to it,
 * and returns it
 * OUTPUTS: new HuffNode pointer of the values passed in
*/
HuffNode* Utils::createNode(char letter, int freq, HuffNode* right, HuffNode* left) {
	HuffNode * node = new HuffNode();
	node->value = letter;
	node->frequency = freq;
	node->right = right;
	node->left = left;
	return node;
}


//TODO
/* FUNCTION: computeQueue
 * CLASS MEMBER: Private
 * INPUTS: HuffNode *node
 * PURPOSE: Takes a root of the psuedo-tree and recursively "in-order prints" the tree into
 * the frequencyQueue, this way, no chars are repeated!
 * OUTPUTS: none
*/
void Utils::computeQueue(HuffNode *node) {
    if(node) {
        if(node->left) {
            computeQueue(node->left);
        }
        if (node -> value != '$') {
            frequencyQueue.push(node);
        }
        if(node->right) {
            computeQueue(node->right);
        }
    }
}


//TODO
/* FUNCTION: huffEncode
 * CLASS MEMBER: Private
 * INPUTS: char charToEncrypt
 * PURPOSE: Uses the Huffman encoding algorithm to generate a tree that represents
 * the most commonly used char's with the fewest amount of bits possible without
 * prefixes
 * OUTPUTS: none
*/
void Utils::huffEncode(char charToEncrpyt){
    vector<HuffmanEncodeStruct*> huffmanCodeVectorTmp = huffmanCodeVector;
    HuffmanEncodeStruct *tmp = huffmanCodeVectorTmp.back();
    huffmanCodeVectorTmp.pop_back();
    while (tmp->value != charToEncrpyt) {
        tmp = huffmanCodeVectorTmp.back();
        if (tmp->value == charToEncrpyt) {
            break;
        }
        huffmanCodeVectorTmp.pop_back();
    }
    *encryptString = *encryptString + tmp->code;
    return;
}


/* FUNCTION: huffEncodeHelper
 * CLASS MEMBER: Private
 * INPUTS: ZippedBookNode *bookNode, string textString
 * PURPOSE: Takes in the book excerpt and calls huffEncode to place each char
 * in the correct place on the huffTree by creating little subnodes of two queue
 * objects each and pushing their roots back on to the queue and repeating until
 * they are all built.
 * OUTPUTS: none
*/
void Utils::huffEncodeHelper(ZippedBookNode *bookNode, string textString) {
    // we want all the sub-trees to have two children, so if the frequencyQueue
    // has an uneven length we can add a null characater to it so that it does
    // have an even number
    if (frequencyQueue.size()%2 == 0) {
        HuffNode *terminationChar = new HuffNode;
        terminationChar->value = '@';
        terminationChar->frequency = 1;
        terminationChar->right = nullptr;
        terminationChar->left = nullptr;
        frequencyQueue.push(terminationChar);
    }
    // declare the variables used to build the tree
    HuffNode *root = new HuffNode;
    HuffNode *tmpL = new HuffNode;
    HuffNode *tmpR = new HuffNode;
    HuffNode *rootLeft = new HuffNode;
    HuffNode *rootRight = new HuffNode;
    // make sure there isn't anything in the huff_root spot before we start
    bookNode->huff_root = nullptr;
    // while the list isn't empty, make our little subtrees using two elements
    // from the queue, and pushing their new miniroot with a frequency of both
    // the sub-frequencies combined, and pushing it back into the queue
    while (!frequencyQueue.empty()) {
        // make the left child
        tmpL = frequencyQueue.top();
        frequencyQueue.pop();
        rootLeft = tmpL;
        // make the right child
        tmpR = frequencyQueue.top();
        frequencyQueue.pop();
        rootRight = tmpR;
        // make the miniRoot
        HuffNode *miniTreeRoot = new HuffNode;
        miniTreeRoot->frequency = rootLeft->frequency + rootRight->frequency;
        miniTreeRoot->right = rootRight;
        miniTreeRoot->value = '$';
        miniTreeRoot->left = rootLeft;
        // push the mini root back into the queue
        frequencyQueue.push(miniTreeRoot);
    }
    // the last and only element in the list is the new root of the huffman tree
    // point the ZippedBookNode->huff_root to this element
    HuffNode *huffmanRoot = frequencyQueue.top();
    bookNode->huff_root = huffmanRoot;
    // call this function to generate the code for each char in the excerpt using
    // this tree we just built
    checkTreeHuffman(huffmanRoot);
    return;
}


/* FUNCTION: checkTreeHuffman
 * CLASS MEMBER: Private
 * INPUTS: HuffNode *node
 * PURPOSE: This function creates the codes for each char in the frequency queue. If
 * the char is to the left it adds a "0" to the  code and if it moves to the right it
 * adds a "1". This is remniscent of in-order printing of a BST. When the char has been
 * found at the leaf the code is pushed to the code vector which is used to encode the
 * actual excerpt.
 * OUTPUTS: true if new node is added, false otherwise.
*/
bool Utils::checkTreeHuffman(HuffNode *node){
    if(node) {
        if(node->left) {
            *encode = *encode + "0";
            checkTreeHuffman(node->left);
        }
        if (!node -> right && !node->left) {
            HuffmanEncodeStruct *newNode = new HuffmanEncodeStruct;
            newNode->value = node->value;
            newNode->code = *encode;
            huffmanCodeVector.push_back(newNode);
        }
        if(node->right) {
            *encode = *encode + "1";
            checkTreeHuffman(node->right);
        }
    }
    encode->pop_back();
    return false;
}


//TODO
/* FUNCTION: huffDecode
 * CLASS MEMBER: Public
 * INPUTS: ZippedBookNode *bookNode
 * PURPOSE: Uses the Huffman tree generated by this excerpt, whose root can be found at
 * ZippedBookNode->huff_root and uses the encrypted string to tell it which way to go in
 * the tree to find the right char, and adds the char to a new string that is decrypted.
 * I originally tried doing this recursively but never got it working properly.
 * OUTPUTS: none
*/
void Utils::huffDecode(ZippedBookNode *bookNode){
    if (!bookNode) {
        return;
    }
    // make sure the decoded string is empty before we start
    *decodedString = "";
    // create two HuffNodes, one points to the root of the tree, the other will be used
    // to step through our tree. Also create our string to decrypt by pulling it from the 
    // bookNode
    HuffNode *root = bookNode->huff_root;
    HuffNode *node = root;
    string stringToDecrypt = bookNode->c_excerpt;
    // A string is a dynamic array (vector) of chars. While the stringToDecrypt is not empty
    while (!stringToDecrypt.empty()) {
        // if there are no right, left nodes, then we are at a leaf node which is one of our
        // char's. If the char is the end of excerpt char(176) return we are done reading
        // them out. Otherwise, push the sequence of 1's and 0's to the decodedString using
        // the built-in function push_back() - remember a string is a vector of chars!
        if(!node->left && !node->right) {
            if (node->value == char(176)) {
                return;
            }
            else {
                decodedString->push_back(node->value);
                node = root;
            }
        }
        // if we aren't at a leaf node keep moving to the right (if a '1') or the left (if a '0')
        // as we move, erase a single char from the front of the stringToDecrypt.
        else {
            if (stringToDecrypt.front() == '0') {
                node = node->left;
            }
            else {
                node = node->right;
            }
            stringToDecrypt.erase(0,1);
        }
    }
    // we have now decoded the string! return the decoded string to the terminal
    cout << "DECODED:" << endl;
    cout << *decodedString << endl;
    return;
}


/* FUNCTION: printHuffTree
 * CLASS MEMBER: Public
 * INPUTS: HuffNode *node
 * PURPOSE: Uses recursion to in-order print a tree (or sub-tree) given a node of
 * type HuffNode
 * OUTPUTS: none, just the print out
*/
void Utils::printHuffTree(HuffNode *node) {
	if(node) {
        if(node->left) {
            printHuffTree(node->left);
        }
        if (node -> value != '$') {
	        cout << "" << node->value << ": " << node->frequency << endl;
        }
        if(node->right) {
            printHuffTree(node->right);
        }
    }
    return;
}


// ADD HUFF NODE FROM EXCERPT
/* FUNCTION: addHuffNode
 * CLASS MEMBER: Public
 * INPUTS: pointer to a string *excerptPtr, ZippedBookNode *bookNode
 * PURPOSE: Reads in the excerpt and char-by-char calls the helper function
 * checkTree which builds a little pseudo-tree to ensure that any char is added
 * only ONCE, and if it is already present in the tree, it increases the frequency,
 * then it calls the computeQueue function which builds the pseudo-tree into
 * the queue. Finally, it contains commented-out code that can print the priority
 * queue generated.
 * OUTPUTS: true if successful
*/
bool Utils::addHuffNode(string *excerptPtr, ZippedBookNode *bookNode){
    // lets make sure our containers for all of the stuff we are about to do are
    // empty before we begin
    frequencyQueue.empty();
    huffmanCodeVector.empty();
    *encode = "";
    *encryptString = "";
    // use our excerpt pointer to create a new string, excerpt
    string excerpt = *excerptPtr;
    // set our *hr HuffNode variable that is declared as a private member of the class
    // to have frequency of 1 and value of the first char in the string we want to encrypt
    // for all of the chars in the string to encrypt, pass our hr node we just made "as a
    // pseudo root" into the checkTreeQueue which builds a tree of the chars and
    // increases their frequency if they are already present. This concept takes inspiration
    // from the MovieTree homework/project 
    hr =  createNode(excerpt[0], 1, nullptr, nullptr);
    for (int i=1; i<excerpt.length(); i++) {
        bool notAlreadyInTree = checkTreeQueue(hr, excerpt[i]);
    }
    // call the compute queue function to turn the tree we build of the chars into a
    // priority queue that is full of HuffNodes
    computeQueue(hr);
    priority_queue<HuffNode*, vector<HuffNode*>, compare> huffmanQueue;
    // Because we built a tree once already using our HuffNodes (that are now in our
    // priority queue) we need to copy our queue so that the left and right pointers are
    // null so that we can use these HuffNodes to build a tree again. I tried just iterating
    // through the priority queue and setting them to nullptrs but came across a few
    // anomalies. At the end the frequencyQueue is reset to the new copied queue.
    while (!frequencyQueue.empty()) {
        HuffNode *node = frequencyQueue.top();
        HuffNode *newNode = new HuffNode;
        newNode->value = node->value;
        newNode->frequency = node->frequency;
        newNode->right = nullptr;
        newNode->left = nullptr;
        huffmanQueue.push(newNode);
        frequencyQueue.pop();
    }
    frequencyQueue = huffmanQueue;
    // call this function to build the huffman tree from the priority queue, this will also
    // create a vector of codes for each char
    huffEncodeHelper(bookNode, excerpt);
    // call the huffEncode function to use the vector of codes and encrypt the excerpt 
    for (int i=0; i<excerpt.length(); i++) {
        char toEncrpyt = excerpt[i];
        huffEncode(toEncrpyt);
    }
    // empty the pointer to the excerpt and then assign it the encryptString
    bookNode->c_excerpt = "";
    bookNode->c_excerpt = *encryptString;
    return true;
}


/* FUNCTION: checkTreeQueue
 * CLASS MEMBER: Private
 * INPUTS: HuffNode *node and char letter
 * PURPOSE: This is a helper function for addHuffNode that checks the char
 * value at all the nodes in the tree and compares them to pre-existing nodes.
 * If the value is not in the tree already, it adds it in, otherwise it increments
 * the frequency of that char.
 * OUTPUTS: true if new node is added, false otherwise.
*/
bool Utils::checkTreeQueue(HuffNode* node, char letter){
    if (hr){
         if (node -> value < letter ) {
            if (node -> right){
                    checkTreeQueue(node->right, letter);
            }
            else{
                node -> right = createNode(letter, 1, nullptr, nullptr);
                return true;
            }
         }
         if (node -> value > letter) {
            if (node -> left) {
                    checkTreeQueue(node -> left, letter);
            }
            else{
                node -> left = createNode(letter, 1, nullptr, nullptr);
                return true;
            }
        }
        if (node->value == letter) {
            node->frequency++;
        }
    }
        return false;
}