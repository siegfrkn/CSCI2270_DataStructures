#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void myFunction(int *c){

*c = 10;

} 

int main( ){

int *a = new int;

int b = 5;

int *a2 = &b;

//call myFunction here
myFunction(&b);

}

