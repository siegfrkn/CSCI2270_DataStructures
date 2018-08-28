#include<iostream>
#include<string>

using namespace std;

string sentence = "Data Structure is awesome";
string wordToStrip = "Structure";

int sentenceSize = 0;
int wordToStripSize = 0;
int stripLocation = 0;

string stripWord(string sentence, string wordToStrip)
{
    if (sentence == "")
    {
        cout<<"Invalid sentence";
    }
    else
    {

        sentenceSize = sizeof(sentence);
        wordToStripSize = sizeof(wordToStrip);
        
        stripLocation = sentence.find(wordToStrip);
        sentence.erase(stripLocation, wordToStripSize); // accepts starting position and end positon / length; needs to be two integers

        cout<<sentence<<endl;
    }
    
    return "";
}