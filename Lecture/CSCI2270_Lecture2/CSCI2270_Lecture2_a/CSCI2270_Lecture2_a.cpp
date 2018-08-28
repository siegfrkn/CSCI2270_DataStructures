#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int length = 0;
int value = 0;

bool found = false;
int ind = 0;
int counter = 0;
int x = 0;
int*newarray = new int [length];


int*arrayShift(int inputarray[], int length, int value){
    
    // Copy the old array into the new array
    int k=0;
    for(k=0; k<length; k++){
        newarray[k] = inputarray[k];
    }
    
    // find the desired value
    while (found !=true && x<= length){
        if (newarray[x] == value){
            found = true;
            ind = x;
        }
        else{
            x++;
        }
    }
        int i;
        for (i=ind; i<=length; i++){
            newarray[i] = inputarray[i+1];
        }
        
        
        length = length-1;
    
    return newarray;
}

int main(){
    
}

// LECTURE NOTES
/*

Pointers
-variables that store address
-*, &
-* is also a dereference

int myInt = 5;
cout<<myInt<<endl;

int*myPtr = myInt;
cout<<myPtr<<endl;

int main() {
int * myPtr = null; // if I can set it right away to something meaningful, otherwise null
int myInt = 5;
myPtr = &myInt; // set myPtr to whatever is located at the address of myInt
cout<<myInt<<endl;  // prints out the value
cout<<&myInt<<endl; // prints out the address

// the * when it is not used in definition, it is used as dereference operator

cout<<myPtr<<endl;  // now that the pointer has been assigned an address, this is the address of myInt

cout<<*myPtr<<endl; // dereference the pointer, will get the value stored at that address, myInt

}

}

Struct

struct WeatherData {
    double temp;
    double humidity;
    double windVelocity;
}

// create an instance of a variable type WeatherData
WeatherData dp1;
// here we are really defining a pointer pointing to beginning of complex struct

// when you allocate memory using "new" you will have to delete that memory when you no longer need it
// the user has to do it because the processor only manages the stack (b/c we have the rules to do that)

// allocate memory
int * arr = new int [];
delete arr;

Array
- data structure
- static data
- what if we need more flexibility?
- effectively creating a pointer - dynamic memory allocation
- contiguous data in memory

// example
// command line arguments
// take a command line argument and store it into a contiguous block of memory associated with argv
int main (int argc, char*argv) {
    ....
}

// how do we access the argument? - index

// how do we translate into other data types?
// there are built in functions for that

// additional resouces on Moodle

// BE SURE TO MASTER POINTERS

// Lecture Quiz Key: zippo
// lecture quiz extended to Friday
// give a look to the youtube videos on the resource page

*/

