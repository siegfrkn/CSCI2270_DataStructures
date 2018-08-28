// THIS VERSION HAS PARSING TO COMPARE INPUT FILE TO IGNORE WORDS


/* Include libraries and namespace needed for file to build
 * and run properly
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <typeinfo>
#include <ctime>
#include <time.h>
#include <tgmath.h>

using namespace std;



/* a user-defined struct for object WordItem
 * composed of a string (single word) and 
 * an integer that counts the number of times it has appeared
*/
struct WordItem {
	string word;
	int count = 0;
};



/* define a singly linked list for object WordItems
 * each node contains a WordItem object and a pointer
 * to the next node in the SLL
*/
struct Node{
	WordItem wordItem;
	WordItem *next;
};



/* Function name: get StopWords
 * Purpose: read stop word list from file and store it into an array
 * @param ignoreWordFile - filename (the file storing ignore words)
 * @param ignoreWords - store ignore words from the file (pass by reference)
 * @return - none
 Note: the number of words is fixed to 50
 */
void getStopWords(string fileIgnoreWordsString, string arrayIgnoreWords[50]){

	// define local variable
	int ignoreCount = 0;
	string line;
	string word;

	// open the ignore words txt file
	ifstream myFileIgnoreWordsStream(fileIgnoreWordsString);

	// ensure the file is "good" - i.e. not empty or at the end
	while(myFileIgnoreWordsStream.good()){
		ignoreCount = ignoreCount + 1;

			// only proceed if we aren't at the end of the file.
			if(!myFileIgnoreWordsStream.eof()){
				for (int i=0; i<50; i++){
					getline(myFileIgnoreWordsStream, line);
					stringstream ss(line);
					getline(ss, word);
					arrayIgnoreWords[i] = word;
					ignoreCount++;
				}
			}
	}

	// if the file doesn't open, let the user know
	if (!myFileIgnoreWordsStream.is_open()){
		cout << "Ignore Words file failed to open." << endl;
	}

	// free up memory and close the file when we are done with it
	myFileIgnoreWordsStream.close();
}



/* Function name: isStopWord
 * Purpose: to see if a word is a stop word
 * @param ignoreWords - the array of strings storing ignore/ stop words
 * @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, string arrayIgnoreWords[]){

	bool compareStopWord = false;
	string stopWord;

	for (int j=0; j<50; j++){

		stopWord = arrayIgnoreWords[j];

		if (word == stopWord){
			compareStopWord = true;
			break;
		}
		// else{
		// 	compareStopWord = false;
		// 	break;
		// }
	}
	//cout << compareStopWord << endl;
	return compareStopWord;
}



/* Function name: getTotalNumberNonStopWords
 * Purpose: compute the total number of words saved in the words array (including
 * repeated words)
 * @param list - an array of wordItems containing non-stop words
 * @param length - the length of the words array
 * @return - the total number of words in the words array (including repeated words multiple times)
*/
int getTotalNumberNonStopWords(WordItem list[], int length){

	return 0;
}



/* Function name: arraySort
 * Purpose: sort an array of wordItems, decreasing, byt their count fields
 * @param list - an array of wordItems to be sorted
 * @param length - the length of the words array
*/
void arraySort(WordItem list[], int length){

}




/* Function name: addWordArray
 * Purpose: add data from file into an array
 * @param int *arraySize - pointer to arraySize variable
 * @param WordItem *& arrayALLwordss - pass by reference to pointer of WordItem
 * @param string textWord - word from text
 * @param int textCount - counter for all the words in the text
 * @return - none
*/
void addWordArray(WordItem *& arrayWords, string textWord, int textCount, int arrayCount){
	arrayWords[arrayCount].word = textWord;
	arrayWords[arrayCount].count = textCount;
}



/* Function name: doubleArray
 * Purpose: double the size of our dynamically allocated array
 * @param int *arraySize - pointer to arraySize variable
 * @param WordItem *& arrayUniqueWords - pass by reference to pointer of WordItem
 * @return - none
*/
void doubleArray(WordItem *& arrayUniqueWords, int *arraySize){
	*arraySize = *arraySize*2;
	WordItem *tmpArray = new WordItem[*arraySize];
	for (int i = 0; i<*arraySize/2; i++){
		tmpArray[i] =arrayUniqueWords[i];
	}
	delete[] arrayUniqueWords;
	arrayUniqueWords = tmpArray;
}



