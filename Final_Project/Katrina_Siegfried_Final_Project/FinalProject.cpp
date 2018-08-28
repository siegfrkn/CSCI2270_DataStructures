//
//  FinalProject.cpp
//  
//  Created by cami on 7/19/18.
//  Modified by Katrina Siegfried 7/23/2018
//  CSCI 2270 - Data Structures
//  Final Project
//
//
//  DUE DATE: FRIDAY 7/27

#include <stdio.h>

// We need to include .cpp here because we are implementing the template class in .cpp.
// This is because the compiler needs to know the complete source code of the template when instantiating
// in other files like our FinalProject.cpp
#include "HashTable.cpp"
using namespace std;


/* FUNCTION: readInFileFunc
 * INPUTS: string fileNameString, HashTable myHashTable
 * PURPOSE: Reads in the space delimited text file, and determines which portions
 * are designated title (preceeded by #), which portions are the excerpt (follows
 * the title on the next line), and where each record ends (***************).
 * OUTPUTS: void
*/
template <int ARRAY_LEN>
void readInFileFunc(string fileNameString, HashTable<ARRAY_LEN> myHashTable, Utils myHuffTree) {
    // get the string passed in the command line (which is expected to be the 
    // name of the txt file to read in), anf pass it into a filestream function
    // for read in. If the filestream does not open properly, cout a statement
    // to inform the user.
    string excerpt, line, title, word;
    bool isExcerpt = false;
    ifstream fileStreamString(fileNameString);
    if (!fileStreamString.is_open()){
        cout << "Book Excerpts file failed to open." << endl;
    }
    // while the filestream is open and not at the end of file (aka .good()),
    // pull out each line. If the first character in a line is prepended by
    // '#', mark it to save as a title. The next lines (until the end of book
    // designation characters, will be the excerpt. If the character line is
    // a series of '*' which designate the end of a book, then push the excerpt
    // and the title into a ZippedBookNode and add to the hash table. Additionally
    // for each book added to a ZippedBookNode, the ZippedBookNode and a pointer
    // to the excerpt is passed to the addHuffNodetoQueue function in the Utils
    // class which will be used to create the huffman tree and encode.
    while (fileStreamString.good()) {
        getline(fileStreamString, line);
        if (isExcerpt) {
            stringstream ss(line);
            ZippedBookNode *node;
            priority_queue<HuffNode*, vector<HuffNode*>, compare> frequencyQueue;
            while (ss.good()) {
                getline(ss, word, ' ');
                if (word == "***************") {
                    myHashTable.insertNode(node);
                    isExcerpt = false;
                    excerpt = "";
                    break;
                }
                // add a space between each word as I was using the ' ' as a delimetre
                excerpt = excerpt + " " + word;
            }
            if (title != "" && excerpt != "") {
                // before pushing the node to the huffNode structures, add an end of line
                // symbol, I chose char(176), only do this if the title and excerpt are
                // both populated. Also, create the instance of the ZippedBookNode
                string endOfString(1, char(176));
                excerpt = excerpt + endOfString;
                node = new ZippedBookNode(title,excerpt, nullptr, nullptr);
                myHuffTree.addHuffNode(&excerpt, node);
            }
        }
        // if the first char of the line is the '#' then this is a title. Erase the '#'
        // and mark the rest of the line as the title.
        if (line[0] == '#') {
            line.erase(0,1);
            title = line;
            isExcerpt = true;
        }
    }
}


