// RECITATION 2



/* Public vs Private
Public can be modii=fied outside the class
Private can only be directly modified outside the class
*/

// how to sort alphabetically
// homework directly compare strings

#include <iostream>
#include <string>
#include <time.h>

using namespace std;


// int recFactorial(int n){
// 	// recursive method
// 	if (n == 1){
// 		return 1;
// 	}
// 	else {
// 		return n*recFactorial(n-1);
// 	}
// }

// int manualFactorial(int n){
// 	int returnValue = 1;
// 	for (int i=1; i<=n; i++)
// 	{
// 		returnValue *= i;
// 	}
// 	return returnValue;
// }

// int main(){
// 	cout << recFactorial(30) << endl;
// 	cout << manualFactorial(30) << endl;
// }

struct node{
	int data = 0;
	node *next = NULL;
};

int main(){
	node * first = new node;
	node * second = new node;
	first -> next = second;
	second -> data = 2;
	cout << second -> data << endl;
	cout << first -> next << endl;
	return 0;
}



// QUIZ PASSWORD: IHOb