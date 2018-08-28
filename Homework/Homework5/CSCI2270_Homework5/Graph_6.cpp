#include<vector>
#include<iostream>
#include<string>
#include <fstream>                                                         
#include <sstream>
#include <cstdlib>
#include <ctype.h>
#include"Graph.h"
#include<queue>
#include<climits>

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
	// cout << "Reading in file..." << endl;
	string word, line;	
	bool test = false;
	ifstream fileStreamString(fileNameString);
	if (!fileStreamString.is_open()){
		cout << "Zombie Cities file failed to open." << endl;
	}
	int counter = 0;
	string nodeCityName;
	string *ptrNodeCityName = &nodeCityName;
	while(fileStreamString.good()){
		getline(fileStreamString, line);
		stringstream ss(line);
		while (ss.good()){
			getline(ss, word, ',');
			vertex *vertexAdded = findVertex(word);
			bool digitFlag = false;
			for (int k=0; k < word.length(); k++) {
				if (isdigit(word[k])) {
					digitFlag = true;
				}
			}
			if (!digitFlag) {
				if (vertexAdded) {
					*ptrNodeCityName = word;
					counter = 0;
				}
				else if (!vertexAdded) {
					addVertex(word);
				}
				else {
					cout << "Error, not added." << endl;
				}
			}
			else {
				counter++;
				string v1city = *ptrNodeCityName;
				string v2city = vertices[counter].name;
				int weight = stoi(word);
				addEdge(v1city, v2city, weight);
			}
		}
	}
	fileStreamString.close();
	cout << "\n \n" << endl;
}


/* FUNCTION: printVertices
 * CLASS MEMBER: Public
 * INPUTS: graph to print 
 * PURPOSE: traverses the graph and prints out the cities and their adjacency lists
 * OUTPUTS: cout
// */
void Graph::displayEdges() {
	cout << endl;
	for (int i=0; i<vertices.size(); i++) {
		if (vertices[i].name != "cities"){
			cout << vertices[i].districtID << ": " << vertices[i].name << " --> ";
			vector<adjVertex> tmp = vertices[i].adj;
			for (int j =0; j<tmp.size(); j++) {
				cout << tmp[j].v -> name;
				if (j != vertices[i].adj.size()-1) {
					cout << " *** ";
				}
			}
			cout << endl;
		}
		else {
			cout << endl;
		}
	}
}


/* FUNCTION: addEdge
 * CLASS MEMBER: Public
 * INPUTS: string first city, string second city, weight between them, 
 * PURPOSE: If the weight between the two cities is -1, not connected if 0 cities are identical,
 * otherwise adds second city to adj vector of first city with given weight
 * OUTPUTS: none
*/
void Graph::addEdge(std::string v1, std::string v2, int weight) {
	if (weight == -1) {
		return;
	}
	else if (weight == 0) {
		return;
	}
else {
		vertex *findCity1 = findVertex(v1);
		vertex *findCity2 = findVertex(v2);
		for (int i=0; i<findCity1->adj.size(); i++) {
			if (findCity1 -> adj[i].v-> name == v2) {
				return;
			}
		}
		adjVertex *adjv = new adjVertex;
		adjv -> v = findCity2;
		adjv -> weight = weight;
		findCity1 -> adj.push_back(*adjv);
		adjVertex *adjv2 = new adjVertex;
		adjv2 -> v = findCity1;
		adjv2 -> weight = weight;
		findCity2 -> adj.push_back(*adjv2);
	}
}


/* FUNCTION: addVertex
 * CLASS MEMBER: Public
 * INPUTS: string cityName
 * PURPOSE: Takes a cityname and creates a new vertex
 * OUTPUTS: none
*/
void Graph::addVertex(string name) {
	vertex *v = new vertex;
	v-> name = name;
	v -> districtID = -1;
	v -> visited = false;
	vertices.push_back(*v);
}


