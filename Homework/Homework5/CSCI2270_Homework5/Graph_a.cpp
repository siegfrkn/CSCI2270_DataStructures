#include<vector>
#include<iostream>
#include<string>
#include <fstream>                                                         
#include <sstream>
#include <cstdlib>
#include <ctype.h>
#include"Graph.h"

using namespace std;

Graph::Graph() {
	vector <vertex> vertices;
}

Graph::~Graph() {
	vector <vertex> vertices;
	vertices.empty();
}

/* FUNCTION: readInFileFunc
 * CLASS MEMBER: Public
 * INPUTS: string fileNameString, MovieTree myMovieTree
 * PURPOSE: Reads in the comma delimited data from the txt passed when the program began,
 * pulled as argv[]. Uses a helper function called LLhelperFunction to create the
 * structure.
 * OUTPUTS: void
*/
void Graph::readInFileFunc(string fileNameString, Graph zombieGraph){
	cout << "Reading in file..." << endl;
	string word;	
	bool test = false;
	ifstream fileStreamString(fileNameString);
	if (!fileStreamString.is_open()){
		cout << "Zombie Cities file failed to open." << endl;
	}
	while(fileStreamString.good()){
		getline(fileStreamString, word, ',');
		// word = line;
		vector<vertex> tempVector;
		vertex *tempVertex = new vertex;
		bool checkCity = findVertices(tempVector, word);
		if (!checkCity) {
			cout << "City is not in the network, adding now..." << endl;
			// temp -> name = word;
			// zombieGraph.vertices.name.push_back(word);
			tempVertex -> name = word;
			tempVector.push_back(*tempVertex);
			cout << word << endl;
		}
		else if (checkCity) {
			return;
		}
	}
	fileStreamString.close();
	cout << "\n \n" << endl;
}


/* FUNCTION: findVertices
 * CLASS MEMBER: Public
 * INPUTS: vector <vertex> vertices of Graph, string cityName
 * PURPOSE: Takes a city and traverses the vertices vector to see if the cityName is already
 * present, if so, it returns true, otherwise false.
 * OUTPUTS: true if city is already in vector, false otherwise
*/
bool Graph::findVertices(vector<vertex> myVector, string cityName) {
	// for (vector<vertex>iterator i = vertices.begin(); i != vertices.end(); i++) {
	for (unsigned i = 0; i<myVector.size(); i++) {
		for (unsigned j = 0; j<myVector.size(); j++) {
			string cityIndex = myVector[j].name;
			if (cityName == cityIndex) {
				return true;
			}
		}
	}
	return false;
}


// void Graph::printVertices(Graph myGraph) {
// 	for (int i=0; i<myGraph.vertices.size(); i++) {
// 		// for (int j =0; j<myGraph.vertices.size(); j++) {
// 			cout << myGraph.vertices[i]-> name;
// 			// cout << myGraph.vertices[i][j];
// 		// }
// 	}
// }