/*
  //   _____          _____            _____ ______ 
  //  / ____|   /\   |  __ \     /\   / ____|  ____|
  // | |  __   /  \  | |__) |   /  \ | |  __| |__   
  // | | |_ | / /\ \ |  _  /   / /\ \| | |_ |  __|  
  // | |__| |/ ____ \| | \ \  / ____ \ |__| | |____ 
  //  \_____/_/    \_\_|  \_\/_/__  \_\_____|______|
  //  / ____|  /\   | |    |  ____|                 
  // | (___   /  \  | |    | |__                    
  //  \___ \ / /\ \ | |    |  __|                   
  //  ____) / ____ \| |____| |____                  
  // |_____/_/    \_\______|______|                 
*/                                                 
                   


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <typeinfo>
#include <ctime>

using namespace std;

struct GarageItem{
	string type;
	bool forSale;
	int price;
};


int findItem(GarageItem arrayOfGarageItems[], string item, int price){
	bool found = false;
	int index = -1;
	int x = 0;
	while (found == false && x<100){
		if (arrayOfGarageItems[x].type == item){
			if (arrayOfGarageItems[x].price <= price){
				found  = true;
				index = x;
			}
		}
		else{
			x++;
		}
	}
	return index;
}


// add item to array
string addItem(GarageItem arrayOfGarageItems[], int index, string item, int price){
	int emptyIndex = -1;
	if (index == -1){

	// find the first empty spot

	for (int i=0; i<100; i++){
		if (arrayOfGarageItems[i].type == ""){
			emptyIndex = i;
			break;
		}
	}

	// add the item
	arrayOfGarageItems[emptyIndex].type = item;
	arrayOfGarageItems[emptyIndex].forSale = 1;
	arrayOfGarageItems[emptyIndex].price = price;
	return "Item added successfully";
	// return emptyIndex;
}
else{

	return "Item already in list";
	// return emptyIndex;
}
}


string removeItem(GarageItem arrayOfGarageItems[], int index){
	if (index != -1){ // item found in the list
		for(int n=index; n<100-1; n++){
			arrayOfGarageItems[n] = arrayOfGarageItems[n+1];
		}
		return "\nYOU HAVE PURCHASED THIS ITEM SUCCESSFULLY\n";
	}
	else{
		return "ITEM NOT AVAILABLE";
	}
}

int BubbleSort(GarageItem arrayOfGarageItems[], bool direction, int length){
	// sort ascending
	//if (direction == 0){
		for (int i=0; i<length; i++){
			for (int j=0; j<length-1; j++){
				if (arrayOfGarageItems[j].type>arrayOfGarageItems[j+1].type){
					GarageItem swapType = arrayOfGarageItems[j];
					arrayOfGarageItems[j] = arrayOfGarageItems[j+1];
					arrayOfGarageItems[j+1] = swapType;
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


int main(int argc, char **argv){
// int main(){

	/***********************OPEN THE FILE***********************/
	string fileString = argv[1];
		//cout << "Please enter data file name with file extension: " << endl;
	//cin >> fileString;
	// cout << "The file name entered is: " << fileString << endl;
	ifstream myFileStream(fileString);

	if (!myFileStream.is_open()){
		cout << "File failed to open." << endl;
	}
	
	/***********************DATA TO ARRAY***********************/
	GarageItem *arrayOfGarageItems = new GarageItem[100];
	string type, forSale;
	string tmpPriceStringInt;
	string priceString;
	string line;
	string tmpForSale;
	int length = 100;
	int count = 0;


	// ensure the file is "good" - i.e. not empty or at the end
	while(myFileStream.good()){

		// for each element in the array of Garage Items, enter data from text
		for (int j=0; j<100; j++){

			// only proceed if we aren't at the end of the file.
			if(!myFileStream.eof()){

				// pull in data, change forSale to bool and price to int
				getline(myFileStream, line);
				stringstream ss(line);
				getline(ss, arrayOfGarageItems[j].type, ',');
				getline(ss, tmpForSale, ',');
				getline(ss, tmpPriceStringInt, ',');
				arrayOfGarageItems[j].price = stoi(tmpPriceStringInt);

				if (tmpForSale == " wanted"){
					arrayOfGarageItems[j].forSale = 1;
				}
				else{
					arrayOfGarageItems[j].forSale = 0;
				}

			}

		// count the number of items in the array
		if (arrayOfGarageItems[j].type != ""){
			count = count+1;
		}

	}

}
	
	// When we are done with the file, close it
	myFileStream.close();


/***********************USER INTERFACE***********************/




	// int findItemIndex = findItem(arrayOfGarageItems, "bike");
	// // deal with item if not found
	// string tmp = addItem(arrayOfGarageItems, findItemIndex, "bike", 1);

	

	//cout << count << endl;

		// Print the array

	return 0;
}



// type<type
// cost<cost