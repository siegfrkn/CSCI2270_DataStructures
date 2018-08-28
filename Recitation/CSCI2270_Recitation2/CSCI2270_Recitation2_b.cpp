// structs and class
// struct initialized with private variables
// class initialized with public variables

#include <iostream>
#include <string>

using namespace std;

struct ani {
	int for_sale = -1;
	string type = "Anmial";
	int price = -1;

	bool furry = true;

	void printStats(){
		cout << type;
		if (for_sale != 1)
		{
			cout << " is not for sale" << endl;
		}
		else{
			cout << " is not for sale for $" + to_string(price) << endl;
		}

		if (furry){
			cout << type + " is furry" << endl;
		}
		else {
			cout << type + " hurts" << endl;
		}
	}
};

class Animal
{
	public: // C++ classes default to private
	int for_sale = -1;
	string type = "Anmial";
	int price = -1;

	void printStats(){
		cout << type;
		if (for_sale != 1)
		{
			cout << " is not for sale" << endl;
		}
		else{
			cout << " is not for sale for $" + to_string(price) << endl;
		}

		if (furry){
			cout << type + " is furry" << endl;
		}
		else {
			cout << type + " hurts" << endl;
		}
	}
}

int main(){
	ani bunny;
	bunny.for_sale = 1;
	bunny.price = 10;
	bunny.type = "Hedgehog";
	bunny.furry = false; // will print out "Bunny hurts" when false

	bunny.printstats()
}

// QUIZ KEY: WaffleHouse