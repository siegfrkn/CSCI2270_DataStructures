// Katrina Siegfried
// CSCI2270 - Data Structures
// Homework 3 - Communication Between Towers
// Assignment3.cpp to be compiled with CommunicationNetwork.cpp
//
//     ______    ___   ____    ____  ____    ____                      
//   .' ___  | .'   `.|_   \  /   _||_   \  /   _|                     
//  / .'   \_|/  .-.  \ |   \/   |    |   \/   |                       
//  | |       | |   | | | |\  /| |    | |\  /| |                       
//  \ `.___.'\\  `-'  /_| |_\/_| |_  _| |_\/_| |_                      
//   `.____ .' `.___.'|_____||_____||_____||_____|                     
//   _________    ___   ____      ____  ________  _______     ______   
//  |  _   _  | .'   `.|_  _|    |_  _||_   __  ||_   __ \  .' ____ \  
//  |_/ | | \_|/  .-.  \ \ \  /\  / /    | |_ \_|  | |__) | | (___ \_| 
//      | |    | |   | |  \ \/  \/ /     |  _| _   |  __ /   _.____`.  
//     _| |_   \  `-'  /   \  /\  /     _| |__/ | _| |  \ \_| \____) | 
//    |_____|   `.___.'     \/  \/     |________||____| |___|\______.' 
//                                                                     
				
#include <fstream>															// include necessary libraries
#include <sstream>
#include <string>

using namespace std;														// include the standard namespace

#include "CommunicationNetwork.h"											// include the CommunicationNetwork header file

