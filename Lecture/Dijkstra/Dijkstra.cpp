// KATRINA SIEGFRIED
// CSCI2270 - DATA STRUCTURES
// EXTRA DEMONSTRATION OF WORKING DIJKSTRA
//
// BASED ON THE EXAMPLE IN THE TEXT BOOK


#include<vector>
#include<iostream>
#include<string>
#include <fstream>                                                         
#include <sstream>
#include <cstdlib>
#include <ctype.h>
#include<queue>
#include<climits>

using namespace std;


struct adjVertex;


struct vertex{
    int ID;
    vertex *parent;
    string name;
    int districtID;
    bool visited;
    int unweightedDistance;
    int weightedDistance;
    vector<adjVertex> adj;
};


struct adjVertex{
    vertex *v;
    int weight;
};


class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    int isAdjacent(std::string v1, std::string v2);
    void displayEdges();
    void assignDistricts();
    // Breadth First Search
    void shortestPath(std::string startingCity, std::string endingCity);
    // Dijkstras
    void shortestWeightedPath(std::string startingCity, std::string endingCity);
protected:
private:
    std::vector<vertex> vertices;
    vertex * findVertex(std::string name);
    void DFSLabel(std::string startingCity, int distID);
};


Graph::Graph() {
	vector <vertex> vertices;
}

Graph::~Graph() {
	vector <vertex> vertices;
	vertices.empty();
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
		else {
			vertices[i].visited = true;
			vertices[i].parent = NULL;
			vertices[i].weightedDistance = 0;
		}
	}
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		vertices[i].ID = i;
		if (vertices[i].districtID == -1){
			cout << "\nPlease identify the districts before checking distances" << endl;
			return;
		}
	}
	if (startV->districtID != endV->districtID) {
		cout << "\nNo safe path between cities" << endl;
		return;
	}
	endV->visited = false;
	startV->visited = true;
	startV->weightedDistance = 0;
	vector<vertex*> visited;
	visited.push_back(startV);
	vertex *parent = new vertex;
	int dist;
	while(!endV->visited) {
		int minDistance = INT_MAX;
		vertex *visitedV = NULL;
		for (int x=0; x<(int)visited.size(); x++) {
			vertex *v = visited[x];
			for (int y=0; y<(int)v->adj.size(); y++) {
				if (!v->adj[y].v->visited) {
					dist =v->weightedDistance + v->adj[y].weight;
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
	cout << "\nThe minimum distance is " << endV->weightedDistance << "\n" << endl;
	solved.push_back(endV);
	while (endV->name != startingCity) {
		cout << endV->parent->name;
		endV = endV->parent;
		if (endV->name != startingCity) {
			cout << ", ";
		}
	}
	cout << endl;
}



int main () {
	Graph();
	Graph myGraph;
	myGraph.addVertex("Start");
	myGraph.addVertex("A");
	myGraph.addVertex("B");
	myGraph.addVertex("C");
	myGraph.addVertex("D");
	myGraph.addVertex("E");
	myGraph.addVertex("F");
	myGraph.addVertex("G");
	myGraph.addVertex("End");
	myGraph.addEdge("Start", "A", 2);
	myGraph.addEdge("Start", "C", 3);
	myGraph.addEdge("Start", "B", 10);
	myGraph.addEdge("A", "B", 2);
	myGraph.addEdge("A", "F", 5);
	myGraph.addEdge("A", "G", 10);
	myGraph.addEdge("A", "Start", 2);
	myGraph.addEdge("B", "Start", 10);
	myGraph.addEdge("B", "A", 2);
	myGraph.addEdge("B", "C", 1);
	myGraph.addEdge("B", "D", 4);
	myGraph.addEdge("B", "E", 8);
	myGraph.addEdge("C", "Start", 3);
	myGraph.addEdge("C", "B", 1);
	myGraph.addEdge("C", "E", 4);
	myGraph.addEdge("D", "B", 4);
	myGraph.addEdge("D", "E", 2);
	myGraph.addEdge("D", "F", 2);
	myGraph.addEdge("D", "End", 5);
	myGraph.addEdge("E", "C", 4);
	myGraph.addEdge("E", "D", 2);
	myGraph.addEdge("E", "End", 7);
	myGraph.addEdge("F", "A", 5);
	myGraph.addEdge("F", "G", 2);
	myGraph.addEdge("F", "D", 2);
	myGraph.addEdge("G", "A", 10);
	myGraph.addEdge("G", "F", 2);
	myGraph.addEdge("G", "End", 3);
	myGraph.addEdge("End", "G", 3);
	myGraph.addEdge("End", "D", 5);
	myGraph.addEdge("End", "E", 7);
	myGraph.displayEdges();
	myGraph.assignDistricts();
	// myGraph.shortestPath("Start", "End");
	// myGraph.shortestWeightedPath("Start", "End");
	myGraph.shortestWeightedPath("End", "Start");
}