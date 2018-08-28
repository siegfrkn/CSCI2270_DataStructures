// LECTURE SPRINT 17 UTILIZING BFS
/*
void Graph::printMislabeledParents(int startVertex) {
	// initializing every part of our graph to not be visited
	// this is something we should do in our constructor - something
	// that should be set when we add our vertex!!!!!
	vertex *start;
	for (int i = 0; i <(int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}
	queue<vertex*> Q; // stores whatever we are going to visit
	Q.push(start); // push in the starting vertex
	start->visited = true; // say we vistied this node so we don't repeat
	cout << start->value << endl;
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
	    //Students have to fill in this part of the code
	    for (int i=0; i<(int)node->adj.size(); i++) {
	        if (!node -> adj[i].v -> visited) {
	            if (node -> adj[i].v -> parentID != node -> value) {
            	    cout  << node -> adj[i].v -> value << endl;
	            }
	            node -> adj[i].v -> visited = true;
	            Q.push(node ->adj[i].v);
	        }
	    }
	}
}
*/

//DFS
/*
Goal is to go as deep as possible
Can be done recursively
DFS(node -> adj[i].v)


// PW FOR LECTURE QUIZ: f=ma