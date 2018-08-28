#include <stdio.h>
#include <iostream>

using namespace std;

int power(int base, int exp){
	if (exp == 0){
		return 1;
	}
	else{
		return (base*power(base, exp-1));
	}
}


int main(){
	int base1 = 2;
	int exp1 = 4;
	int answer = power(base1, exp1);

	cout << answer << endl;

	return answer;
}