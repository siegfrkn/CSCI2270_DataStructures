// Katrina Siegfried 2018
// CSCI 2270 - Data Structures
// Homework 2


// ##     ## ##     ## ##    ##  ######   ######## ########  
// ##     ## ##     ## ###   ## ##    ##  ##       ##     ## 
// ##     ## ##     ## ####  ## ##        ##       ##     ## 
// ######### ##     ## ## ## ## ##   #### ######   ########  
// ##     ## ##     ## ##  #### ##    ##  ##       ##   ##   
// ##     ## ##     ## ##   ### ##    ##  ##       ##    ##  
// ##     ##  #######  ##    ##  ######   ######## ##     ## 


//  ######      ###    ##     ## ########  ######  
// ##    ##    ## ##   ###   ### ##       ##    ## 
// ##         ##   ##  #### #### ##       ##       
// ##   #### ##     ## ## ### ## ######    ######  
// ##    ##  ######### ##     ## ##             ## 
// ##    ##  ##     ## ##     ## ##       ##    ## 
//  ######   ##     ## ##     ## ########  ######  





/* Include libraries and namespace needed for file to build
 * and run properly
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <ctime>

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
};



/* define a singly linked list for object WordItems
 * each node contains a WordItem object and a pointer
 * to the next node in the SLL
*/
struct SingleNode{
	WordItem w;
	SingleNode *n;
};



/* Create a struct that will always allow me to have
a head node
*/
class LinkedList{

public:
	SingleNode *head = new SingleNode;
	LinkedList(){};
	LinkedList(WordItem w){
		head -> w.word = "head";
		head -> w.count = 1;
		head -> n = NULL;
	}
};



/* DECLARE FUNCTION PROTOTYPES */
double readInFileSLL(string fileMainString, LinkedList *sllUniqueWords, string arrayIgnoreWords[], int ignoreCount);
int addNode(LinkedList *sllUniqueWords, string word, int sllCount);
SingleNode *searchNode(LinkedList *linkedlist, string valueToSearch);
double insertionSort(WordItem A[], int size);
void printTopN(WordItem *&arrayToPrint, int topN);
ReturnResult readInFileArray(string fileMainString, int *arraySize, WordItem *&arrayUniqueWords, string arrayIgnoreWords[], int ignoreCount);
void doubleArray(WordItem *& arrayUniqueWords, int *arraySize);
int addWordArray(WordItem *& arrayUniqueWords, string textWord, int textCount, int uniqueCount);
bool isStopWord(string word, string arrayIgnoreWords[], int ignoreCount);
int getStopWords(string fileIgnoreWordsString, string *&arrayIgnoreWords, int *ignoreSize);