/* FUNCTION: main
 * INPUTS: int argc (the number of arguments passeed in command line) and char **argv
 * a pointer to an array of command line arguments passed
 * PURPOSE: This is where the Utils.cpp and HashTable.cpp functionalities are combined
 * and called in a meaningful way to create the hash table and execute encryption and
 * decryption.
 * OUTPUTS: void
*/
int main(int argc, char **argv) {

    /*********************INSTANTIATE**********************/
    /* create our class member using the default constructor
     * and pull in the file passed at runtime via argv[1] and
     * call the readInFileFunc to read in the contents of the
     * comma delimited file and store in the BST/LL structure.
     * Define the bool variable userExit that will trigger an
     * exit of the program.
    */

    HashTable<11> myHashTable;
    Utils myHuffTree;
    priority_queue<HuffNode*, vector<HuffNode*>> frequencyQueue;

    string filename = argv[1];
    readInFileFunc(filename, myHashTable, myHuffTree);

    bool userExit = 0;

    while (!userExit) {

    /**********************MAIN MENU***********************/
    /* Build the main menu with the user input choices. The
     * getline function is used to take user input and
     * store it in the userChoice variable string which is
     * then stored to int. This will be used to navigate the
     * case loop on which the menu is based.
    */

    cout << "\n======Main Menu======" << endl;
    cout << "1. Print titles" << endl;
    cout << "2. Search Excerpt" << endl;
    cout << "3. Search Excerpt and Decode" << endl;
    cout << "4. Get Hash Table Size" << endl;
    cout << "5. Print Huffman Tree for Book" << endl;;
    cout << "6. Quit" << endl;
    cout << "\n" << endl;

    string userChoice;                                                  
    getline(cin, userChoice);

    while (!isdigit(userChoice[0])) {
        cout << "\nInvalid selection. Please try again." << endl;
        cout << "Enter only integer numbers 1-6." << endl;
        getline(cin, userChoice);
    }                                   
                                        
    int userInput = stoi(userChoice);
    switch(userInput){  

        /*********************PRINT TITLES*********************/
        /* Call the function printTitles of the class HashTable
         * to print out all the books stored in the hash table
        */
        case 1: {
            myHashTable.printTitles();
            break;
        }


        /*******************SEARCH EXCERPT********************/
        /*******************RETURN ENCODED********************/
        /* Search the hash table for the book title entered by
         * the user, saved in string searchBook. The searchBook
         * is passed into the hashSum function to find its appro-
         * priate location in the table. If there is only one
         * item in the table and that item has a title that
         * matches the title of the searchBook, it will print
         * the Title and the encoded excerpt of that book. If
         * there are multiple titles at that index, it will
         * traverse the linked list to see if there is a match.
         * If there is a match it will print the title and encoded
         * excerpt. If there is no match it will inform the user
         * they need to enter a valid book Title.
        */
        case 2: {
            string searchBook;
            cout << "Enter title of the book to search" << endl;
            getline(cin, searchBook);

            cout << endl;
            int index = myHashTable.hashSum(searchBook); 
            if (index != -1) {
                 if (!myHashTable.lookupTable[index]->next && myHashTable.lookupTable[index]->title == searchBook) {
                    cout << "Title: " << myHashTable.lookupTable[index]->title << endl;
                    cout << "ENCODED:" << endl;
                    cout << myHashTable.lookupTable[index]->c_excerpt << endl;
                    break;
                }
                else {
                    ZippedBookNode *traverse = myHashTable.lookupTable[index];
                    while (traverse->title != searchBook && traverse->next != nullptr) {
                        traverse = traverse->next;
                    }
                    if (traverse->title  == searchBook) {
                        cout << "Title: " << traverse->title << endl;
                        cout << "ENCODED:" << endl;
                        cout << traverse->c_excerpt << endl;
                    }
                    else {
                        cout << "Book not found, please enter valid book entry" << endl;
                    }
                }
            }
            else {
                cout << "Book not found, please enter valid book entry" << endl;
            }
            break;
        }

        /*******************SEARCH EXCERPT********************/
        /*******************RETURN DECODED********************/
        /* Search the hash table for the book title entered by
         * the user, saved in string searchBook. The searchBook
         * is passed into the hashSum function to find its appro-
         * priate location in the table. If there is only one
         * item in the table and that item has a title that
         * matches the title of the searchBook, it will call the
         * huffDecode function which will decode the encoded
         * excerpt and print it out to the terminal. If
         * there are multiple titles at that index, it will
         * traverse the linked list to see if there is a match.
         * If there is a match it will call the huffDecode
         * function for that title and return the decoded
         * excerpt.  If there is no match it will inform the user
         * they need to enter a valid book Title.
        */
        case 3: {
            string searchBook;
            cout << "Enter title of the book to search" << endl;
            getline(cin, searchBook);

            cout << endl;
            int index = myHashTable.hashSum(searchBook); 
            if (index != -1) {
                if (!myHashTable.lookupTable[index]->next && myHashTable.lookupTable[index]->title == searchBook) {
                    cout << "Title: " << myHashTable.lookupTable[index]->title << endl;
                    myHuffTree.huffDecode(myHashTable.lookupTable[index]);
                    break;
                }
                else {
                    ZippedBookNode *traverse = myHashTable.lookupTable[index];
                    while (traverse->title != searchBook && traverse->next != nullptr) {
                        traverse = traverse->next;
                    }
                    if (traverse->title  == searchBook) {
                        cout << "Title: " << traverse->title << endl;
                        myHuffTree.huffDecode(traverse);
                    }
                    else {
                        cout << "Book not found, please enter valid book entry" << endl;
                    }
                }
            }
            else {
                cout << "Book not found, please enter valid book entry" << endl;
            }
            break;
        }

        /********************GET TABLE SIZE*******************/
        /* For the user's edification, they can get the table size
         * of the hashtable in use.
        */
        case 4: {
            int sizeOfTable = myHashTable.getTableSize();
            cout << "\nThe table size is " << sizeOfTable << endl; 
            break;
        }

        /*******************PRINT HUFF TREE******************/
        /* Ask the user for a book title, if the book title exists,
         * call the printHuffTree function to print the huff tree
         * for the book title
        */
        case 5: {
            string printBook;
            cout << "Enter title of the book to search" << endl;
            getline(cin, printBook);

            cout << endl;
            HuffNode *printNode = new HuffNode;
            int index = myHashTable.hashSum(printBook); 
            if (index != -1) {
                if (!myHashTable.lookupTable[index]->next && myHashTable.lookupTable[index]->title == printBook) {
                    cout << "Title: " << myHashTable.lookupTable[index]->title << endl;
                    printNode = myHashTable.lookupTable[index]->huff_root;
                    myHuffTree.printHuffTree(printNode);
                    break;
                }
                else {
                    ZippedBookNode *traverse = myHashTable.lookupTable[index];
                    while (traverse->title != printBook && traverse->next != nullptr) {
                        traverse = traverse->next;
                    }
                    if (traverse->title  == printBook) {
                        cout << "Title: " << traverse->title << endl;
                        printNode = traverse->huff_root;
                        myHuffTree.printHuffTree(printNode);
                    }
                    else {
                        cout << "Book not found, please enter valid book entry" << endl;
                    }
                }
            }
            else {
                cout << "Book not found, please enter valid book entry" << endl;
            }
            break;
        }

        /************************QUIT************************/
        /* Switch case 4 will change the userExit bool to 1,
         * which  will trigger an exit of the switch case loop
         * and termination of the program.
        */
        case 6: {
            cout << "\nGoodbye!\n" << endl;
            userExit = 1;   
            break;
        }
        default: {
            break;
        }
    }
}
}
