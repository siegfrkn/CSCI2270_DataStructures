#include<iostream>
#include<string>

using namespace std;

string sentence = "Data Structure is awesome";
string wordToStrip = "Structure";

string * ptrSentence = &sentence

// count the number of words by counting the spaces
int spaces = 0;
char characterIndex;
sentenceSize = sizeof(sentence);

for (int i=0; i<sentenceSize; i++){
	characterIndex = sentence[i];
	if (characterIndex == " "){
		spaces++;
	}
}
int wordCount = spaces+1;


string * ptrNewSentence = new string [wordCount];

int sentenceSize = 0;
int wordToStripSize = 0;
int stripLocation = 0;

string stripWord(string sentence, string wordToStrip)
{
	for (int i = 0; i<wordCount; i++){

	    if (sentence.empty())
	    {
	        cout<<"Invalid sentence";
	    }
	    else
	    {
	        sentenceSize = sentence.length();
	        wordToStripSize = wordToStrip.length()+1;
	        stripLocation = sentence.find(wordToStrip);
	        sentence.erase(stripLocation, wordToStripSize); // accepts starting position and end positon / length; needs to be two integers
	        
	        // nice built in function to handle
	        // sentence.find_first_not_of(" ");
	        // sentence.find_last_not_of(" ");

	        cout<<sentence<<endl;
	    }
	    
	    return "";
	}
}




    for (i=0; i<letterCount; i++){
        for (j=0; j<wordCount; j++){
            string sentenceCharacter;
            sentenceCharacter= sentence[i];
            if (sentenceCharacter == " "){
                j++; // go to the next word
            }
            else{
                //newSentence[j] = newSentence[j] + sentence[i];
                newSentence[j] = sentence[j];
            }
        }
        i++; // go to the next letter
    }


        for (i=0; i<letterCount; i++){
        sentenceCharacter = sentence[i];
        for (j=0; j<wordCount; j++){
            
            if (sentenceCharacter == " "){
                newSentence[j] = newSentence[j];
                //i++; // go to the next letter
                j = j+1;
            }
            
            else{
                newSentence[j] = newSentence[j] + sentence[i];
                //newSentence[j] = sentence[j];
            }
            i++;
        }
    }