/* main function, all user interactions will occur here */
int main(int argc, char **argv){

	/*************************READ INPUT*************************/
	
	string fileIgnoreWordsString = argv[3]; // read in the ignoreWords file
	string fileMainString = argv[2]; // read in the main input file
	string stringRepeatInt = argv[1];

	/***********************READ IGN FILE***********************/

	// store the number of repeat words to display
	int repeatInt = stoi(stringRepeatInt);

	// read in the ignorewords and store in static array of size 50
	int ignoreSize = 2;
	int ignoreCount = 0;
	string *arrayIgnoreWords = new string[ignoreSize];
	ignoreCount = getStopWords(fileIgnoreWordsString, arrayIgnoreWords, &ignoreSize);

	/****************************ARRAY*****************************/

	/* READ IN THE MAIN INPUT FILE AND STORE ONLY UNIQUE WORDS */
	// start a timer
	clock_t begin = clock();
	int numberUniqueWords = 0;
	ReturnResult uniqueResults;
	int arraySize = 100;
	double arrayTime = 0;
	WordItem *arrayUniqueWords = new WordItem[arraySize];
	uniqueResults = readInFileArray(fileMainString, &arraySize, arrayUniqueWords, arrayIgnoreWords, ignoreCount);
	// stop the timer
	clock_t end = clock();
  	arrayTime = double(end - begin) / CLOCKS_PER_SEC;

	/*************************LINKED LIST**************************/

  	/* READ IN THE MAIN INPUT FILE AND STORE ONLY UNIQUE WORDS */
	// start a timer
	clock_t beginA = clock();
	LinkedList *sllUniqueWords = new LinkedList();
	SingleNode *head = sllUniqueWords -> head;
	head -> w.word = "";
	head -> w.count = 1;
	head -> n = NULL;
	int sllCount = 0;
	double sllTime = 0;
	sllCount = readInFileSLL(fileMainString, sllUniqueWords, arrayIgnoreWords, ignoreCount);
	// stop the timer
	clock_t endA = clock();
  	sllTime = double(endA - beginA) / CLOCKS_PER_SEC;
	// Uncomment the folloing lines to print singly linked list for debugging
	// SingleNode *printNode = head;
	// while (printNode != NULL){
	// 	cout << "This is the value of the current node: " << printNode -> w.word << " - " << printNode -> w.count << endl;
	// 	printNode = printNode -> n;
	// }

	/************************ARRAY SORTING*************************/

	double sortTime = 0;
	sortTime = insertionSort(arrayUniqueWords, uniqueResults.value1);
	// Uncomment the following lines to print the entire sorted array of unique words
	// for (int j=0; j< uniqueResults.value1; j++){
	// 	cout << arrayUniqueWords[j].word << endl;
	// }

	/**********************PRINT THE OUTPUT***********************/

	// print the most commonly appearing words
	printTopN(arrayUniqueWords, repeatInt);
	cout << "\nArray doubled: " << uniqueResults.value2 << endl;
	cout << "\nTime taken to store in array: " << arrayTime << " seconds" << endl;
	cout << "\nTime taken to sort array using insertion sort: " << sortTime << " seconds" << endl;
	cout << "\nTime taken to store in linked list: " << sllTime << " seconds" << endl;
	cout << "\nUnique non-common words: " <<  uniqueResults.value1 << endl;
	cout << "\nTotal non-common words: " << uniqueResults.value3 << endl;
}











