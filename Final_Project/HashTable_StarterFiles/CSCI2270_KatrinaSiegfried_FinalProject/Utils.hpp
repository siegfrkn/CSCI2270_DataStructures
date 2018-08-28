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
struct HuffNode {
    
    char value = 'a';
    
};

class Utils {
    
public:
    // The following are stubs for you to start with. Change them accordigly to your needs. Add more elper functions and implement them.
    Utils();
    ~Utils();
    void computeFrequency();
    void huffEncode();
    void huffDecode();
    
    
    
};

#endif /* Utils_hpp */
