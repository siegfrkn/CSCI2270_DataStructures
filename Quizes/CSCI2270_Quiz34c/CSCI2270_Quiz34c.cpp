// Pre-Conditions
// sentence must be a string
// wordToStrip must be a string
// No built-in functions

// Post-Conditions
// sentence is stripped of wordToStrip
// The edited sentence is returned

// Algorithm
/* This function takes in two inputs, the sentence and the word to strip. It then
   breaks the sentence string into a new array of strings where each index is a
   word from the original sentence.
   1. Check to make sure the sentence is valid, i.e. not empty
   2. Count the number of words
   3. Creates a new array where each index is a word
   4. Compare each index to the wordToStrip, if it matches, make it empty
   5. Print out all indices on same line with appropriate spacing
   6. Delete dynamically allocated variables
*/   




/****************************CODE BEGINS HERE**********************************/
/******************************************************************************/


/******************Include standard libraries and namespace********************/


#include <iostream>
#include <string>

using namespace std;


/**************************FUNCTION BEGINS HERE********************************/


string stripWord(string sentence, string wordToStrip)
{


/**************Make sure the sentence is valid, i.e. not empty*****************/
    
    if (sentence == ""){
        cout << "Invalid sentence" << endl;
    }


/************* Count the number of words by counting the spaces ***************/
    
    int spaces = 0;
    string characterIndex;
    int letterCount = 0;
    for (int n=0; sentence[n] != '\0'; n++){
        characterIndex = sentence[n];
        letterCount++;
        if (characterIndex == " "){
            spaces++;
        }
    }
    
    int wordCount = spaces+1; // the number of words is one more than the number of spaces


/******Create a new sentence array of strings and fill it with each word*******/
    
    string * newSentence = new string[wordCount]; // size dependent on input so dynamically allocate newSentence
    int i = 0; // iterate through the letters
    int j = 0; // iterate through the words
    string sentenceCharacter; // to hold the index value from the original sentence
    
    // iterate over each letter, when there is a space, jump to the next index in newSentence
    for (i=0,j=0; i<letterCount && j<wordCount;){
        sentenceCharacter = sentence[i];
        
        if (sentenceCharacter == " "){
            //newSentence[j] = newSentence[j];
            //i++; // go to the next letter
            j = j+1;
            i++;
        }
        
        else{
            newSentence[j] = newSentence[j] + sentence[i];
            //newSentence[j] = sentence[j];
            j=j;
            i++;
        }
    }
    
    
/*******Compare the words in the array newSentence to the wordToStrip*********/
    
    int m=0;
    for (m=0; m<wordCount; m++){
        // if the wordToStrip is found, make the index blank
        if (newSentence[m] == wordToStrip){
            newSentence[m] = "";
        }
    }
    

/********************************Print it out*********************************/
    
    int k = 0;
    // print each word then a space
    for (k=0; k<wordCount-1; k++){
        if (newSentence[k] == ""){
            k++;
        }
        cout<<newSentence[k] << " ";
    }
    cout<<newSentence[wordCount-1]; // print the last word/index by itself so you don't print the space after

    delete [] newSentence; // clean up the memory space because newSentence was dynamically allocated
    return ""; // needs to return something
}