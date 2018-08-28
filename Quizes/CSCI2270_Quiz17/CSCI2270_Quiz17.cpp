bool Graph::ifPathExists(string vertex1, string vertex2) {
    vertex *start;
	for (int i = 0; i <(int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].name == vertex1) {
			start = &vertices[i];
		}
	}
	queue<vertex*> Q; // stores whatever we are going to visit
	Q.push(start); // push in the starting vertex
	start->visited = true; // say we vistied this node so we don't repeat
	//cout << start->name << endl;
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
	    //Students have to fill in this part of the code
	    for (int i=0; i<(int)node->adj.size(); i++) {
	        if (!node -> adj[i].v -> visited) {
	           if (node -> adj[i].v -> name == vertex2) {
            	//cout  << node -> adj[i].v -> name << endl;
            	return true;
	           }
	            node -> adj[i].v -> visited = true;
	            Q.push(node ->adj[i].v);
	        }
	    }
	}
	return false;
}