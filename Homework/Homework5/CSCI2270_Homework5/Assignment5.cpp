// KATRINA SIEGFRIED
// CSCI2270 - DATA STRUCTURES
// ASSIGNMENT 5




#include<vector>
#include<iostream>
#include<string>
#include <fstream>                                                         
#include <sstream>
#include <cstdlib>
#include <ctype.h>
#include"Graph.h"

using namespace std;

int main(int argc, char **argv) {

	/*********************INSTANTIATE**********************/
	/* create our class member using the default constructor
	 * and pull in the file passed at runtime via argv[1] and
	 * call the readInFileFunc to read in the contents of the
	 * comma delimited file and store in the BST/LL structure.
	 * Define the bool variable userExit that will trigger an
	 * exit of the program.
	*/

	Graph();
	Graph zombieGraph;

	string fileName = argv[1];
	zombieGraph.readInFileFunc(fileName, zombieGraph);

	bool userExit = 0;

	while(!userExit){


	/**********************MAIN MENU***********************/
	/* Build the main menu with the user input choices. The
	 * getline function is used to take user input and
	 * store it in the userChoice variable string which is
	 * then stored to int. This will be used to navigate the
	 * case loop on which the menu is based.
	*/
	cout << "\n======Main Menu======" << endl;
	cout << "1. Print vertices" << endl;
	cout << "2. Vertex Adjacent" << endl;
	cout << "3. Find Districts" << endl;
	cout << "4. Find Shortest Path" << endl;
	cout << "5. Find Shortest Weighted Path" << endl;
	cout << "6. Quit" << endl;
	cout << "\n" << endl;

	string userChoice;													
	getline(cin, userChoice);

	while (!isdigit(userChoice[0])) {
		cout << "\nInvalid selection. Please try again." << endl;
		cout << "Enter only integer numbers 1-6." << endl;
		getline(cin, userChoice);
	}									
										
	int userInput = stoi(userChoice);
	switch(userInput){	


		/*******************PRINT VERTICES********************/
		case 1: {
			// zombieGraph.printVertices(zombieGraph);
			zombieGraph.displayEdges();
			break;
		}


		/*******************VERTEX ADJACENT********************/
		case 2: {
			cout << "\nEnter first city" << endl;
			string firstCityString;
			int adjacentResult = 0;
			getline(cin, firstCityString);
			cout << "\nEnter second city" << endl;
			string secondCityString;
			getline(cin, secondCityString);
			adjacentResult = zombieGraph.isAdjacent(firstCityString, secondCityString); 
			if (adjacentResult == 1) {
				cout << "\nTrue" << endl;		// Cities are adjacent
			}
			else {
				cout << "\nFalse" << endl;	// Cities are not adjacent
			}
			break;
		}


		/********************FIND DISTRICTS********************/
		case 3: {
			zombieGraph.assignDistricts();
			break;
		}


		/******************FIND SHORTEST PATH******************/
		case 4: {
			cout << "\nEnter a starting city" << endl;
			string startingCityString;
			getline(cin, startingCityString);
			cout << "\nEnter second city" << endl;
			string endingCityString;
			getline(cin, endingCityString);
			zombieGraph.shortestPath(startingCityString, endingCityString);
			break;
		}



		/**************FIND SHORTEST WEIGHTED PATH**************/
		case 5: {
			cout << "\nEnter a starting city" << endl;
			string startingCityString;
			getline(cin, startingCityString);
			cout << "\nEnter second city" << endl;
			string endingCityString;
			getline(cin, endingCityString);
			zombieGraph.shortestWeightedPath(startingCityString, endingCityString);
			break;
		}

		/************************QUIT************************/
		case 6: {
			cout << "\nGoodbye!\n" << endl;
			userExit = 1;	
			break;
		}
	}
}
}