/* Function name: readInFileArray
 * Purpose: read in data to dynamically allocated array ONLYif it is NOT an ignore word
 * and don't dupicate words, only increase their count
 * @param int *arraySize - pointer to arraySize variable
 * @param WordItem *& arrayUniqueWords - pass by reference to pointer of WordItem
 * @return arrayCount - number of unique words
*/
int readInFileArray(string fileMainString, int *arraySize, WordItem *&arrayUniqueWords, string arrayIgnoreWords[]){

	// open the hunger games txt file
	ifstream myMainFileStream(fileMainString);

	// initialize the variables, arrays
	string word;
	string line;
	string singleLine;
	int count;
	int arrayCount = 0;
	size_t position = 0;
	string delimiter = " ";
	size_t nposition = 0;
	bool compareWord = false;
	int doubleArrayCounter = 0;

	// if the file is "good" (not empty or at end) pull all the data out into array
	while (myMainFileStream.good()){

		// get the data one line at a time, and parse each line by spaces into words
		getline(myMainFileStream, line);
		stringstream lineStream(line);
		getline(lineStream, singleLine);
		nposition = singleLine.size();
		while ((position = singleLine.find(delimiter)) <= nposition){
			if (nposition == delimiter.size()){
				break;
			}

			// if the array size is the same size as the number of elements, double it to make space
			if (arrayCount == *arraySize){		
				doubleArray(arrayUniqueWords, arraySize);
				doubleArrayCounter = doubleArrayCounter + 1;
			}

			// each word is separated by spaces
			word = singleLine.substr(0,position);

			// Compare to the stop word
			compareWord = isStopWord(word, arrayIgnoreWords);
			if (compareWord != true){
				addWordArray(arrayUniqueWords, word, 0, arrayCount);
				arrayCount++;
			}

			// erase the line to the end of the word just read so the cycle can be repeated for the next word
			singleLine.erase(0, position + delimiter.length());
			nposition = singleLine.size();
		}
	}

	//cout << doubleArrayCounter << endl;
	//cout << arrayCount << endl;

	// if the file doesn't open, let the user know
	if (!myMainFileStream.is_open()){
		cout << "Main file to be analyzed failed to open." << endl;
		return 0;
	}

	// Close the file when we are done to free up memory
	myMainFileStream.close();

	// return the number of unique words
	return arrayCount;
}



/* Function name: readEntireFileArray
 * Purpose: read in ENTIRE data to dynamically allocated array
 * and don't dupicate words, only increase their count
 * @param int *arraySize - pointer to arraySize variable
 * @param WordItem *& arrayUniqueWords - pass by reference to pointer of WordItem
 * @return arrayAllCount - the total number of words in the file
*/
int readEntireFileArray(string fileMainString, int *arrayAllSize, WordItem *&arrayAllWords){

	// open the hunger games txt file
	ifstream myMainFileStream(fileMainString);

	// initialize the variables, arrays, sll
	string word;
	string line;
	string singleLine;
	int count;
	int arrayAllCount = 0;
	size_t position = 0;
	string delimiter = " ";
	size_t nposition = 0;

	// if the file is "good" (not empty or at end) pull all the data out into SLL and then array
	while (myMainFileStream.good()){

		// get the data one line at a time, and parse each line by spaces into words
		getline(myMainFileStream, line);
		stringstream lineStream(line);
		getline(lineStream, singleLine);
		nposition = singleLine.size();
		while ((position = singleLine.find(delimiter)) <= nposition){
			if (nposition == delimiter.size()){

				break;
			}

			// if the array size is the same size as the number of elements, double it to make space
			if (arrayAllCount == *arrayAllSize){		
				doubleArray(arrayAllWords, arrayAllSize);
			}

			// each word is separated by spaces
			word = singleLine.substr(0,position);

			addWordArray(arrayAllWords, word, 0, arrayAllCount);	
			arrayAllCount++;

			// erase the line to the end of the word just read so the cycle can be repeated for the next word
			singleLine.erase(0, position + delimiter.length());
			nposition = singleLine.size();
		}
	}
	// if the file doesn't open, let the user know
	if (!myMainFileStream.is_open()){
		cout << "Main file to be analyzed failed to open." << endl;
		return 0;
	}
	myMainFileStream.close();

	// return the total number of words in the file
	return arrayAllCount;
}



