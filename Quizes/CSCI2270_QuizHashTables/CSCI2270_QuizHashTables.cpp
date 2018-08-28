// LECTURE 19
//
// temp.cpp
//
//
// Created by Katrina Siegfried on 7/18/2018
//

#include<iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

// use a type T to define values in this class
// where T is a placeholder for variables we will pass
template<class T, class S>
class RectangularPrism
{
public:
	RectangularPrism();
	~RectangularPrism();
	void setPrism(T, T, T);
	T getSurfaceArea();
	T getVolume();
	void getValues();
	T hashSum(S,T);
private:
	T W;
	T L;
	T D;
	T V;
	T Surface;
};



// HASH FUNCTION - LECTURE QUIZ
// computes the module with respect to size of table
// The tableSize is the maximum size I'm willing to allow my 
// hash table to be. I can scale it based on my input data
// will iterate through characters in string and add up ASCII values
template<class T, class S>
T RectangularPrism<T,S>::hashSum(S myString, T tableSize) {
	int sum = 0;
	for (T i=0; i<myString.length(); i++) {
		cout << "This is ASCII of " << myString[i] << ":" << (T)myString[i] << endl;
		sum +=myString[i];
	}
	cout << "This is SUM: " << sum << endl;
	// maybe instead of computing the sum of all characters of the string,
	// if "% tableSize" you will be able to store your value in the table
	// because it says I will contain anything less than my max size, and will
	// expell everything else. The mod division prevents us from having to have
	// a table that of length 100's+ - not feesible.
	return sum % tableSize;
}


template<class T, class S>
RectangularPrism<T,S>::RectangularPrism() {

}

template<class T, class S>
RectangularPrism<T,S>::~RectangularPrism() {

}

template<class T, class S>
void RectangularPrism<T,S>::setPrism (T length, T width, T depth) {
	W=width;
	L=length;
	D=depth;
}

template<class T, class S>
T RectangularPrism<T,S>::getVolume () {
	V = W*L*D;
	cout << "Volume = " << V << endl;
	return V;
}

template<class T, class S>
T RectangularPrism<T,S>::getSurfaceArea () {
	Surface = 2*W*L+2*W*D+2*D*L;
	cout << "Surface Area = " << Surface << endl;
	return Surface;
}

template<class T, class S>
void RectangularPrism<T,S>::getValues() {
	cout << "Length is: " << L << endl;
	cout << "Width is: " << W << endl;
	cout << "Depth is: " << D << endl;
}


int main() {

	/**************TEMPLATE**************/

	/* Playing around with template objects*/
	// T myVec[];
	// vector<T> myVec; // specifying a list of T's
	// vector<> myVec;	   // specifying a list just named myVec, compiler will complain

	/* Creating a class object using standard protocol */
	RectangularPrism<int,string> myPrism;
	// myPrism.setPrism(1,2,3);

	/* Creating a class object using TEMPLATE! */
	// instead of creating a whole new class, I can just redefine the types!
	// RectangularPrism<double> myPrism;
	// myPrism.setPrism(1.4364,2.77,3.135);

	// myPrism.getValues();
	// myPrism.getVolume();

	/****************HASH****************/

	// Call our HASH function
	cout << "This will be our index" << endl;
	myPrism.hashSum("ABC", 15);

	// What if we pass "ABCABC"?
	// Is "Forrest Gump" == "Gump Forrest"?
	// cout << "This will be our index" << endl;
	// hashSum("BCA", 15);
	// Oh no! Sum is the same! We call this collisionc
	// we have more than one possibility to get this result
}





/***************HASH FUNCTIONS***************/
/*
F(H) = function(hash)
H(x) = hash(x)

Hash functions are interesting, especially in math
because they are a particular set of functions that are
particularly difficult to invert -> H(x) ^-1

Finding the value of y is very very difficult without x
H(x)^-1 = y, y=f(x)=x+x

f(5) = 10 very easy if given x
What happens if you are given 10 without x? Very difficult

This -provides a great way to "hide" or "protect" info.
Hash functions are used for cryptography, white hat
security, bloom filters (hash tables that use hash functions)


			*
A 	B 	Z 	D 	myArray
0	1	2	3

How do we optimize a search function, so instead of going
through an array or a list item by item, how can we create
a function that gives us an index given our search item?
f(x) -> index ?
for example, f("D") -> 3

Create a structure with access time of 1 given a function,
MUST have access to hash function to make that happen

Now if I have the array, I can ask myArray[3] -> D
Well, here I'm asking for "D" and your just giving me "D" back
What if "D" was just a pointer to something much more complex.
What if we were able to create a table

0	|	obj	|->*
1	|	obj	|->*
2	|	obj	|->*
3	|	obj	|->*
4	|	obj	|->*
5	|	obj	|->*
6	|	obj	|->*

Saving a lot of space and saving time
Maybe the object is a movie, and
Movie1.name = "Forrest Gump"

0	|	Movie1	|->*
1	|	Movie2	|->*
2	|	Movie3	|->*
3	|	Movie4	|->*
4	|	Movie5	|->*
5	|	Movie6	|->*
6	|	Movie7	|->*

When I query f("Forrest Gump") -> index 0
Movie tmpMovie = hashTable[0];
to access all the good info about "Forrest Gump"

In the case explored above with the hashSum, where we give
two different values and get the same index, we call this
a collision.

Our Hash table is vertically is an array and it extends to
a linked list.
To truly avoid collisions, definitely not going to implement
a hash sum, but pseudo-random functions that a truely not
computable given the result.

//IMPLEMENT A HASH FUNCTION USING TEMPLATES WITH TEST CASES//

*/