/* FUNCTION: findVertex
 * CLASS MEMBER: Private
 * INPUTS: string cityName
 * PURPOSE: Takes a city and traverses the vector of vectors to see if the cityName is already
 * present, if so, returns that vertex
 * OUTPUTS: returns vertex of cityName, otherwise NULL
*/
vertex * Graph::findVertex(string name) {
   	for (int i=0; i<vertices.size(); i++) {
		if (name == vertices[i].name) {
			return &vertices[i];
		}
	}
	return NULL;
}


/* FUNCTION: isAdjacent
 * CLASS MEMBER: Public
 * INPUTS: string first City name, string second City name
 * PURPOSE: Finds the vertex of the first City and traverses its adjacency list to
 * find the second City
 * OUTPUTS: 1 if adjacent, 0 otherwise
*/
int Graph::isAdjacent(std::string v1, std::string v2) {
	vertex *tmp = findVertex(v1);
	if (!tmp) {
		return 0;
	}
	else if (tmp) {
		vector<adjVertex> tmpAdj = tmp -> adj;
		for (int i=0; i<tmpAdj.size(); i++) {
			if (tmpAdj[i].v -> name == v2) {
				return 1;
			}
			else{
			}
		}
	}
	else {
		return 0;
	}
	return 0;
}


/* FUNCTION: assignDistricts
 * CLASS MEMBER: Public
 * INPUTS: none
 * PURPOSE: Calls the private helper function DFSLabel to find a starting city and assign an ID
 * OUTPUTS: none
*/
void Graph::assignDistricts() {
	int IDcounter = 0;
	for (int i=0; i<vertices.size(); i++) {
		if (vertices[i].districtID == -1) {
			vertices[i].visited = false;
			DFSLabel(vertices[i].name, IDcounter);
			// vertices[i].visited = false;
			IDcounter++;
		}
	}
}


/* FUNCTION: DFSLabel
 * CLASS MEMBER: Private
 * INPUTS: string of the startingCity name, ID to assign
 * PURPOSE: accesses the vertices vector and assigns a district ID to each isolated network of
 * cities by parsing through all adjacent cities of startingCity and then all of the adjacent
 * cities of those cities; utilizes the depth first search algorithm
 * OUTPUTS: none
*/
void Graph::DFSLabel(std::string startingCity, int distID) {
	queue<vertex*> Q;
	for (int i=0; i< vertices.size(); i++) {
		if (vertices[i].name == startingCity) {
			// vertices[i].visited = false;
			Q.push(&vertices[i]);
			vertices[i].districtID = distID;
			break;
		}
	}
	while(!Q.empty()) {
		vertex *front = Q.front();
		Q.pop();
		for (int k=0; k<front ->adj.size(); k++) {
			if (!front -> adj[k].v -> visited) {
				front -> adj[k].v -> visited = true;
				front -> adj[k].v -> districtID = distID;
				Q.push(front -> adj[k].v);
			}
		}
	}
}


