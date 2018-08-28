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
                   
/*
Katrina Siegfried
CSCI 2270 - Data Structures
Instructor: Lambrocco

This code reads a comma and space delineated text file with garage sale data
and parses it into a custom struct, returns, and sorts.
*/

// Include libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <typeinfo>
#include <ctime>
#include <time.h>

using namespace std;


// Define a custom struct
struct GarageItem{
	string type;
	string sale;
	bool forSale; // 0 is for sale, 1 is wanted
	int sold; // 0 is unsold, 1 is sold
	int price;
};


// Define find item function that returns the index of the item in question, -1 otherwise
int findItem(GarageItem arrayOfGarageItems[], string item, int price){
	bool found = false;
	int index = -1;
	int x = 0;
	while (found == false && x<100){
		if (arrayOfGarageItems[x].forSale == 0){
			if (arrayOfGarageItems[x].type == item){
				if (price <= arrayOfGarageItems[x].price){
					found  = true;
					index = x;
					break;
				}
				else{
					x++;
					break;
				}
			}
			else{
				x++;
				//break;
			}
		}
		else{
			x++;
			//break;
		}
	}
	return index;
}


// add item to array function, returns string indicating success or failure
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
	arrayOfGarageItems[emptyIndex].forSale = 1; // wanted=1
	arrayOfGarageItems[emptyIndex].sale = " for sale";
	arrayOfGarageItems[emptyIndex].sold = 0;
	arrayOfGarageItems[emptyIndex].price = price;
	return "Item added successfully";
	// return emptyIndex;
}
else{

	return "Item already in list";
	// return emptyIndex;
}
}


// function to remove item, returns string indicating success or failure
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


// Bubble Sort function
double BubbleSort(GarageItem arrayOfGarageItems[], bool direction, int length){
   time_t Tbegin, Tend;
   time(&Tbegin);

		for (int i=0; i<length; i++){
			for (int j=0; j<length-1; j++){
				if (arrayOfGarageItems[j].type>arrayOfGarageItems[j+1].type){
					GarageItem swapType = arrayOfGarageItems[j];
					arrayOfGarageItems[j] = arrayOfGarageItems[j+1];
					arrayOfGarageItems[j+1] = swapType;
				}
			}
		}
	time (&Tend);
  	double elapsed_secs = difftime(Tend, Tbegin);
	return elapsed_secs;
}


// Quick Sort function
double quickSort(GarageItem A[], int left, int right){
	clock_t begin = clock();
	int i = left;
	int j = right;
	string pivot = A[(left+right)/2].type;
	while (i < j){
		while (A[i].type < pivot){
		i = i+1;
		}
		while (A[j].type > pivot){
		j =j-1;
		}
		if (i <= j){
		GarageItem temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i =i+1;
		j = j-1;
		}
	}
	if (left < j){
		quickSort (A, left, j);
	}
	if (i < right){
		quickSort (A, i, right);
	}
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	return elapsed_secs;
}


// Insertion Sort Function
double insertionSort( GarageItem A[], int count){
	clock_t begin = clock();
	for (int i=1; i<count; i++){
		string index = A[i].type;
		int j=i;
		while (j>0 && A[j-1].type>index){
			A[j].type = A[j-1].type;
			j=j-1;
		}
		A[j].type = index;
	}
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	return elapsed_secs;
}


