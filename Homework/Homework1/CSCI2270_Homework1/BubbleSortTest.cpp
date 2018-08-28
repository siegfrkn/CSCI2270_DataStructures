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

int BubbleSort(GarageItem arrayOfGarageItems[]){
	// sort ascending
	//if (direction == 0){
	int length = 4;
		for (int i=0; i<length; i++){
			for (int j=0; j<length-1; j++){
				if (arrayOfGarageItems[j].type>arrayOfGarageItems[j+1].type){
					GarageItem swapType = arrayOfGarageItems[j];
					arrayOfGarageItems[j] = arrayOfGarageItems[j+1];
					arrayOfGarageItems[j+1] = swapType;
					//cout <<  arrayOfGarageItems[j+1] <<endl
					// string swapType = arrayOfGarageItems[j].type;
					// arrayOfGarageItems[j].type = arrayOfGarageItems[j+1].type;
					// arrayOfGarageItems[j+1].type = swapType;
					// int swapPrice = arrayOfGarageItems[j].price;
					// arrayOfGarageItems[j].price = arrayOfGarageItems[j+1].price;
					// arrayOfGarageItems[j+1].price = swapPrice;
					// int swapForSale = arrayOfGarageItems[j].forSale;
					// arrayOfGarageItems[j].forSale = arrayOfGarageItems[j+1].forSale;
					// arrayOfGarageItems[j+1].forSale = swapForSale;
				}
				}
			}
		//}
	return 0;
}


int main () {

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

	int sort = BubbleSort(arrayOfGarageItems);

	for (int i=0; i<4; i++){
		cout << arrayOfGarageItems[i].type << arrayOfGarageItems[i].forSale << arrayOfGarageItems[i].price << endl;
	}


	return 0;
}

