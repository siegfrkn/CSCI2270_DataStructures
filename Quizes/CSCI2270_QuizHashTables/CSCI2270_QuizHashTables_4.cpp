// QUIZ 18
//
//
//
// Created by Katrina Siegfried on 7/19/2018
//
// I MADE A LIBRARY!!!!



// include the necessary libraries and namespace
#include<iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <ctype.h>
#include <sstream>

using namespace std;



// create a struct called BookInfo that takes in title and
// isbn number, each of a different type defined by the
// template
template<class T, class S>
struct BookInfo {
	S title;
	T isbn;
};


// create a class called Library that has the following public
// and private attributes and functions. Utilizes a template for
// two different variable types
template<class T, class S>
class Library
{
public:
	Library(); // default constructor
	~Library(); // default destructor
	void addBook (S,T); 	// add a book to the virtual library array
	void getBook(S);	// get a book's info from the library
	T hashSum(S,T);		// use a string and length of hash table to generate and return a hash table index
	T sieve(T);		// use a prime sieve to return the smallest prime number greater than the length of the string to hash
	bool isNumber(S);	// checks to see if an input is a number, true if number, false otherwise
	string intToString(S);	// takes a value that is NOT a string and turns it into a string so hashing functions can be used.
private:
	int numBooks;	// intital number of books in the library, used for defining the array
	vector <BookInfo<T,S>> bookVector;		// the vector of BookInfo type that is our "library"
};


/* FUNCTION: Default Constructor
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: When an object of type "Library" is created it is "born" with the
 * following properties
 * OUTPUTS: void
*/
template<class T, class S>
Library<T,S>::Library() {
	vector <BookInfo<T,S>> bookVector;
}


/* FUNCTION: Default Destructor
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: When an object of type "Library"s destructor is called, this is how
 * it is destroyed.=
 * OUTPUTS: void
*/
template<class T, class S>
Library<T,S>::~Library() {
	bookVector.empty();
}


/* FUNCTION: isNumber
 * CLASS MEMBER: Public
 * INPUTS: s of type S (defined by template)
 * PURPOSE: Takes an input of type S (specified by template), checks if it
 * is a string or not
 * OUTPUTS: true if it is a number, false otherwise
*/
template<class T, class S>
bool Library<T,S>::isNumber(S s)
{
	string myString;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}
 
template<class T, class S>
string Library<T,S>::intToString(S notAstring) {
	string myString = to_string(notAstring);
	return myString;
}


/* FUNCTION: hashSum
 * CLASS MEMBER: Public
 * INPUTS: inputString of type S and tableSize of type T where S and T are
 * defined by the template
 * PURPOSE: Takes a string and a tableSize and uses the tableSize and the 
 * prime sieve function to generate the smallest prime number larger than
 * the tableSize^3, which is the smallest prime larger than the length of
 * the inputString
 * OUTPUTS: index of a hash table for given inputString
*/
template<class T, class S>
T Library<T,S>::hashSum(S inputString, T tableSize) {
	string myString = inputString;
	// }
	int sum = 0;
	for (T i=0; i<myString.length(); i++) {
		cout << "This is ASCII of " << myString[i] << ":" << (T)myString[i] << endl;
		sum += myString[i];
	}
	cout << "This is SUM: " << sum << endl;
	int giantPrime = tableSize * tableSize * tableSize;
	int primeMultiplier = sieve(giantPrime);
	cout <<  "The giant prime is " << primeMultiplier << endl;
	cout << "This is index: " << sum % tableSize << endl;
	return primeMultiplier * sum % tableSize;
}


/* FUNCTION: addBook
 * CLASS MEMBER: Public
 * INPUTS: title of type S and isbn of type T where S and T are defined by
 * the template
 * PURPOSE: Adds a book and its isbn to the library vector
 * OUTPUTS: none
*/
template<class T, class S>
void Library<T,S>::addBook (S title, T isbn) {
	BookInfo<T,S> tmp;
	tmp.title = title;
	bookVector.push_back(tmp);
}


/* FUNCTION: hashSum
 * CLASS MEMBER: Public
 * INPUTS: title of type S (defined by the template)
 * PURPOSE: Takes a title and searches the vector, returns the book info
 * if it is found!
 * OUTPUTS: none
*/
template<class T, class S>
void Library<T,S>::getBook(S title) {
	for (int i=0; i<(int)bookVector.size(); i++) {
		if (bookVector[i].title == title) {
			cout << "Book found: " << bookVector[i].title << endl;
		}
	}
}


/* FUNCTION: sieve
 * CLASS MEMBER: Public
 * INPUTS: number of type T as defined by the template
 * PURPOSE: Takes a number and finds the smallest prime number that is
 * larger than the input number and returns it
 * OUTPUTS: returns prime number of type T
*/
template<class T, class S>
T Library<T,S>::sieve(T numWords) {
	int limit = numWords*2;
	int * sieveArray = new int[limit];
	int primeBelow = 0;
	int primeAbove = 0;
	for (int k=0; k<limit; k++){
		sieveArray[k] = k;
	}
	for (int i=0; i< limit; i++) {
		sieveArray[i] = sieveArray[i] -1;
		for (int j=2; j<9; j++) {
			if (sieveArray[i] > j && sieveArray[i] % j == 0) {
				sieveArray[i] = 0;
			}
		}
	}
	for (int k=0; k<limit; k++){
		if (sieveArray[k] > primeBelow) {
			primeBelow = sieveArray[k];
		}
		if (primeBelow > numWords) {
			primeAbove = sieveArray[k];
			break;
		}
	}
	return primeAbove;
}


/* FUNCTION: main
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: Primary user interaction occurs here
 * OUTPUTS: none
*/
int main() {

	// hashTable<int,string,string> myHash; // how do I make that last one a pointer to a cust struct
	// int initialLength = 10;
	// string *bookShelfArray = new string[initialLength];

	Library<int,int> library;

	// string bookToAdd = "Forrest Gump";
	// // cout << typeid(string).name() << endl;
	// // int bookToAdd = 12;
	// int primeSize = sizeof(bookToAdd);
	// cout << "size of bookToAdd "<< bookToAdd << endl;
	// // int hashSizePrime = library.sieve(bookToAdd.length());
	// int hashSizePrime = library.sieve(primeSize);
	// cout << "Smallest prime greater than number of characters in " << bookToAdd << " is " << hashSizePrime << endl;
	// library.addBook(bookToAdd, 123);
	// library.getBook(bookToAdd);
	// library.hashSum(bookToAdd, hashSizePrime);


	int number = 894376;
	// library.isNumber(number);
	string output = library.intToString(number);

	// cout << endl;
	// string bookToAdd2 = "The Great Gatsby";
	// int hashSizePrime2 = library.sieve(bookToAdd2.length());
	// cout << "Smallest prime greater than number of characters in " << bookToAdd2 << " is " << hashSizePrime2 << endl;
	// library.addBook(bookToAdd2, 123);
	// library.getBook(bookToAdd2);
	// library.hashSum(bookToAdd2, hashSizePrime);
}

