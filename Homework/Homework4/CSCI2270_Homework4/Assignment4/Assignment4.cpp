/*
Katrina Siegfried
CSCI 2270 - Data Structures
Week 5 - Extra Credit
main.cpp, bst_class.cpp, bst_class.h
*/


/*
 *    ####### #     # #       ### #     # #######         
 *    #     # ##    # #        #  ##    # #               
 *    #     # # #   # #        #  # #   # #               
 *    #     # #  #  # #        #  #  #  # #####           
 *    #     # #   # # #        #  #   # # #               
 *    #     # #    ## #        #  #    ## #               
 *    ####### #     # ####### ### #     # #######  
 *       
 *    #     # ####### #     # ### #######                 
 *    ##   ## #     # #     #  #  #                       
 *    # # # # #     # #     #  #  #                       
 *    #  #  # #     # #     #  #  #####                   
 *    #     # #     #  #   #   #  #                       
 *    #     # #     #   # #    #  #                       
 *    #     # #######    #    ### ####### 
 *                
 *     #####  ####### ######  #     # ###  #####  ####### 
 *    #     # #       #     # #     #  #  #     # #       
 *    #       #       #     # #     #  #  #       #       
 *     #####  #####   ######  #     #  #  #       #####   
 *          # #       #   #    #   #   #  #       #       
 *    #     # #       #    #    # #    #  #     # #       
 *     #####  ####### #     #    #    ###  #####  ####### 
 *                                                        
 *                                                      
 *   Because this assignment definitely used to be a movie       
 *   rental store but they don't exist anymore...
 */



// include necessary libraries and namespaces
#include <fstream>				
#include <sstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "MovieTree.h"
using namespace std;