// main
int main(int argc, char **argv){											// main with input recorded in argv

	/*********************INSTANTIATE**********************/

	CommunicationNetwork();													// create an instance of the CommunicationNetwork class
	City *head = new City;													// create a newCity object called head to intialize.
	CommunicationNetwork Network;											// create an object of class CommunicationNetwork


	/********************USER INTERFACE*********************/

	bool userExit =  0;														// bool varible that will trigger user exit
	cout << "\n \n" << endl;
	cout << "Katrina Siegfried\nCSCI2270 - Data Structures\nHomework 3" << endl;
	cout << "\n \n" << endl;

	while (userExit == 0){													// while the user has not exited, keep the menu running

		cout<< 																// print out this cute little art
		"TTTTTT  OOO  W     W EEEE RRRR   SSS " << "\n"
		"  TT   O   O W     W E    R   R S " << "\n"
		"  TT   O   O W  W  W EEE  RRRR   SSS" << "\n"
		"  TT   O   O  W W W  E    R R       S" << "\n"
		"  TT    OOO    W W   EEEE R  RR SSSS " << "\n"
		  << endl;
		                                                                                                                       
		cout <<																// print the main menu options
		"\n**********************MAIN MENU*********************"
		<< endl;

		cout <<
		"\n PLEASE ENTER A NUMBER FROM THE FOLLOWING OPTIONS" << endl;
		cout << "\n 1. BUILD NETWORK \n 2. PRINT NETWORK PATH \n"
		" 3. TRANSMIT MESSAGE COAST-TO-COAST \n 4. ADD CITY \n "
		"5. DELETE CITY \n 6. CLEAR NETWORK \n 7. QUIT \n" << endl;

		cout << "**********************MAIN MENU*********************"
		<< endl;


		string userChoice;													// create a string called userChoice that takes in user input
		getline(cin, userChoice);											// use getline to store user input
		int userInput = stoi(userChoice);									// go from string to int - further work needs to be done to throw exception if not valid int

		switch(userInput){													// use a switch case structure to organize menu options

			/*********************BUILD NETWORK********************/
			case 1: {														// CASE 1: BUILD THE NETWORK
				cout << "\nBUILD THE NETWORK\n" << endl;
				Network.buildNetwork();										// builds the initial doubly linked list of cities
				cout << "\n" << endl;
				break;
			}

			/*********************PRINT NETWORK********************/
			case 2: {														// CASE 2: PRINT THE NETWORK
				cout << "\nPRINT THE NETWORK\n" << endl;
				Network.printNetwork();										// prints the list starting at the city head
				cout << "\n" << endl;
				break;
			}

			/*********************TRANSMIT MESS********************/
			case 3: {														// CASE 3: TRANSMIT MESSAGE COAST-TO-COAST
				cout << "\nTRANSMIT MESSAGE COAST-TO-COAST\n" << endl;
				string line; 												// define the string variable line
				string fileNameString = argv[1]; 							// read in the message.txt file
				ifstream fileStreamString(fileNameString);
				if (!fileStreamString.is_open()){							// spit out an erro if it doesn't open
					cout << "Ignore Words file failed to open." << endl;
				}
				while(fileStreamString.good()){								// while the file is open and not at the end of the file
					getline(fileStreamString, line);						// get the first line from the file and call it line
					stringstream ss(line);									// turn the first line into a long string of substring
					char *ptrline = &line[0];								// create a character pointer to the first char in the line string
					Network.transmitMsg(ptrline);							// pass the char pointer to transmit the message in te network
					if (fileStreamString.eof()){							// check to see if the file is at he end
						break;												// break;
					}
					delete ptrline;											// delete dynamically allocated variable
				}
				fileStreamString.close();									// close the file when we are done with it
				cout << "\n \n" << endl;
				break;
			}

			/***********************ADD CITY**********************/
			case 4: {														// CASE 4: ADD CITY
				cout << "\nADD CITY\n" << endl;
				cout << "ENTER THE NAME OF THE CITY YOU WOULD LIKE TO ADD.\n" << endl;
				string addCityName;											// define variable string for user input
				getline(cin, addCityName, '\n');							// get user input and store to addcityname
				cout << "\nWHERE IN THE NETWORK WOULD YOU LIKE TO ADD THIS CITY?" << endl;
				cout << "ENTER THE NAME OF THE PREVIOUS CITY IN THE NETWORK." << endl;
				cout << "TO ADD TO THE FRONT OF THE LIST, TYPE 'First', TO ADD" << endl;
				cout << "TO THE END OF THE LIST JUST HIT ENTER (CARRIAGE RETURN).\n" << endl;
				string addCityPrevious;										// define variable string for user input
				getline(cin, addCityPrevious);								// get user input and store to addcityprevious
				Network.addCity(addCityPrevious, addCityName);				// adds the city at the right position in the list
				cout << "\n \n" << endl;
				break;
			}

			/**********************DELETE CITY*********************/				
			case 5: {														// CASE 5: DELETE CITY
				cout << "\nDELETE CITY\n" << endl;
				cout << "ENTER THE NAME OF THE CITY YOU WOULD LIKE TO DELETE FROM THE NETWORK.\n" << endl;
				string deleteCityString;									// define variable string for user input
				getline(cin, deleteCityString);								// get user input and store as deleteCityString
				Network.deleteCity(deleteCityString);						// call function to delete city string
				cout << "\n \n" << endl;
				break;
			}

			/********************CLEAR NETWORK********************/
			case 6:{														// CASE 6: CLEAR NETWORK
				cout << "\nCLEAR NETWORK\n" << endl;
				Network.~CommunicationNetwork();							// Call the destructor to remove the network
				cout << "\nNETWORK CLEARED\n" << endl;
				break;
			}

			/*************************QUIT************************/
			case 7: {														// CASE 7: QUIT
				cout << "\nYOU HAVE CHOSEN TO QUIT"<< endl;
				cout << "GOODBYE\n" << endl;
				userExit = 1;												// change userExit bool to true, will cause switch case to end
				break;
			}
			default: {														// DEFAULT: If a proper number wasn't chosen, let the user know
				cout << "\nPLEASE ENTER A VALID INPUT NUMBER (1, 2, 3, 4, 5, 6, or 7)\n" << endl;
			break;}
		}
	}
	delete head;															// delete dynamically allocated data when we are done
}


/*
C:\Users\katri.WINDOWS-I21LG7M\Desktop\SUBLIME_FILES\CSCI2270\Homework\CSCI2270_Homework3
g++ -std=c++11 Assignment3.cpp CommunicationNetwork.cpp -o hw3
hw3 message.txt
*/