/* Function name: printTopN
 * Purpose: to print the top N high frequency words
 * @param wordItemList - a pointer that points to a *sorted* array of wordItems
 * @param topN - the number of top frequency words to print
 * @return - none
*/
void printTopN(WordItem *&arrayToPrint, int topN){
	for(int i=0; i< topN; i++){
		cout << arrayToPrint[i].word << " - " << arrayToPrint[i].count << endl; 
	}

}



/* Function name: printEntireArray
 * Purpose: to print the entire array
 * @param wordItemList - a pointer that points to a *sorted* array of wordItems
 * @param arraySize - pointer that points to array size
 * @return - none
*/
void printEntireArray(WordItem *&arrayToPrint, int *arrayAllSize){
	for(int i=0; i< *arrayAllSize; i++){
		if (arrayToPrint[i].word != ""){
			cout << arrayToPrint[i].word << " - " << arrayToPrint[i].count << endl;
		}
	}

}


/* Function name: BubbleSort
 * Purpose: to sort the array by counter from greatest to least
 * @param wordItemList - a pointer that points to a *sorted* array of wordItems
 * @param arraySize - pointer that points to array size
 * @return - none
*/
double BubbleSort(WordItem A[], bool direction, int length){
   time_t Tbegin, Tend;
   time(&Tbegin);

		for (int i=0; i<length; i++){
			for (int j=0; j<length-1; j++){
				if (A[j].count>A[j+1].count){
					WordItem swapCount = A[j];
					A[j] = A[j+1];
					A[j+1] = swapCount;
				}
			}
		}
	time (&Tend);
  	double elapsed_secs = difftime(Tend, Tbegin);
	return elapsed_secs;
}


// Quick Sort function
double quickSort(WordItem A[], int left, int right){
	clock_t begin = clock();
	int i = left;
	int j = right;
	int pivot = A[(left+right)/2].count;
	while (i < j){
		while (A[i].count < pivot){
		i = i+1;
		}
		while (A[j].count > pivot){
		j =j-1;
		}
		if (i <= j){
		WordItem temp = A[i];
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
double insertionSort(WordItem A[], int count){
	clock_t begin = clock();
	for (int i=1; i<count; i++){
		int index = A[i].count;
		int j=i;
		while (j>0 && A[j-1].count>index){
			A[j].count = A[j-1].count;
			j=j-1;
		}
		A[j].count = index;
	}
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	return elapsed_secs;
}


/* main function, all user interactions will occur here */
int main(int argc, char **argv){


	/*************************READ INPUT*************************/
	
	string fileIgnoreWordsString = argv[3]; // read in the ignoreWords file
	string fileMainString = argv[2]; // read in the main input file
	string stringRepeatInt = argv[1];

	/***********************READ THE FILE***********************/

	// store the number of repeat words to display
	int repeatInt = stoi(stringRepeatInt);

	// read in the ignorewords and store in static array of size 50
	string arrayIgnoreWords[50] = {};
	getStopWords(fileIgnoreWordsString, arrayIgnoreWords);
	// Uncomment the following lines to print the array of Ignore Words
	// for (int i = 0; i<50; i++){
	// 	cout << arrayIgnoreWords[i] << endl;
	// }

	// read in the main input file
	int numberTotalWords = 0;
	int arrayAllSize = 2;
	WordItem *arrayAllWords = new WordItem[arrayAllSize];
	numberTotalWords = readEntireFileArray(fileMainString, &arrayAllSize, arrayAllWords);
	//printEntireArray(arrayAllWords, &arrayAllSize);

	// read in the main input file and only store unique words
	int numberUniqueWords = 0;
	int arraySize = 2;
	WordItem *arrayWords = new WordItem[arraySize];
	numberUniqueWords = readInFileArray(fileMainString, &arraySize, arrayWords, arrayIgnoreWords);
	//printEntireArray(arrayWords, &arraySize);


	/************************ARRAY SORTING*************************/


	/***********************ARRAY DOUBLING************************/

	int numberDoubled = 0;
	numberDoubled = sqrt(numberUniqueWords);


	/**********************PRINT THE OUTPUT***********************/

	// print the most commonly appearing words

	cout << "\nArray doubled: " << numberDoubled << endl;
	
	cout << "\nTime taken to store in array: " << endl;
	
	cout << "\nTime taken to store in linked list: " << endl;	

	cout << "\nUnique non-common words: " <<  numberUniqueWords << endl;

	//cout << "Number of Words to Repeat: " << repeatInt << endl;

	cout << "\nTotal non-common words: " << numberTotalWords << endl;


	/************************DATA TO LIST************************/



	//delete[] arrayAllWords;
}