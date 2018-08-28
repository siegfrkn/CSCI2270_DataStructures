//
//  FinalProject.cpp
//  
//
//  STUDENT NAME:
//
//  DUE DATE: FRIDAY 7/27

#include <stdio.h>
#include <iostream>
// We need to include .cpp here because we are implementing the template class in .cpp.
// This is because the compiler needs to know the complete source code of the template when instantiating
// in other files like our FinalProject.cpp
#include "HashTable.cpp"

using namespace std;

// TODO: modify it accordingly as of the write up instruction
// Your main should have parameters as the program will run with command line
// arguments (correct the current behavior!)

int main() {

    // This is a quick test code that you can use as you complete your HashTable class
    // Uncomment the sections marked with /* ... */ as you implement the respective methods;
    
    // ********* Test create hashtable *********
    /*
    HashTable<2> myHashTable;
    int computedSizeOfTable = sizeof(myHashTable.lookupTable)/sizeof(myHashTable.lookupTable[0]);
    
    if (myHashTable.getTableSize() != computedSizeOfTable){
        cout<<"The table was not initialized correctly"<<endl;
    }
    
    else{
        cout<<"SUCCESS, initialized correctly, now let's add some stuff to it"<<endl;
        ZippedBookNode *testNode = new ZippedBookNode("test","0011", nullptr, nullptr);
     }

    */
    
    int index = -1;
    
    // ********* Test hash function *********
    /*
    try{
        index = myHashTable.hashSum(testNode->title);
        cout<<"This is the index in the table of your new node "<<index<<endl;
    }
    catch(int e){
        cout<<"Hash function is behaving weird"<<endl;
    }
    */
    
    // ********* Test insert **********
    /*
    myHashTable.insertNode(testNode);
    // add more nodes
    cout<<myHashTable.lookupTable[index]->title<<endl;
    */
    
    // ********* Test print  *********
    /*
    myHashTable.printTitles();
     */
    

    return 0;
    
}
