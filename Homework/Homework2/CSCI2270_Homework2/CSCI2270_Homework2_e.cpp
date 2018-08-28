// THIS VERSION HAS PARSING TO COMPARE INPUT FILE TO IGNORE
// WORDS AND INCREMENTING COUNTS FOR DUPLICATES
// IT ALSO HAS DYNAMIC ALLOCATION OF IGNOREWORDS ARRAY
// AND SORTING AND PRINTING OF TOP ITEMS
// AND LINKED LIST

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
	int count = 1;
};



/* a user-defined struct that will allow me to return multiple
 * values from a function
*/
struct ReturnResult{
	int value1;
	int value2;
	int value3;
	double timeOut;
};



/* define a singly linked list for object WordItems
 * each node contains a WordItem object and a pointer
 * to the next node in the SLL
*/
struct SingleNode{
	WordItem w;
	SingleNode *n;
};
// instantiate object THEN insert it into the node



// // Create a struct that will always allow me to have a head node
// class LinkedList{

// public:
// 	SingleNode *head = NULL;
// 	LinkedList(){};
// 	LinkedList(WordItem wordItem){
// 		head -> wordItem.word = "";
// 		head -> wordItem.count = 1;
// 		head -> next = NULL;
// 	}
// };



/* ALL THE FUNCTIONS TO COME
void getStopWords(string fileIgnoreWordsString, string &arrayIgnoreWords, int *ignoreSize);
bool isStopWord(string word, string arrayIgnoreWords[])
void addWordArray(WordItem *& arrayWords, string textWord, int textCount, int arrayCount);
void doubleArray(WordItem *& arrayUniqueWords, int *arraySize);
ReturnResult readInFileArray(string fileMainString, int *arraySize, WordItem *&arrayUniqueWords, string arrayIgnoreWords[]);
int readEntireFileArray(string fileMainString, int *arrayAllSize, WordItem *&arrayAllWords);
void printTopN(WordItem *&arrayToPrint, int topN);
void printEntireArray(WordItem *&arrayToPrint, int *arrayAllSize);
double BubbleSort(WordItem A[], bool direction, int length);
double quickSort(WordItem A[], int left, int right);
double insertionSort(WordItem A[], int count);
*/



/* Function name: get StopWords
 * Purpose: read stop word list from file and store it into an array
 * @param ignoreWordFile - filename (the file storing ignore words)
 * @param ignoreWords - store ignore words from the file (pass by reference)
 * @return - none
 Note: the number of words is fixed to 50
 */
int getStopWords(string fileIgnoreWordsString, string *&arrayIgnoreWords, int *ignoreSize){

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
		// if(!myFileIgnoreWordsStream.eof()){
		for (int i=0; i<=ignoreCount; i++){

			getline(myFileIgnoreWordsStream, line);
			stringstream ss(line);
			getline(ss, word);

			//cout << word << endl;

			// if the array size is the same size as the number of elements, double it to make space
			if (ignoreCount > *ignoreSize){		
					*ignoreSize = *ignoreSize*2;
					string *tmpArray = new string[*ignoreSize];
					for (int j = 0; j<*ignoreSize/2; j++){
						tmpArray[j] =arrayIgnoreWords[j];
					}
					// delete[] arrayIgnoreWords;
					arrayIgnoreWords = tmpArray;
			}

			arrayIgnoreWords[i] = word;
			ignoreCount = ignoreCount + 1;

			// if (ignoreCount >=50){
			if (myFileIgnoreWordsStream.eof()){
				break;
			}
		}
		// }
	}

	// if the file doesn't open, let the user know
	if (!myFileIgnoreWordsStream.is_open()){
		cout << "Ignore Words file failed to open." << endl;
	}

	// clear out the final counter check
	ignoreCount = ignoreCount - 1;

	// free up memory and close the file when we are done with it
	myFileIgnoreWordsStream.close();
	return ignoreCount;
}