/* FUNCTION: shortestPath
 * CLASS MEMBER: Public
 * INPUTS: string startingCity, string endingCity
 * PURPOSE: uses the breadth first search to find the shortest path between two
 * cities
 * OUTPUTS: none
*/
void Graph::shortestPath(string startingCity, string endingCity) {
	vertex *start = findVertex(startingCity);
	vertex *end = findVertex(endingCity);
	int minTravel = 0;
	if (!start || !end) {
		cout << "\nOne or more cities doesn't exist" << endl;
		return;
	}
	int ID = 0;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		vertices[i].ID = ID;
		if (vertices[i].districtID == -1){
			cout << "\nPlease identify the districts before checking distances" << endl;
			return;
		}
		ID++;
	}
	if (end -> districtID != start -> districtID) {
		cout << "\nNo safe path between cities" << endl;
		return;
	}
	queue<vertex*> Q;
	vector<vertex*> printShortestPath;
	Q.push(start);
	start->visited = true;
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
	    for (int i=0; i<(int)node->adj.size(); i++) {
	        if (!node -> adj[i].v -> visited) {
	        	node -> adj[i].v -> visited = true;
	        	node -> adj[i].v -> parent = node;
	           	if (node -> adj[i].v -> name == endingCity) {
	            	vertex *tmp = node -> adj[i].v;
	            	while (tmp) {
	            		tmp -> weightedDistance = tmp -> adj[i].weight;
	            		printShortestPath.push_back(tmp);
	            		if (tmp -> parent -> name == startingCity) {
	            			break;
	            		}
	            		tmp = tmp -> parent;
	            	}
	            	break;
	            }
	            Q.push(node ->adj[i].v);
	        }
	    }
	}
	int minDistance = 1;
	int minTravel2 = 0;
	cout << "\n" << startingCity;
	for (int i=printShortestPath.size()-1; i>0; i--) {
		cout << ", " << printShortestPath[i] -> name;
		minDistance++;
	}
	cout << ", " << endingCity << endl;
	cout << "\nThe minimum distance is: " << minDistance << " segments\n" << endl;
}


/* FUNCTION: shortestWeightedPath
 * CLASS MEMBER: Public
 * INPUTS: string startingCity, string endingCity
 * PURPOSE: uses Dijkstra's algorithm to find the shortest weighted distance between cities.
 * There is currently a problem with it, where it is exiting without exploring all the possibilities,
 * likely due to choice of vertex over queue?
 * OUTPUTS: none
*/
void Graph::shortestWeightedPath(string startingCity, string endingCity) {
	vertex *startV = findVertex(startingCity);
	vertex *endV = findVertex(endingCity);
	if (!startV || !endV) {
		cout << "\nOne or more cities doesn't exist" << endl;
		return;
	}
	for (int i=0; i<vertices.size();i++) {
		if (vertices[i].name != startingCity) {
			vertices[i].visited = false;
			vertices[i].parent = NULL;
			vertices[i].weightedDistance = INT_MAX;
		}
		else if (vertices[i].name != startingCity) {
			vertices[i].visited = true;
			vertices[i].parent = NULL;
			vertices[i].weightedDistance = 0;
		}
	}
	if (startV->districtID == -1){
		cout << "\nPlease identify the districts before checking distances" << endl;
		return;
	}
	if (startV->districtID != endV->districtID) {
		cout << "\nNo safe path between cities" << endl;
		return;
	}
	endV->visited = false;
	startV->visited = true;
	startV->weightedDistance = 0;
	vector<vertex*> visited;
	vertex *visitedV = new vertex;
	visited.push_back(startV);
	vertex *parent = new vertex;
	int dist;
	while(!endV->visited) {
		int minDistance = INT_MAX;
		visitedV = NULL;
		for (int x=0; x<(int)visited.size(); x++) {
			vertex *v = visited[x];
			for (int y=0; y<(int)v->adj.size(); y++) {
				if (!v->adj[y].v->visited) {
					dist =(int)v->weightedDistance + (int)v->adj[y].weight;
					if (dist<minDistance) {
						visitedV = v->adj[y].v;
						minDistance = dist;
						parent = v;
					}
				}
			}
		}
		visitedV->weightedDistance = minDistance;
		visitedV->parent = parent;
		visitedV->visited = true;
		visited.push_back(visitedV);
	}
	vector<vertex*> solved;
	solved.push_back(endV);
	cout << "\nThe minimum distance is: " << endV->weightedDistance<< endl;
	cout << startingCity << ", ";
	while(endV->name != startingCity) {
		if (endV->parent->name == startingCity) {
			cout << endingCity << endl;
			break;
		}
		cout << endV ->parent->name;
		endV = endV -> parent;
		if (endV->name != startingCity) {
			cout << ", ";
		}
		else if (endV->parent->name == startingCity) {
			cout << endingCity << endl;
			break;
		}
	}
}