// begin the main function which contains all the basic user interfacing
int main(int argc, char **argv){

	/*********************INSTANTIATE**********************/
	/* create our class member using the default constructor
	 * and pull in the file passed at runtime via argv[1] and
	 * call the readInFileFunc to read in the contents of the
	 * comma delimited file and store in the BST/LL structure.
	 * Define the bool variable userExit that will trigger an
	 * exit of the program.
	*/

	MovieTree();
	MovieTree myMovieTree;

	string fileName = argv[1];
	myMovieTree.readInFileFunc(fileName, myMovieTree);

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
	cout << "1. Find a Movie" << endl;
	cout << "2. Rent a Movie" << endl;
	cout << "3. Print the Inventory" << endl;
	cout << "4. Delete a Movie" << endl;
	cout << "5. Count the Movies" << endl;
	cout << "6. Quit" << endl;
	cout << "7. BONUS: Add Movie" << endl;
	cout << "8. BONUS: Delete Entire BST" << endl;
	cout << "9. BONUS: Delete Nodes Recursively in Post-Order"<< endl;
	cout << "\n" << endl;

	string userChoice;													
	getline(cin, userChoice);

	while (!isdigit(userChoice[0])) {
		cout << "\nInvalid selection. Please try again." << endl;
		cout << "Enter only integer numbers 1-8." << endl;
		getline(cin, userChoice);
	}									
										
	int userInput = stoi(userChoice);
	switch(userInput){	


	/********************FIND A MOVIE*********************/
	/* Call the public function findMovie that is a member
	 * of the MovieTree class to search the BST and then
	 * the associated linked list for a movie node. User
	 * input taken via getline and printouts are handled
	 * by the function.
	*/

	case 1: {
		cout << "\nEnter title" << endl;
		string movieTitleSearch;
		getline(cin, movieTitleSearch);
		myMovieTree.findMovie(movieTitleSearch);	
		break;
	}


	/********************RENT A MOVIE*********************/
	/* Call the public function rentMovie that is a member
	 * of the MovieTree class to search the BST and then
	 * the associated linked list for a movie node. User
	 * input taken via getline and printouts are handled
	 * by the function. This function is very similar to
	 * findMovie except it decrements the quantity by one
	 * and handles deletions as neccessary when quantity
	 * is zero.
	*/

	case 2: {
		cout << "\nEnter title" << endl;
		string movieTitleRent;
		getline(cin, movieTitleRent);
		myMovieTree.rentMovie(movieTitleRent);	
		break;
	}


	/*****************PRINT THE INVENTORY*****************/
	/* Call the public function printMovieInventory that
	 * is a member of the MovieTree class. This function
	 * traverses the BST recursively and then prints out
	 * the content of the BST's singly linked list.
	*/

	case 3: {
		cout << "\n" << endl;
		myMovieTree.printMovieInventory();
		cout << "\n" << endl;
		break;
	}


	/*******************DELETE A MOVIE*******************/
	/* Call the public function deleteMovieNode that is a
	 * member of the MovieTree class. This function handles
	 * all of the edge cases of deleting a node from a BST
	 * and/or linked list as indicated by the movie's node
	 * as entered by the user.
	*/

	case 4: {
		cout << "\nEnter title" << endl;
		string movieTitleDelete;
		getline(cin, movieTitleDelete);
		myMovieTree.deleteMovieNode(movieTitleDelete);
		break;
	}


	/******************COUNT THE MOVIES******************/
	/* Call the public function countMovieNodes that is
	 * a member of the Movie Tree class to recursively
	 * count all of the nodes in the tree and linked list.
	 * This is a count of all the nodes, not of all of
	 * the "total quantities" of movie copies.
	*/

	case 5: {
		int movieCount = myMovieTree.countMovieNodes();
		cout << "Tree contains " << movieCount << " movies." << endl;
		break;
	}


	/************************QUIT************************/
	/* This changes the bool variable userExit to 1 which
	 * causes the switch case loop to exit.
	*/

	case 6: {
		cout << "\nGoodbye!\n" << endl;
		userExit = 1;	
		break;
	}


	/******************BONUS: ADD MOVIE******************/
	/* This is a bonus functionality that allows the user
	 * to add movies to the system, and if the movie is
	 * already in the system, they will be asked if they
	 * would like to overwrite or add to the existing
	 * quantity.
	*/

	case 7: {
		int addMovieRank, addMovieYear, addMovieQuantity;
		string addMovieTitle, addMovieRankString, addMovieYearString, addMovieQuantityString;
		cout << "Enter the title of the movie you would like to add:" << endl;
		getline(cin, addMovieTitle);
		cout << "What is the ranking of " << addMovieTitle << "?" << endl;
		getline(cin, addMovieRankString);
		addMovieRank = stoi(addMovieRankString);
		cout << "What year was " << addMovieTitle << " released?" << endl;
		getline(cin, addMovieYearString);
		addMovieYear = stoi(addMovieYearString);
		cout << "How many copies of " << addMovieTitle << " are you adding to the database?" << endl;
		getline(cin, addMovieQuantityString);
		addMovieQuantity = stoi(addMovieQuantityString);
		myMovieTree.addMovieNode(addMovieRank, addMovieTitle, addMovieYear, addMovieQuantity);
		break;
	}



	/***************BONUS: DELETE ENTIRE BST**************/
	/* This case will call the destructor of the entire BST
	 * and will clear it out. The program does request the
	 * user confirm their selection before proceeding.
	*/

	case 8: {
		cout << "\THIS WILL DELETE THE ENTIRE TREE!\n" << endl;
		cout << "Are you sure you want to continue? Y/N" << endl;
		string userConfirm;
		getline(cin, userConfirm);
		if (userConfirm == "Y"){
			myMovieTree.~MovieTree();
			break;
		}
		break;
	}


	/***************BONUS: DELETE ENTIRE BST**************/
	/* This case will call the destructor of the entire BST
	 * and will clear it out. The program does request the
	 * user confirm their selection before proceeding.
	*/

	case 9: {
		cout << "\THIS WILL DELETE ENTIRE NODES IN THE TREE!\n" << endl;
		cout << "Are you sure you want to continue? Y/N" << endl;
		string userConfirmDA;
		getline(cin, userConfirmDA);
		if (userConfirmDA == "Y"){
			string deleteAllPostOrder;
			cout << "\nWhat is the letter/number of the node you would like to delete?" << endl;
			getline(cin, deleteAllPostOrder);
			myMovieTree.DeleteALL(deleteAllPostOrder);
			break;
		}
		break;
	}


	/**********************DEFAULT**********************/
	/* This is the default case that handles all user
	 * input htat does not match a case.
	*/

	default: {				
		cout << "\nPLEASE ENTER A VALID INPUT NUMBER (1, 2, 3, 4, 5, 6, 7, 8, or 9)\n" << endl;
		break;
	}
	}
	}

	return 0;
}