/* Function name: isStopWord
 * Purpose: to see if a word is a stop word
 * @param ignoreWords - the array of strings storing ignore/ stop words
 * @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, string arrayIgnoreWords[], int ignoreCount){

	bool compareStopWord = false;
	string stopWord;

	for (int j=0; j<ignoreCount; j++){

		stopWord = arrayIgnoreWords[j];

		if (word == stopWord){
			compareStopWord = true;
			break;
		}

	}
	//cout << compareStopWord << endl;
	return compareStopWord;
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
 * @return uniqueCount - number of unique words
*/
ReturnResult readInFileArray(string fileMainString, int *arraySize, WordItem *&arrayUniqueWords, string arrayIgnoreWords[], int ignoreCount){

	// start a timer
	clock_t begin = clock();

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
	int uniqueCount = 0;
	int tmpCount = 1;
	ReturnResult readFile;
	int totalCount = 0;

	// if the file is "good" (not empty or at end) pull all the data out into array
	while (myMainFileStream.good()){

		// get the data one line at a time, and parse each line by spaces into words
		getline(myMainFileStream, line);
		stringstream lineStream(line);
		getline(lineStream, singleLine);
		nposition = singleLine.size();
		while ((position = singleLine.find(delimiter)) <= nposition){
			
			// if empty line
			if (nposition == delimiter.size()){
				break;
			}

			// if the array size is the same size as the number of elements, double it to make space
			if (uniqueCount >= *arraySize){		
				doubleArray(arrayUniqueWords, arraySize);
				doubleArrayCounter = doubleArrayCounter + 1;
			}

			// each word is separated by spaces
			word = singleLine.substr(0,position);

			// reset tmpCount
			tmpCount = 1;

			// Compare to the stop word
			compareWord = isStopWord(word, arrayIgnoreWords, ignoreCount);

			// if it's not a stop word, keep going
			if (compareWord != true){

				bool isFound = false;
				// Compare this word to all the other words currently in the array
				for (int i=0; i< uniqueCount; i++){
					string compareCount = arrayUniqueWords[i].word;

					// If already in array, do not add new item, but increase count for that index
					if (word == compareCount){
						
						tmpCount = arrayUniqueWords[i].count;
						tmpCount = tmpCount + 1; // increase because we have a match
						arrayUniqueWords[i].count = tmpCount;

						//arrayUniqueWords[i].count ++;
						isFound = true;
						uniqueCount = uniqueCount - 1;
						break;
					}
					addWordArray(arrayUniqueWords, word, tmpCount, uniqueCount);

				}

				uniqueCount = uniqueCount + 1;
				totalCount = totalCount +1;


			}

			// increment to the next word
			singleLine.erase(0, position + delimiter.length());
			nposition = singleLine.size();
			
		}
	}

	// remove the last count added before exit
	uniqueCount = uniqueCount - 1;

	// if the file doesn't open, let the user know
	if (!myMainFileStream.is_open()){
		cout << "Main file to be analyzed failed to open." << endl;
		readFile.value1 = 0;
		readFile.value2 = 0;
		return readFile;
	}

	// Close the file when we are done to free up memory
	myMainFileStream.close();

	// store outputs in the return struct
	readFile.value1 = uniqueCount;
	readFile.value2 = doubleArrayCounter;
	readFile.value3 = totalCount;


	// stop the timer
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	readFile.timeOut = elapsed_secs;

	// return the number of unique words
	return readFile;
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
	int doubleArrayCounter = 0;


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
			arrayAllCount = arrayAllCount + 1;

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

	// close the file when we are done with it
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
	for(int i=0; i<topN; i++){
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



/* Function name: InsertionSort
 * Purpose: to sort the array by counter from greatest to least
 * @param wordItemList - a pointer that points to a *sorted* array of wordItems
 * @param arraySize - pointer that points to array size
 * @return - time taken to sort
*/
double insertionSort(WordItem A[], int size){
	clock_t begin = clock();
    int i, j;
    WordItem index;
     for(j = 1; j < size; j++)
    {
           index = A[j];
           for(i = j - 1; (i >= 0) && (A[i].count < index.count); i--)
          {
                 A[i+1] = A[i];
          }
         A[i+1] = index;
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
	int ignoreSize = 2;
	int ignoreCount = 0;
	string *arrayIgnoreWords = new string[ignoreSize];
	ignoreCount = getStopWords(fileIgnoreWordsString, arrayIgnoreWords, &ignoreSize);

	// read in the main input file
	int numberTotalWords = 0;
	int arrayAllSize = 2;
	WordItem *arrayAllWords = new WordItem[arrayAllSize];
	numberTotalWords = readEntireFileArray(fileMainString, &arrayAllSize, arrayAllWords);
	//printEntireArray(arrayAllWords, &arrayAllSize);

	// read in the main input file and only store unique words
	int numberUniqueWords = 0;
	ReturnResult uniqueResults;
	int arraySize = 100;
	WordItem *arrayWords = new WordItem[arraySize];
	uniqueResults = readInFileArray(fileMainString, &arraySize, arrayWords, arrayIgnoreWords, ignoreCount);
	//printEntireArray(arrayWords, &numberUniqueWords);


	/*************************LINKED LIST**************************/
 	int listSize = 100;

	// LinkedList *linkedlist = new LinkedList();
	// insertNode(linkedlist, leftValue, textWord);


	/************************ARRAY SORTING*************************/

	double sortTime = 0;
	sortTime = insertionSort(arrayWords, uniqueResults.value1);


	/**********************PRINT THE OUTPUT***********************/

	// print the most commonly appearing words
	printTopN(arrayWords, repeatInt);

	cout << "\nArray doubled: " << uniqueResults.value2 << endl;
	
	cout << "Time taken to store in array: " << uniqueResults.timeOut << " seconds" << endl;

	cout << "Time taken to sort array: " << sortTime << " seconds" << endl;
	
	cout << "\nTime taken to store in linked list: " << endl;

	cout << "Time taken to traverse linked list: " << endl;	

	cout << "\nUnique non-common words: " <<  uniqueResults.value1 << endl;

	cout << "Total non-common words: " << uniqueResults.value3 << endl;

	cout << "Number of ignored words entered from text: " << ignoreCount <<endl;

	cout << "Number of total words: " << numberTotalWords << endl;

	/************************DATA TO LIST************************/



	//delete[] arrayAllWords;
}