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
	cout << "Reading in file..." << endl;
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
			// cout << vertexAdded -> name << endl;
			bool digitFlag = false;
			// cout << "Address of nodeCityName is " << ptrNodeCityName << endl;
			// cout << "Address of nodeCityName is " << &nodeCityName << endl;
			for (int k=0; k < word.length(); k++) {
				if (isdigit(word[k])) {
					digitFlag = true;
					// cout << word << " is a number" << endl;
				}
			}
			if (!digitFlag) {
				if (vertexAdded) {
					*ptrNodeCityName = word;
					// cout << "Beginning of this line is: " << *ptrNodeCityName << endl;
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
				// cout << "Counter is: " << counter << endl;
				string v2city = vertices[counter].name;
				// cout << "connecting city is" << v2city << endl;
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
// void Graph::printVertices(Graph myGraph) {
// 	for (int i=0; i<myGraph.vertices.size(); i++) {
// 		cout << myGraph.vertices[i].name;
// 		vector<adjVertex> tmp = myGraph.vertices[i].adj;
// 		for (int j =0; j<tmp.size(); j++) {
// 			cout << " -> " << tmp[j].v -> name;
// 		}
// 		cout << endl;
// 	}
// }
void Graph::displayEdges() {
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
		// cout << v1 << " and " << v2 << " not connected" << endl;
		return;
	}
	else if (weight == 0) {
		// cout << v1 << " and " << v2 << " are the same city" << endl;
		return;
	}
	else {
		vertex *findCity1 = findVertex(v1);
		adjVertex *adjv = new adjVertex;
		adjv -> v = findVertex(v2);
		adjv -> weight = weight;
		findCity1 -> adj.push_back(*adjv);
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
	// cout << name << " added!" << endl;
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
			// cout << "MATCH!" << endl;
			// cout << vertices[i].name << endl;
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
		// cout << "City " << v1 << "is not a member of this graph" << endl;
		return 0;
	}
	else if (tmp) {
		vector<adjVertex> tmpAdj = tmp -> adj;
		for (int i=0; i<tmpAdj.size(); i++) {
			if (tmpAdj[i].v -> name == v2) {
				// cout << v2 << " is adjacent to " << v1 << endl;
				return 1;
			}
			else{
				// cout << v2 << " is NOT adjacent to " << v1 << endl;
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
			vertices[i].visited = false;
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
			vertices[i].visited = true;
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
	cout << "\n" << startingCity;
	for (int i=printShortestPath.size()-1; i>0; i--) {
		cout << ", " << printShortestPath[i] -> name;
	minDistance++;
	}
	cout << ", " << endingCity << endl;
	cout << "\nThe minimum distance is: " << minDistance << "\n" << endl;
}


void Graph::shortestWeightedPath(std::string startingCity, std::string endingCity) {
	vertex *start = findVertex(startingCity);
	vertex *end = findVertex(endingCity);
	// int minDistance = 0;
	if (!start || !end) {
		cout << "\nOne or more cities doesn't exist" << endl;
		return;
	}
	int ID = 0;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		vertices[i].ID = ID;
		vertices[i].weightedDistance = INT_MAX;
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
	priority_queue<vertex*> Q;
	vector<vertex*> printShortestPath;
	Q.push(start);
	int dist = 0;
	start->visited = true;
	int minDistance = 0;
	// cout << "first ID: " << start -> ID << endl;
	// int minDistance = start -> adj[start->ID].weight;
	// cout << "minDistance is: " << minDistance << endl;
	while (!Q.empty()) {
		vertex *node = Q.top();
		Q.pop();
		// int minDistance = node -> adj[start->ID].weight;
	    for (int i=0; i<(int)node->adj.size(); i++) {
	        if (!node -> adj[i].v -> visited) {
	        	node -> adj[i].v -> visited = true;
	        	node -> adj[i].v -> parent = node;
	           	if (node -> adj[i].v -> name == endingCity) {
	            	vertex *tmp = node -> adj[i].v;
	            	tmp -> weightedDistance = node -> adj[i].weight;
	            	dist = node -> adj[i].weight;
	            	// minDistance = dist + minDistance;
	            	minDistance = minDistance + node -> adj[i].weight;
	            	while (tmp) {
	            		printShortestPath.push_back(tmp);
	            		// minDistance = dist + minDistance;
	            		// cout << tmp -> weightedDistance << endl;
	            		if (tmp -> parent -> name == startingCity) {
	            			break;
	            		}
	            		tmp = tmp -> parent;
	            	}
	            	break;
	           }
	           	Q.push(node ->adj[i].v);
	            dist = node -> adj[i].weight;
	        	// minDistance = dist + minDistance;
	        }
	        // dist = node -> adj[i].weight;
	        // minDistance = dist + minDistance;
	    }
	}
	// int minDistance = 0;
	cout << "\n" << startingCity;
	for (int i=printShortestPath.size()-1; i>0; i--) {
		cout << ", " << printShortestPath[i] -> name;
		// cout << "Segment Weight " << printShortestPath[i] -> weightedDistance << endl;
		minDistance = minDistance + printShortestPath[i] -> weightedDistance;
	}
	// minDistance
	cout << ", " << endingCity << endl;
	cout << "\nThe minimum distance is: " << minDistance << "\n" << endl;

}