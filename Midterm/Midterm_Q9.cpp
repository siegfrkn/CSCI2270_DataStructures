#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


int *func2(int *z){
	int *a = new int;
	*a = *z + 5;
	return a;
}

int main(){
	
	int b = 5;
	int *a;
	a = &b;
	int *c = func2(a);
	cout<<*c<<endl;
}