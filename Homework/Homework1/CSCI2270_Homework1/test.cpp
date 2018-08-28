#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <typeinfo>

using namespace std;

struct GarageItem{
	string type;
	bool forSale;
	int price;
};


int main(){
	GarageItem *arrayOfGarageItems = new GarageItem[4];

	arrayOfGarageItems[0].type = "chicken";
	arrayOfGarageItems[0].forSale = 1;
	arrayOfGarageItems[0].price = 60;
	arrayOfGarageItems[1].type = "microwave";
	arrayOfGarageItems[1].forSale = 0;
	arrayOfGarageItems[1].price = 201;
	arrayOfGarageItems[2].type = "bike";
	arrayOfGarageItems[2].forSale = 1;
	arrayOfGarageItems[2].price = 60;
	arrayOfGarageItems[3].type = "bike";
	arrayOfGarageItems[3].forSale = 0;
	arrayOfGarageItems[3].price = 50;

	for (int i=0; i<4; i++){
		cout << arrayOfGarageItems[i].type << arrayOfGarageItems[i].forSale << arrayOfGarageItems[i].price << endl;
	}
	return 0;
}