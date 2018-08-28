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



// Create a struct that will always allow me to have a head node
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

	if (word == ""){
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
int addWordArray(WordItem *& arrayWords, string textWord, int textCount, int uniqueCount){
	arrayWords[uniqueCount].word = textWord;
	arrayWords[uniqueCount].count = textCount;
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
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  	readFile.timeOut = elapsed_secs;
	// return the number of unique words
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



// have to find where to insert nodes
/* searchNode
 * @param - leftValue: value after which we add new node
 * @param - value: value of the new node to be added
 */
SingleNode *searchNode(LinkedList *linkedlist, string valueToSearch){
	// first node is a searchNode node because we need to traverse the list
	SingleNode *searchNode = linkedlist -> head;

	// if this is the only item in the list, return the head
	if (searchNode -> n == NULL){
		return NULL;
	}

	while (searchNode -> n != NULL){
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
 * Purpose: to add unique words to a new node in a linked list
 * @param wordItemSLL - a pointer that points to a class of linkedList
 * @param addWordItem - the word and it's count to add
 * @return - none
*/
void addNode(LinkedList *linkedList, string word){

	SingleNode *head = linkedList -> head;

	// SingleNode *left = searchNode(linkedList, leftValue.word);

	SingleNode *left = new SingleNode;

	left -> w.word =  word;
	left -> w.count = 1;
	left -> n = NULL;

	// SingleNode *left = searchNode(linkedList, leftValue.word);

	SingleNode *tmp = head;

	// if there is no head set a head
	if (tmp == NULL){
		head = left;
		return;
	}


	// // if there is only the head node
	// if (tmp -> n == NULL){
	// 	head -> n = left;
	// 	return;
	// }
	while(tmp -> n != NULL){
		tmp = tmp -> n;
	}
	tmp -> n = left;
	// delete tmp;
}




/* Function name: readInFileSLL
 * Purpose: read in data to dynamically allocated array ONLYif it is NOT an ignore word
 * and don't dupicate words, only increase their count
 * @param int *arraySize - pointer to arraySize variable
 * @param WordItem *& arrayUniqueWords - pass by reference to pointer of WordItem
 * @return - time taken to create
*/
double readInFileSLL(string fileMainString, LinkedList *linkedList, string arrayIgnoreWords[], int ignoreCount){

	// start a timer
	clock_t begin = clock();

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
				// Compare to the stop word, true if yes, false is no
				compareWord = isStopWord(word, arrayIgnoreWords, ignoreCount);
				for (int i=0; i<ignoreCount; i++){
					if (compareWord == false){
						SingleNode *tmp = searchNode(linkedList, word);
						SingleNode *newNode = new SingleNode;

						if (tmp == NULL){
							addNode(linkedList, word);

							sllCount++;
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
			break;
		}
	}

	// if the file doesn't open, let the user know
	if (!myMainFileStream.is_open()){
		cout << "Main file to be analyzed failed to open." << endl;
		return 0;
	}

	// Close the file when we are done to free up memory
	myMainFileStream.close();
	// stop the timer
	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	// return the number of unique words
	return sllCount;
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

	// for (int i=0; i< 50; i++){
	// 	cout<< arrayIgnoreWords[i] << " ,";
	// }
	// read in the main input file
	/*int numberTotalWords = 0;
	int arrayAllSize = 2;
	WordItem *arrayAllWords = new WordItem[arrayAllSize];
	numberTotalWords = readEntireFileArray(fileMainString, &arrayAllSize, arrayAllWords);*/
	//printEntireArray(arrayAllWords, &arrayAllSize);

	// read in the main input file and only store unique words
	int numberUniqueWords = 0;
	ReturnResult uniqueResults;
	int arraySize = 100;
	WordItem *arrayWords = new WordItem[arraySize];
	uniqueResults = readInFileArray(fileMainString, &arraySize, arrayWords, arrayIgnoreWords, ignoreCount);
	//printEntireArray(arrayWords, &numberUniqueWords);


	/*************************LINKED LIST**************************/

	LinkedList *linkedList = new LinkedList();
	SingleNode *head = linkedList -> head;
	head -> w.word = "";
	head -> w.count = 1;
	head -> n = NULL;
	double sllTime = 0;
	cout << linkedList -> head -> w.word << endl;
	sllTime = readInFileSLL(fileMainString, linkedList, arrayIgnoreWords, ignoreCount);
	// insertNode(linkedlist, leftValue, textWord);
	// while (linkedList -> head -> n != NULL){
	// 	cout << linkedList -> head -> w.word << endl;
	// 	head = head -> n;
	// }

		// print
	// SingleNode *head = linkedList -> head;
	SingleNode *printNode = head;
	while (printNode != NULL){
		cout << "This is the value of the current node: " << printNode -> w.word << " - " << printNode -> w.count << endl;
		printNode = printNode -> n;
	}

	/************************ARRAY SORTING*************************/

	double sortTime = 0;
	sortTime = insertionSort(arrayWords, uniqueResults.value1);


	/**********************PRINT THE OUTPUT***********************/

	// print the most commonly appearing words
	printTopN(arrayWords, repeatInt);

	cout << "\nArray doubled: " << uniqueResults.value2 << endl;
	
	cout << "Time taken to store in array: " << uniqueResults.timeOut << " seconds" << endl;

	cout << "Time taken to sort array: " << sortTime << " seconds" << endl;
	
	cout << "\nTime taken to store in linked list: " << sllTime << endl;

	cout << "\nUnique non-common words: " <<  uniqueResults.value1 << endl;

	cout << "Total non-common words: " << uniqueResults.value3 << endl;

	cout << "Number of ignored words entered from text: " << ignoreCount <<endl;
}