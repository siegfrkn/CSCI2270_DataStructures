#include<iostream>
#include<string>

using namespace std;


int* myFunc(){
	int* myIntPtr = new int[2];
	myIntPtr[0] = 1;
	myIntPtr[1] = 7;

	cout << myIntPtr[0] << endl;
	cout << myIntPtr << endl;

	return 0;
}


int main(){

	myFunc();

	return 0;
}