//
//  Graph.hpp
//  
//
//  Created by cami on 7/9/18.
//
//

#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct adjVertex;

/*
 This is the struct for each vertex in the graph.
 When you construct the shortest path between two vertices,
 you will need to store a pointer to the parent vertex.
 Also, you will use the distance members in your shortest
 path implementations.  The ID member should be an index
 that is increased every time a vertex is added to the graph.
 The first vertex will have an ID equal to zero.
 */
struct vertex{
    int ID;
    vertex *parent;
    std::string name;
    int districtID;
    bool visited;
    int unweightedDistance;
    int weightedDistance;
    std::vector<adjVertex> adj;
};

/*
 This is the struct for the adjacent vertices for each
 vertex in the graph. It contains a weight of the edge
 connecting the vertex and the adjacent vertex as well
 as a pointer to the adjacent vertex.
 */

struct adjVertex{
    vertex *v;
    int weight;
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);                                       // DONE
    void addVertex(std::string name);                                                               // DONE
    int isAdjacent(std::string v1, std::string v2);                                                 // DONE
    void displayEdges();                                                                            // DONE
    void assignDistricts();                                                                         // DONE
    // Breadth First Search
    void shortestPath(std::string startingCity, std::string endingCity);                            // DONE
    // Dijkstras
    void shortestWeightedPath(std::string startingCity, std::string endingCity);                    // DONE -but not correctly I don't think
    /**********************FUNCTION BELOW ADDED BY KATRINA**********************/
    void readInFileFunc(std::string fileNameString, Graph zombieGraph);                             // DONE                                                            // DONE
protected:
private:
    std::vector<vertex> vertices;
    vertex * findVertex(std::string name);                                                          // DONE
    /*
     Call this from within assignDistricts to label the districts.
     This method should implement a depth first search from the
     startingCity and assign all cities encountered the distID value.
     */
    void DFSLabel(std::string startingCity, int distID);                                            // DONE
};

#endif // GRAPH_H
