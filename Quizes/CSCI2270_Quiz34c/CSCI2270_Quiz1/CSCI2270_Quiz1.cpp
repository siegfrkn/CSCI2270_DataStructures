#include <iostream>
#include <string>
using namespace std;

string name,sentence;
string HelloDataStructures(string name, string hello);

string hello = "Hello, ";

string helloDataStructures(string name)
{
    if (name.empty())
    {
            cout<<"Invalid Sentence";
    }

    sentence = hello + name;
    const char *s = sentence.c_str();
    
    uint_32 i; 
    for(i=0; i<sentence.length(); i++) {
        cout<<sentence[i];
    }
}

int main()
{
    
    cout<<"What's your name? ";
    getline(cin,name);

    helloDataStructures(name);
    
    sentence = hello + name;
    
    //cout<<hello<<name<<endl;
    return 0;
}

