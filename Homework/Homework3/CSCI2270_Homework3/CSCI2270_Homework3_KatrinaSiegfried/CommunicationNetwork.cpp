// Katrina Siegfried
// CSCI2270 - Data Structures
// Homework 3 - Communication Between Towers
// CommunicationNetwork.cpp  to be compiled with Assignment3.cpp
                                                                                                          
#include <sstream>                                                            // inlude the necessary libraries

using namespace std;                                                          // include the standard namespace

#include "CommunicationNetwork.h"                                             // include CommunicationNetwork.h header file


CommunicationNetwork::CommunicationNetwork() {                                // create a default constructor with NULL head and tail
  head = NULL;
  tail = NULL;
}
CommunicationNetwork::~CommunicationNetwork() {                               // create a deconstructor with NULL head and tail
  head = NULL;
  tail = NULL;
}

//declaring functions
void buildNetwork();                                                          // will build the list of cities that we start with
void transmitMsg(City * head);                                                // passes a message from the first to last node through the list
void addCity(City * head, string prev, string cityName);                      // adds a city to the list in the location specified by the user
void printNetwork();                                                          // prints the list of cities


void CommunicationNetwork::printNetwork() {                                   // prints the cities in the list
  City * temp = head;                                                         // define a pointer that dictates our "current" node - set to first element of the list
  cout << "===CURRENT PATH===" << endl;
  while(temp != NULL)                                                         // while there is a valid node being pointed to
    {
      cout << temp->cityName;                                                 // prints the city name
      cout << " <-> " ;                                                       // prints an arrow
      temp = temp->next;                                                      // change the current node to the next one in the list
    }
  cout << "NULL" <<endl;                                                      // prints NULL to signify the end of the list 
  cout << "==================" << endl;
}


void CommunicationNetwork::addCity(string previousCity, string cityName){     // add city after previous city, return head
    City *newCity = new City;                                                 // new node called newCity
    if (previousCity == "First"){                                             // if the user wants to add a city at the beginning of the list
        newCity -> next = head;                                               // set the newCity to point at the head
        newCity -> cityName = cityName;                                       // set the cityName of the city to user-inputted cityName
        head -> previous = newCity;                                           // set the head to point previously to newCity
        head = newCity;                                                       // set newCity as the new head
    }
    else if (previousCity == ""){                                             // if the user sends an empty string for previousCity, make it at the end
        City *traverse = head;                                                // make a traverse node
        while (traverse -> next != NULL){                                     // find the last node in the list - this could also be done using tail!
          traverse =traverse -> next;
        }
        newCity -> cityName = cityName;                                       // set the newCity name to cityName
        newCity -> previous = traverse;                                       // point the newCity back to the last node in the list
        newCity -> next = NULL;                                               // point the newCity forward to NULL
        traverse -> next = newCity;                                           // set the current last node to point to the newCity node
        if (newCity -> next == NULL){                                         // double check - if the newCity node is last in the list
          tail = newCity;                                                     // make it the tail node
        }
    }
    else {                                                                    // otherwise we are adding the city into the middle of the list
        City *traverse = head;                                                // make a traverse node
        while (traverse -> cityName != previousCity){                         // traverse to the end of the list - could also be done using tail!
          traverse =traverse -> next;
        }
        newCity -> cityName = cityName;                                       // set the newCity name to be cityName
        newCity -> next = traverse -> next;                                   // point newCity forward to the previous city's next
        newCity -> previous = traverse;                                       // point newCity back to the previousCity
        traverse -> next -> previous = newCity;                               // point the previous city's next back to newCity
        traverse -> next = newCity;                                           // point the previousCity to the newCity
        if (newCity -> next == NULL){                                         // double check - if the newCity node is last in the list
          tail = newCity;                                                     // make it the tail node
        }
    }
}


void CommunicationNetwork::buildNetwork() {                                   // will build the list of cities that we start with, and returns the head of the list
  City * temp;                                                                // "current" city
  string cities[] = {"LA", "Phoenix", "Denver", "Dallas", "St. Louis"
  , "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};          // names of the cities where we want to pass the message
  int num_cities = 10;                                                        // number of cities - default we are starting with 10
  for (int counter = 0; counter < num_cities; counter ++){                    // for each city we want to pass the message to
    City * newCity = new City(cities[counter], NULL, NULL, "");               // make a new city that's empty
    if (counter == 0){                                                        // if it's the first element, it's the head
  	  head = newCity;                                                         // make the head the first newCity
      tail = newCity;                                                         // the tail and the head are the same because the list is empty
    }
    else{                                                                     // otherwise, it's just the next city
  	  City *traverse = head;                                                  // make a traverse node to find the end of the list - could also be done using tail?
      while (traverse -> next != NULL){                                       // traverse to find the end
        traverse = traverse->next;                                            // move to the next city
      }
      traverse -> next  = newCity;                                            // the next city is the one that comes next in the list, point it to the newCity
      traverse -> next -> previous = traverse;                                // point the next's previous back to the traverse
      tail = newCity;                                                         // make the newCity the tail
    }
  }
  CommunicationNetwork::printNetwork();                                       // print the network out
}


void CommunicationNetwork::transmitMsg(char *line) {                          // this will need to be modified in order to read in the message from a file
    string word;                                                              // create a string variable called word
    string sline = *&line;                                                    // create a string called sline equal to the value line points to
    stringstream stream(sline);                                               // get stringstream of sline called stream
    while(stream >> word){                                                    // while the stream is bigger than a simple string
      City * temp = head;                                                     // pointer to the first city in the list
      while (temp != NULL) {                                                  // increments through the list
        temp->message = word;                                                 // passes the message to the current city
        cout<<temp->cityName+" received "+temp->message<<endl;                // prints that the next city received the word
        temp->message = "";                                                   // deletes the word from the message we're concerned about
        temp = temp->next;                                                    // shifts to the next node
      } 
      delete temp;                                                            // delete dynamically allocated temp variable
    }
  }

void CommunicationNetwork::deleteCity(string cityName){                       // delete a node
    City *tmp = head;
    while (tmp !=NULL && head -> cityName == cityName){                       // case 1: head node to be deleted
        head = head -> next;                                                  // bump the head node forward one
        delete tmp;                                                           // deltee the dynamically allocated variable
        tmp = head;                                                           // set tmp as the head
    }
    while (tmp != NULL){                                                      // case 2+3: middle or end node to be deleted
        City *left = head;                                                    // create a node that points to the head
        bool found = false;                                                   // create a boolean variable to indicate if we have found the value to delete
        tmp = head -> next;                                                   // increment to one elmenet from the head
        while (tmp != NULL && !found){                                        // increment through the list
            if (tmp -> cityName == cityName){                                 // if the cityName matches the name of the node
                left -> next = tmp -> next;                                   // point the previous node to one node down from the matching node
                if (left -> next == NULL){                                    // if we aren't at the end of the list
                    tmp -> next = NULL;                                       // point the current node to null
                    found = true;                                             // set the flag to true - we found it!
                }
                delete tmp;                                                   // delete dynamically allocated variable
                found = true;                                                 // set found flag as true
            }
            else{                                                             // if we didn't find it yet
                left = tmp;                                                   // keep iterating
                tmp = tmp -> next;
            }
        }
    }
}