/* Function name: get StopWords
 * Purpose: read stop word list from file and store it into an array
 * @param ignoreWordFile - filename (the file storing ignore words)
 * @param ignoreWords - store ignore words from the file (pass by reference)
 * @return - none
 Note: this is a dynamic array
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
			getline(ss, word, ' ');
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
	if (word == ""){
		compareStopWord = true;
	}
		if (word == " "){
		compareStopWord = true;
	}
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
int addWordArray(WordItem *& arrayUniqueWords, string textWord, int textCount, int uniqueCount){
	arrayUniqueWords[uniqueCount].word = textWord;
	arrayUniqueWords[uniqueCount].count = textCount;
	uniqueCount++;
	return uniqueCount;
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
 * @param arraySize - pointer to arraySize variable
 * @param arrayUniqueWords - pass by reference to pointer of WordItem
 * @param fileMainString - main txt file to be parsed
 * @param arrayIgnoreWords - array of words to NOT be added
 * @param ignoreCount - number of ignoreWords in arrayIgnoreWords
 * @return uniqueCount - number of unique words
*/
ReturnResult readInFileArray(string fileMainString, int *arraySize, WordItem *&arrayUniqueWords, string arrayIgnoreWords[], int ignoreCount){
	// open the hunger games txt file
	ifstream myMainFileStream(fileMainString);
	// initialize the variables, arrays
	string word;
	string lineFromText;
	int arrayCount = 0;
	bool compareWord = false;
	int doubleArrayCounter = 0;
	int wordCount = 0;
	ReturnResult readFile;
	int totalCount = 0;
	// if the file is "good" (not empty or at end) pull all the data out into array
	while (!myMainFileStream.eof()){
		while (getline(myMainFileStream, lineFromText)){
			if (lineFromText == " ")
			{
				break;
			}
			// if the line is blank, increment
			stringstream ss(lineFromText);
			while (getline(ss, word, ' ')){
				// Compare to the stop word, true if yes, false is no
				compareWord = isStopWord(word, arrayIgnoreWords, ignoreCount);
				// if it's not a stop word, keep going
				if (compareWord == false){
					bool isFound = false;
					// Compare this word to all the other words currently in the array
					// is the word already in the array?
					for (int i=0; i< wordCount; i++){
						// If already in array, do not add new item, but increase count for that index
						if (word ==  arrayUniqueWords[i].word){
							arrayUniqueWords[i].count++;
							isFound = true;
							break;
						}
					}
					if (isFound == false){
						// if the array size is the same size as the number of elements, double it to make space
						if (wordCount == *arraySize){		
							doubleArray(arrayUniqueWords, arraySize);
							doubleArrayCounter = doubleArrayCounter + 1;
						}
						wordCount = addWordArray(arrayUniqueWords, word, 1, wordCount);
					 }
					totalCount++;
				}
			}
			
		}
	}
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
	readFile.value1 = wordCount;
	readFile.value2 = doubleArrayCounter;
	readFile.value3 = totalCount;
	// stop the timer
	// return a struct with multiple output values
	return readFile;
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



/* searchNode
 * Purpose: to search  a singly linked list and indicate whether
 * a particular value is contained within it
 * @param linkedList - pointer to the beginning of the linkedList
 * @param valueToSearch - string value of the new node to be searched
 * @return - NULL if valueToSearch not found, returns node containing
 * valueToSearch otherwise
 */
SingleNode *searchNode(LinkedList *linkedlist, string valueToSearch){
	// first node is a searchNode node because we need to traverse the list
	SingleNode *searchNode = linkedlist -> head;
	// if this is the only item in the list, return the head
	if (searchNode -> n == NULL){
		return NULL;
	}
	while (searchNode != NULL){
	// while (searchNode -> n != NULL){ // I commented this out because when the linked list only has one value, the tmp->n will ALWAYS be NULL
		if (searchNode -> w.word == valueToSearch){
			// if I find the value
			return searchNode;
		}
		searchNode = searchNode-> n;
	}
	return NULL;
}



/* Function name: addNode
 * Purpose: to add unique words to the ned of a new node in a linked list
 * @param sllUniqueWords - a pointer that points to a list of sllUniqueWords
 * @param word - the string to be added to that node
 * @param sllCount - the current number of items in the sllUniqueWords list
 * @return - incremented sllCount
*/
int addNode(LinkedList *sllUniqueWords, string word, int sllCount){
	// define the head and a new empty node
	SingleNode *head = sllUniqueWords -> head;
	SingleNode *left = new SingleNode;
	// initialize the new node
	left -> w.word =  word;
	left -> w.count = 1;
	left -> n = NULL;
	// define a tmp node to traverse the list
	SingleNode *tmp = head;
	// if there is no head set a head
	if (tmp == NULL){
		head = left;
	}
	// traverse the list to find the ned and insert the left node
	// as the new node
	while(tmp -> n != NULL){
		tmp = tmp -> n;
	}
	tmp -> n = left;
	// increment the sllCount and return it
	sllCount++;
	return sllCount;
}



/* Function name: readInFileSLL
 * Purpose: read in data to dynamically allocated sll ONLYif it is NOT an ignore word
 * and don't dupicate words, only increase their count
 * @param fileMainString - file containing the text to be parsed
 * @param sllUniqueWords - pass by reference to pointer to singly linked list of WordItems
 * @param arrayIgnoreWords - array of words to NOT add
 * @param ignoreCount - number of elements in arrayIgnoreWords
 * @return - time taken to create
 */
 double readInFileSLL(string fileMainString, LinkedList *sllUniqueWords, string arrayIgnoreWords[], int ignoreCount){
	// open the hunger games txt file
	ifstream myMainFileStream(fileMainString);
	// initialize the variables, arrays
	string word;
	string lineFromText;
	bool compareWord = false;
	int sllCount = 0;
	// if the file is "good" (not empty or at end) pull all the data out into array
	while (!myMainFileStream.eof()){
		while (getline(myMainFileStream, lineFromText)){
			if (lineFromText == " ")
			{
				break;
			}
			stringstream ss(lineFromText);
			while (getline(ss, word, ' ')){
				if (word == " "){
					break;
				}
				// Compare to the stop word, true if yes, false is no
				compareWord = isStopWord(word, arrayIgnoreWords, ignoreCount);
				SingleNode *tmp = searchNode(sllUniqueWords, word);
				for (int i=0; i<ignoreCount; i++){
					if (compareWord == false){
						if (tmp == NULL){
							sllCount = addNode(sllUniqueWords, word, sllCount);
							break;
						}
						else{
							tmp -> w.count++;
						}
						tmp = tmp -> n;
						break;
					}
				}
			}
		}
	}
	// if the file doesn't open, let the user know
	if (!myMainFileStream.is_open()){
		cout << "Main file to be analyzed failed to open." << endl;
		return 0;
	}
	// Close the file when we are done to free up memory
	myMainFileStream.close();
	// return the number of unique words
	return sllCount;
}