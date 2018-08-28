// Vectors
// Think "dynamic arrays" with automatic resizing
// #include <vector> // calls vector library
// vector < int > vec;  // declare a vector: need the word vector followed by <type>
// vec.push_back(2); // adds the number 2 to the end of the vector
// vec.pop_back(); // remove the last element from the vector

#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main () {
	vector <int> vec;
	for (int i = 1; i <=10; ++i)
	{
		vec.push_back(i*10);
	}
	cout << "The first elment in the vector is: " << vec[0] << endl;
	cout << "The first elment in the vector is: " << vec.front() << endl;
	cout << "The last elment in the vector is: " << vec.back() << endl;
	cout << "The size of the vector is: " << vec.size() << endl;

	cout << "Removing the last element fromt the vector..." << endl;
	vec.pop_back();

	cout << "The size of the vector is now: " << vec.size() << endl;
	cout << "The last elment in the vector is now: " << vec.back() << endl;
	
	vec.erase(vec.begin() + 1);
	cout << "Remove the second element in the vector" << endl;
	cout << "The second elment in the vector is now: " << vec[1] << endl;

	return 0;
}



// Graphs
// Directed vs undirected
// Weighted vs unweighted
// Representations: adjacency list vs adjacency matrix
// Simple graph: undirected unweighted with no self loop
// Directed: I follow a famous soccer played on twitter, but he doesnt follow me back
// Undirected: people that I have been on the same soccer team as - you can't be on someone elses
// team without them playing with you
// G = (V,E) where V =vertices and E = edges
// V ={set of all the nodes in the graph}
// E = {set of ordered pairs of people who have played together or are linked} // using math {} not programming
// direted graph has ordered pairs, undirected graph has unordered pairs
// Weighted- typically think of edges being weighted, but nodes can be weighted as well
// unweighted can be though of all edges having weight of 1
// this is varying capacity or emphasis on edges
// K sub 5 is a fully connected graph of 5 nodes
// K sub 4-e is a fully connected graph minus one edge
// Adjacency matrix -symmetric if undirected
// 			to here
// 	      0 1 2 3 4 5 6
// f	0 0 0 1 0 1 1 0
// r	1 1 0 0 0 0 0 
// o	2
// m	3
// 	    4
// 	    5
// 	    6
// symmetry matrix if undirected (1,0 = 0,1) - transpose of matrix, over the diagonal
// Lots of zeros in there - wasted space, we can condense into a list!
// n = total # nodes
// m - total # edges
// the degree of a node is just the number of edges that come into it (edges in undirected)
// for directed, you have in degree and out degree
// Adjacency list
// list of nodes where it points TO all the other adjacent nodes
// 0 -> 2 -> 4
// 1 -> 0
// 2 -> 1 -> 5
// 3
// 4
// 5
// 6
// to find the number of adjacent nodes by traversing the "list" (or vector or whatever)
// if we had weights we would restructure our nodes so that:
// Struct node {
// 	int key;
// 	int weight;
// 	node * next;
// }
// for a graph with n nodes and m edges
// 							adjacency matrix			adjacency list
// space					n^2							n+m

// time to check if 		
// w adjacent to v 			1							out degee of w (od(w))

// Time to visit all		n 							od(w)
// w adjacent to v

// Time to visit all		n^2							n+m
// edges

// homework : district id - two components in the same graph (totally separate components (no edges))
// labeling each city in the graph with the component its a part of
// i.e. district 1, district 2, 


// Quiz password: Monday