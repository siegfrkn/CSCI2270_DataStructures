#include <iostream>
#include <string>
using namespace std;

string hello, concat, sentence;
string name = "Giorgione";

string helloDataStructures(string name)
{
    //cout<<"What's your name? ";
        
    if (name.empty())
    {
        cout<<"Invalid sentence";
        string hello = "";
        string name = "";
        concat = hello + name;
    }
    else
    {
        string hello = "Hello ";
        concat = hello + name;
    }
    
    return concat;
}

int main() {
    
}
