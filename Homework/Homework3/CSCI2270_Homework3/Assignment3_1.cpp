#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <ctime>


using namespace std;

#include "CommunicationNetwork.h"											// include the CommunicationNetwork header file

// main
int main(int argc, char **argv){											// main with input recorded in argv

	/*********************INSTANTIATE**********************/

	CommunicationNetwork();													// create an instance of the CommunicationNetwork class
	City *head = new City;													// create a newCity object called head to intialize.
	CommunicationNetwork Network;											// create an object of class CommunicationNetwork


	/*********************READ IN FILE*********************/

	string fileNameString = argv[1]; // read in the message.txt file
	string word, line; // define the string variables line and word for parsing
	ifstream fileStreamString(fileNameString);
	if (!fileStreamString.is_open()){
		cout << "Ignore Words file failed to open." << endl;
	}


	/********************USER INTERFACE*********************/

	bool userExit =  0;														// bool varible that will trigger user exit
	cout << "\n \n" << endl;
	cout << "Katrina Siegfried\nCSCI2270 - Data Structures\nHomework 3" << endl;
	cout << "\n \n" << endl;

	while (userExit == 0){													// while the user has not exited, keep the menu running

		cout << "\n**********************MAIN MENU*********************" << endl;

		cout << "\n PLEASE ENTER A NUMBER FROM THE FOLLOWING OPTIONS" << endl;
		cout << "\n 1. BUILD NETWORK \n 2. PRINT NETWORK PATH \n 3. TRANSMIT MESSAGE COAST-TO-COAST \n 4. ADD CITY \n 5. DELETE CITY \n 6. CLEAR NETWORK \n 7. QUIT \n" << endl;

		cout << "**********************MAIN MENU*********************" << endl;



		int userInput = 0;
		int userPrice = 0;

		cin >> userInput;
		cout << " " << endl;

		switch(userInput){

			/*********************BUILD NETWORK********************/
			case 1: {
				cout << "\nBUILD THE NETWORK\n" << endl;
				Network.buildNetwork();										// builds the initial doubly linked list of cities
				cout << "\n" << endl;
				break;
			}

			/*********************PRINT NETWORK********************/
			case 2: {
				cout << "\nPRINT THE NETWORK\n" << endl;
				Network.printNetwork();										// prints the list starting at the city head
				cout << "\n" << endl;
				break;
			}

			/*********************TRANSMIT MESS********************/
			case 3: {
				cout << "\nTRANSMIT MESSAGE COAST-TO-COAST\n" << endl;

				while(fileStreamString.good()){								// while the file is open and not at the end of the file
					getline(fileStreamString, line);						// get the first line from the file and call it line
					stringstream ss(line);									// turn the first line into a long string of substrings
					int inputLength = sizeof(line)/sizeof(line[0]);			// the length of the line is the size of the whole line divided by the size of the first element
					for (int i=0; i< inputLength; i++){ // OFF BY 1			// for the entire length of the string
						getline(ss, word, ' ');								// break the line string into substrings of words separated by ' '
						int wordLength = sizeof(word)/sizeof(word[0]);		// find the length of each particular word
						char *wordArray = new char[wordLength];				// create a new dynamically allocated array
						for (int j = 0; j<wordLength; j++){					// for each letter in the word
							wordArray[j] = word[j];							// the letter is assigned to the array
						}
						Network.transmitMsg(*&wordArray);					// transmit the message, passing by reference the word array of chars
						// line.erase(0, wordLength);
					}
					if (fileStreamString.eof()){							// check to see if the file is at he end
								break;										// break;
					}
				}
				cout << "\n" << endl;
				break;
			}

			/***********************ADD CITY**********************/
			case 4: {
				cout << "\nADD CITY\n" << endl;
				cout << "ENTER THE NAME OF THE CITY YOU WOULD LIKE TO ADD.\n" << endl;
				string addCityName;
				cin >> addCityName;
				cout << "\nWHERE IN THE NETWORK WOULD YOU LIKE TO ADD THIS CITY?" << endl;
				cout << "ENTER THE NAME OF THE PREVIOUS CITY IN THE NETWORK." << endl;
				cout << "TO ADD TO THE FRONT OF THE LIST, TYPE 'First', TO ADD" << endl;
				cout << "TO THE END OF THE LIST, ENTER EMPTY QUOTATIONS OR 'Last'.\n" << endl;
				string addCityPrevious;
				cin >> addCityPrevious;
				Network.addCity(addCityPrevious, addCityName);									// adds the city of Tampa to the end of the list
				cout << "\nCITY ADDED\n" << endl;
				break;
			}

			/**********************DELETE CITY*********************/				
			case 5: {
				cout << "\nDELETE CITY\n" << endl;
				cout << "ENTER THE NAME OF THE CITY YOU WOULD LIKE TO DELETE FROM THE NETWORK.\n" << endl;
				string deleteCityString;
				cin >> deleteCityString;
				Network.deleteCity(deleteCityString);
				cout << "\nCITY DELETED\n" << endl;
				break;
			}

			/********************CLEAR NETWORK********************/
			case 6:{
				cout << "\nCLEAR NETWORK\n" << endl;
				Network.~CommunicationNetwork();							// Call the destructor to remove the network
				cout << "\nNETWORK CLEARED\n" << endl;
				break;
			}

			/*************************QUIT************************/
			case 7: {
				cout << "\nYOU HAVE CHOSEN TO QUIT"<< endl;
				cout << "GOODBYE\n" << endl;
				userExit = 1;
				break;
			}
		}
	}
}