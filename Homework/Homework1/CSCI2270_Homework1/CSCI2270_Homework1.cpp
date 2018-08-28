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


int findItem(GarageItem arrayOfGarageItems[], string item){
	bool found = false;
	int index = -1;
	int x = 0;
	while (found == false && x<100){
		if (arrayOfGarageItems[x].type == item){
			found  = true;
			index = x;
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
					// GarageItem swapType = arrayOfGarageItems[j];
					// arrayOfGarageItems[j] = arrayOfGarageItems[j+1];
					// arrayOfGarageItems[j+1] = swapType;
					string swapType = arrayOfGarageItems[j].type;
					arrayOfGarageItems[j].type = arrayOfGarageItems[j+1].type;
					arrayOfGarageItems[j+1].type = swapType;
					int swapPrice = arrayOfGarageItems[j].price;
					arrayOfGarageItems[j].price = arrayOfGarageItems[j+1].price;
					arrayOfGarageItems[j+1].price = swapPrice;
					int swapForSale = arrayOfGarageItems[j].forSale;
					arrayOfGarageItems[j].forSale = arrayOfGarageItems[j+1].forSale;
					arrayOfGarageItems[j+1].forSale = swapForSale;
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
bool userExit =  0;
cout << "\n \n" << endl;
string welcomeImage = "\n  ooooooo8      o      oooooooooo       o       ooooooo8 ooooooooooo\no888    88     888      888    888     888    o888    88  888    88\n888    oooo   8  88     888oooo88     8  88   888    oooo 888ooo8\n888o    88   8oooo88    888  88o     8oooo88  888o    88  888    oo\n 888ooo888 o88o  o888o o888o  88o8 o88o  o888o 888ooo888 o888ooo8888\n\n oooooooo8      o      ooooo       ooooooooooo\n888            888      888         888    88                       \n 888oooooo    8  88     888         888ooo8\n        888  8oooo88    888      o  888    oo\no88oooo888 o88o  o888o o888ooooo88 o888ooo8888\n";
cout << welcomeImage << endl;
cout << "\n \n" << endl;
cout << "Katrina Siegfried\nCSCI2270 - Data Structures\nHomework 1" << endl;
cout << "\n \n" << endl;

while (userExit == 0){

	cout << "\n**********************WELCOME*********************" << endl;

	cout << "\n PLEASE ENTER A NUMBER FROM THE FOLLOWING OPTIONS" << endl;
	cout << "\n 1. FIND ITEM \n 2. BUY ITEM \n 3. ADD ITEM \n 4. PRINT LIST \n 5. SORTING ROUTINE METRICS \n 6. EXIT \n" << endl;

	cout << "**********************WELCOME*********************" << endl;

	int userInput = 0;

	cin >> userInput;
	cout << " " << endl;

	switch(userInput){
		case 1: {//cout << "1" << endl;
				cout << "ENTER THE NAME OF THE ITEM YOU ARE LOOKING FOR\n" << endl;
				string userFindItem;
				cin >> userFindItem;
				cout << " " << endl;
				int findItemIndex = findItem(arrayOfGarageItems, userFindItem);
				if (findItemIndex != -1){
					cout << "\nITEM FOUND\n" << endl;
					cout << arrayOfGarageItems[findItemIndex].type << " " << arrayOfGarageItems[findItemIndex].price << "\n" << endl;
					cout << "WOULD YOU LIKE TO BUY THE ITEM? Y/N\n" << endl;
					char buyOrNot;
					cin >> buyOrNot;
					if (buyOrNot == 'Y'){
						string removeItemOutput = removeItem(arrayOfGarageItems, findItemIndex);
						count = count-1;
						cout << removeItemOutput << endl;
						cout << "\n \n" << endl;
						Sleep(1000);
						break;
					}
					else{
						Sleep(500);
						break;
					}
				}
				else{
					cout << "\nITEM NOT FOUND\n" << endl;
					cout << "WOULD YOU LIKE TO ADD THE ITEM AS A WANTED ITEM? Y/N\n" << endl;
					char userYesNo;
					cin >> userYesNo;
					if (userYesNo == 'Y'){
						cout << "\nENTER THE PRICE OF THIS ITEM IN WHOLE DOLLARS\n" << endl;
						int userFindAddPrice;
						cin >> userFindAddPrice;
						int findItemIndex = findItem(arrayOfGarageItems, userFindItem);
						string tmp = addItem(arrayOfGarageItems, findItemIndex, userFindItem, userFindAddPrice);
						count = count+1;
						cout << "\nITEM ADDED\n" << endl;
						cout << "\n \n" << endl;
						Sleep(1000);
						break;
						}
					Sleep(500);
					break;
				cout << "\n \n" << endl;}
				}
		case 2: {cout << "\nENTER THE NAME OF THE ITEM YOU WOULD LIKE TO BUY\n" << endl;
				string userBuyItem;
				cin >> userBuyItem;
				int findItemIndex = findItem(arrayOfGarageItems, userBuyItem);
				string removeItemString = removeItem(arrayOfGarageItems, findItemIndex);
				cout << " " << endl;
				cout << removeItemString << endl;
				if (removeItemString == "ITEM NOT AVAILABLE"){
					cout << "\nWOULD YOU LIKE TO ADD THE ITEM AS A WANTED ITEM? Y/N\n" << endl;
					char userYesNo;
					cin >> userYesNo;
					if (userYesNo == 'Y'){
						cout << "\nENTER THE PRICE OF THIS ITEM IN WHOLE DOLLARS\n" << endl;
						int userBuyAddPrice;
						cin >> userBuyAddPrice;
						int findItemIndex = findItem(arrayOfGarageItems, userBuyItem);
						string tmp = addItem(arrayOfGarageItems, findItemIndex, userBuyItem, userBuyAddPrice);
						count = count+1;
						cout << "\nITEM ADDED\n" << endl;
						cout << "\n \n" << endl;
						Sleep(500);
						break;
						}
					else{
						count = count-1;
						Sleep(500);
						break;
					}
				}
				else{
					cout << arrayOfGarageItems[findItemIndex].type << " " << arrayOfGarageItems[findItemIndex].price << "\n" << endl;
					count = count -1;
					Sleep(1000);
					break;
				}
				Sleep(1000);
				break;}
		case 3: {cout << "\nENTER THE TYPE OF ITEM YOU WOULD LIKE TO ADD\n" << endl;
				string userAddItem;
				cin >> userAddItem;
				cout << "\nENTER THE PRICE OF THIS ITEM IN WHOLE DOLLARS\n" << endl;
				int userAddPrice;
				cin >> userAddPrice;
				int findItemIndex = findItem(arrayOfGarageItems, userAddItem);
				string tmp = addItem(arrayOfGarageItems, findItemIndex, userAddItem, userAddPrice);
				count = count+1;
				cout << "\nITEM ADDED\n" << endl;
				cout << "\n \n" << endl;
				Sleep(1000);
				break;}
		case 4: {cout << "\nGARAGE ITEMS" << endl;
				Sleep(500);
				for (int k=0; k<count; k++) {
					cout << arrayOfGarageItems[k].type << " "<< arrayOfGarageItems[k].price << endl;
				}
				cout << "\n \n" << endl;
				Sleep(500);
				break;}
		case 5: {cout << "LINKED LIST STUFF WILL GO HERE" << endl;
				int sortInt = BubbleSort(arrayOfGarageItems, 1, length);
				Sleep(500);
				// int start_sclock();
				// int stop_sclock();
				// cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SECOND)*1000 << endl;
				break;}
		case 6: {cout << "\nGOODBYE\n" << endl;
				userExit= 1;
				Sleep(100);
				break;}
		default: { cout << "\nPLEASE ENTER A VALID INPUT NUMBER (1, 2, 3, 4, 5, 6)\n" << endl;
				Sleep(500);
				break;}
	}
}



	// int findItemIndex = findItem(arrayOfGarageItems, "bike");
	// // deal with item if not found
	// string tmp = addItem(arrayOfGarageItems, findItemIndex, "bike", 1);

	for (int k=0; k<count; k++) {
		cout << arrayOfGarageItems[k].type << " "<< arrayOfGarageItems[k].forSale << " " << arrayOfGarageItems[k].price << endl;
	}

	//cout << count << endl;

		// Print the array

	return 0;
}



// type<type
// cost<cost