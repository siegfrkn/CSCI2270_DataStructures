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