// Main
int main(int argc, char **argv){

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
	int lineCount = 0;


	// ensure the file is "good" - i.e. not empty or at the end
	while(myFileStream.good()){
		count = count+1;
		// for each element in the array of Garage Items, enter data from text
		for (int j=0; j<100; j++){

			// only proceed if we aren't at the end of the file.
			if(!myFileStream.eof()){

				GarageItem compareStruct;

				getline(myFileStream, line);
				stringstream ss(line);
				getline(ss, compareStruct.type, ',');
				getline(ss, tmpForSale, ',');
				getline(ss, tmpPriceStringInt, ',');
				compareStruct.price = stoi(tmpPriceStringInt);

				if (tmpForSale == " wanted"){
					compareStruct.forSale = 1;
					compareStruct.sale = " wanted";
				}
				else{
					compareStruct.forSale = 0;
					compareStruct.sale = " for sale";
				}

				compareStruct.sold = 0; // all items initialized as unsold.
				arrayOfGarageItems[j] = compareStruct;

				count = count+1;

				for (int k=0; k<j; k++){

					if (arrayOfGarageItems[k].type == compareStruct.type){
						if (arrayOfGarageItems[k].sold ==0 && compareStruct.sold == 0){
						 	if (compareStruct.forSale == 1 && arrayOfGarageItems[k].forSale == 0){
								if (arrayOfGarageItems[k].price <= compareStruct.price){
									arrayOfGarageItems[j].sold = 1; // mark as wanted item that was matched to sort out later
									arrayOfGarageItems[k].sold = 1; // mark as sold to separate out later
									break;
								}
							}
						}
					}

				}
			
				if (tmpForSale == " wanted"){
					arrayOfGarageItems[j].forSale = 1;
				}
				else{
					arrayOfGarageItems[j].forSale = 0;
				}
			}
			// adjust count by number deleted
	for (int i=0; i< 100; i++) {
		if (arrayOfGarageItems[i].type == " "){
			removeItem(arrayOfGarageItems, i);
			count = count-1;
			i=i-1;
		}
	}

		}
	}

	// When we are done with the file, close it
	myFileStream.close();

	for (int i=0; i< 100; i++) {
		if (arrayOfGarageItems[i].sold == 1){
			count = count-1;
		}
	}

	count = count-1;


/***********************USER INTERFACE***********************/
bool userExit =  0;
cout << "\n \n" << endl;
string welcomeImage = "\n  ooooooo8      o      oooooooooo       o       ooooooo8 ooooooooooo\no888    88     888      888    888     888    o888    88  888    88\n888    oooo   8  88     888oooo88     8  88   888    oooo 888ooo8\n888o    88   8oooo88    888  88o     8oooo88  888o    88  888    oo\n 888ooo888 o88o  o888o o888o  88o8 o88o  o888o 888ooo888 o888ooo8888\n\n oooooooo8      o      ooooo       ooooooooooo\n888            888      888         888    88                       \n 888oooooo    8  88     888         888ooo8\n        888  8oooo88    888      o  888    oo\no88oooo888 o88o  o888o o888ooooo88 o888ooo8888\n";
cout << welcomeImage << endl;
cout << "\n \n" << endl;
cout << "Katrina Siegfried\nCSCI2270 - Data Structures\nHomework 1" << endl;
cout << "\n \n" << endl;

cout << "ORIGINAL READ-IN OF .TXT  FILE" << endl;
cout << "LINE-BY-LINE WITH MATCHES" << endl;
cout << "OMITTED AS FILE WAS READ IN\n" << endl;
cout << "ITEMS REMAINING IN THE MESSAGE BOARD AFTER READING ALL LINES IN THE FILE" << endl;
for (int k=0; k<100; k++) {
	if (arrayOfGarageItems[k].sold == 0 && arrayOfGarageItems[k].type != ""){
		cout << arrayOfGarageItems[k].type << " " << arrayOfGarageItems[k].sale << " " << arrayOfGarageItems[k].price << " " << arrayOfGarageItems[k].sold<<  endl;
	}
}
cout << "\n \n" << endl;
cout << "ITEMS SOLD" << endl;
for (int k=0; k<100; k++) {
	if (arrayOfGarageItems[k].sold == 1 && arrayOfGarageItems[k].type != ""){
		cout << arrayOfGarageItems[k].type << " " << arrayOfGarageItems[k].sale << " " << arrayOfGarageItems[k].price << " " << arrayOfGarageItems[k].sold<<  endl;
	}
}
cout << "\n \n" << endl;

while (userExit == 0){

	cout << "\n**********************WELCOME*********************" << endl;

	cout << "\n PLEASE ENTER A NUMBER FROM THE FOLLOWING OPTIONS" << endl;
	cout << "\n 1. MAKE ALL POSSIBLE MATCHES \n 2. PRINT LIST OPTIONS \n 3. SORTING ROUTINES AND METRICS \n 4. EXIT \n" << endl;

	cout << "**********************WELCOME*********************" << endl;

	int userInput = 0;
	int userPrice = 0;

	cin >> userInput;
	cout << " " << endl;

	switch(userInput){
		case 1: {cout << "\nREMOVE ALL POSSIBLE MATCHES FROM LIST\n" << endl;
				cout << "\nWITH FIRST MATCH REMAINING\n" << endl;
				for (int j=0; j<count; j++){
					for (int k=0; k<j; k++){
						if (arrayOfGarageItems[k].sold == 0 && arrayOfGarageItems[j].sold == 0){
						if (arrayOfGarageItems[j].type == arrayOfGarageItems[k].type){
							if (arrayOfGarageItems[j].forSale == 0 && arrayOfGarageItems[k].forSale == 1){
								if (arrayOfGarageItems[k].price >= arrayOfGarageItems[j].price)
									// removeItem(arrayOfGarageItems, j);
									arrayOfGarageItems[j].sold = 1; // mark as wanted item that was matched
									//j=j-1;
									arrayOfGarageItems[k].sold = 1; // mark as sold to separate out later
									break;
							}
						}
					}}
				}
				for (int r; r<count;r++){
					removeItem(arrayOfGarageItems, r);
					count = count-1;
				}
				Sleep(500);
				break;
				}
		case 2: {cout << "ITEMS REMAINING IN THE MESSAGE BOARD\n" << endl;
				for (int k=0; k<100; k++) {
					if (arrayOfGarageItems[k].sold == 0 && arrayOfGarageItems[k].type != ""){
						cout << arrayOfGarageItems[k].type << " " << arrayOfGarageItems[k].sale << " " << arrayOfGarageItems[k].price << " " << arrayOfGarageItems[k].sold<<  endl;
					}
				}
				cout << "\n \n" << endl;
				cout << "ITEMS SOLD\n" << endl;
				for (int k=0; k<100; k++) {
					if (arrayOfGarageItems[k].sold == 1 && arrayOfGarageItems[k].type != ""){
						cout << arrayOfGarageItems[k].type << " " << arrayOfGarageItems[k].sale << " " << arrayOfGarageItems[k].price << " " << arrayOfGarageItems[k].sold<<  endl;
					}
				}
				cout << "\n \n" << endl;
				Sleep(500);
				break;}
		case 3: {cout << "BUBBLE SORT" << endl;
				double sortBubbleInt = BubbleSort(arrayOfGarageItems, 1, count);
				for (int i=0; i<count; i++){
					cout << arrayOfGarageItems[i].type << arrayOfGarageItems[i].forSale << arrayOfGarageItems[i].price << endl;
				}
				cout << "BUBBLE SORT TIME ELAPSED: " << sortBubbleInt << endl;
				Sleep(500);
				cout << "\nQUICK SORT" << endl;
				double sortQuickInt = quickSort(arrayOfGarageItems, 0, count);
				for (int i=0; i<count; i++){
					cout << arrayOfGarageItems[i].type << arrayOfGarageItems[i].forSale << arrayOfGarageItems[i].price << endl;
				}
				cout << "QUICK SORT TIME ELAPSED: " << sortBubbleInt << endl;
				Sleep(500);
				cout << "\nINSERTION SORT" << endl;
				int sortInsertInt = insertionSort(arrayOfGarageItems, count);
				for (int i=0; i<count; i++){
					cout << arrayOfGarageItems[i].type << arrayOfGarageItems[i].forSale << arrayOfGarageItems[i].price << endl;
				}
				cout << "INSERTION SORT TIME ELAPSED: " << sortBubbleInt << endl;
				Sleep(500);
				break;}
		case 4: {cout << "\nGOODBYE\n" << endl;
				userExit= 1;
				Sleep(100);
				break;}
		default: { cout << "\nPLEASE ENTER A VALID INPUT NUMBER (1, 2, 3, 4, 5, 6)\n" << endl;
				Sleep(500);
				break;}
	}
}


	return 0;
}

