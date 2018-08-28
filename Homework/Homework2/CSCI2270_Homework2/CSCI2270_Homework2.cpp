// THIS FILE ONLY CREATES AND PRINTS DYNAMICALLY ALLOCATED ARRAY OF ENTIRE INPUT FILE


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
 Note: the number of words is fixed to 60
 */
void getStopWords(char *ignoreWordFileName, string ignoreWords[]){

}



/* Function name: isStopWord
 * Purpose: to see if a word is a stop word
 * @param ignoreWords - the array of strings storing ignore/ stop words
 * @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, string ignoreWords[]){

	return 0;
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



/* Function name: addStudentArray
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
 * @return - none
*/
void readInFileArray(string fileMainString, int *arraySize, WordItem *&arrayUniqueWords){

	// open the hunger games txt file
	ifstream myMainFileStream(fileMainString);

	// initialize the variables, arrays, sll
	string word;
	string line;
	string singleLine;
	int count;
	int arrayCount = 0;
	size_t position = 0;
	string delimiter = " ";
	size_t nposition = 0;

	// if the file is "good" (not empty or at end) pull all the data out into SLL and then array
	while (myMainFileStream.good()){
		// if (arrayCount == *arraySize){		
		// 	doubleArray(arrayUniqueWords, arraySize);
		// }
		getline(myMainFileStream, line);
		stringstream lineStream(line);
		getline(lineStream, singleLine);
		nposition = singleLine.size();
		while ((position = singleLine.find(delimiter)) <= nposition){
			if (nposition == delimiter.size()){
				//addWordArray(arrayUniqueWords, " ", 0, arrayCount);	
				//arrayCount++;
				break;
			}
			if (arrayCount == *arraySize){		
				doubleArray(arrayUniqueWords, arraySize);
			}
			word = singleLine.substr(0,position);
			//cout << "word added: " << word<< endl;
			addWordArray(arrayUniqueWords, word, 0, arrayCount);	
			arrayCount++;
			//cout << arrayCount << endl;
			singleLine.erase(0, position + delimiter.length());
			nposition = singleLine.size();
		}
	}
	// if the file doesn't open, let the user know
	if (!myMainFileStream.is_open()){
		cout << "Main file to be analyzed failed to open." << endl;
		return;
	}
	myMainFileStream.close();
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
void printEntireArray(WordItem *&arrayToPrint, int *arraySize){
	for(int i=0; i< *arraySize; i++){
		cout << arrayToPrint[i].word << " - " << arrayToPrint[i].count << endl; 
	}

}




/* main function, all user interactions will occur here */
int main(int argc, char **argv){

	/***********************OPEN THE FILE***********************/
	
	// initialize the variables, arrays, sll
	// string word;
	// int count;

	string fileMainString = argv[2]; // leave here no matter what
	int arraySize = 2;
	WordItem *arrayUniqueWords = new WordItem[arraySize];
	readInFileArray(fileMainString, &arraySize, arrayUniqueWords);

	printEntireArray(arrayUniqueWords, &arraySize);
	delete[] arrayUniqueWords;


	// store the number of repeat words to display
	string stringRepeatInt = argv[1];
	int repeatInt = stoi(stringRepeatInt);
	cout << "Number of Words to Repeat: " << repeatInt << endl;

	// open the hunger games txt file
	// string fileMainString = argv[2]; // leave here no matter what
	// ifstream myMainFileStream(fileMainString);
	// // if the file is open pull all the data out into SLL and then array
	// if (myMainFileStream.is_open()){
	// 	int arrayCount = 0;
	// 	while(myMainFileStream>>word>>arrayCount){
	// 				addStudentArray(arrayUniqueWords, arrayCount);	
	// 	}
	// }
	// // if the file doesn't open, let the user know
	// else{
	// 	cout << "Main file to be analyzed failed to open." << endl;
	// }

	// open the ignoreWords.txt
	string fileIgnoreWordsString = argv[3];

	ifstream myFileIgnoreWordsStream(fileIgnoreWordsString);

	if (!myFileIgnoreWordsStream.is_open()){
		cout << "Ignore Words file failed to open." << endl;
	}

	/***********************DATA TO LIST***********************/

}