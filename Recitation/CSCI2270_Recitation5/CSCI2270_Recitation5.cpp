// Depth First Search
// function explore (G,v)
// 	v.vistied = true
// 	v.previsit = clock
// 	clock += 1
// 	for nei in v.neighbors
// 		if nei.visited = false
// 			explore(G, nei)
// 	v.postvisit = clock, clock+1

// Breadth Search First
// BFS(G, starting_node)
// Used to find connecting components
// Keep track of queue (vector) and visited (boolean property of node)
// O(|V|+ |E|) algorithm
// On direted or undireced, unweighted grapsh
// Can find the shortest path on UNWEIGHTED

// BFS PSEUDOCODE
// BFS(starting_node)
// 	current = starting_node
// 	queue.enqueue(starting_node)
// 	while (queue is not empty)
// 			for neighbor in current.neighbor
// 					if neighbor.visited = false
// 						queue.enqueue(neighbor)
// 						neighbor.vistied =true
// 				current = queue.pop_front()
// 	return visited neighbors

// DIJKSTRAS algorithm
// like BFS but keeping track of weighted distances
// Shortest distance from starting  _node to every other node in the grapsh
// Relies on the property that the shortest path from s to t is also the shortest
// path to any of the vertices along the path
// This is exactly what BFS does
// NON-NEG EDGE WEIGHTS
// dijkstra(G,w,s)
// for all u in V: u.dist = infinity, u.prev = NULL
// s.dist = 0
// H = Makequeue(V)
// while H is not empty
// 		 = H.pop_front()
// 		for all v in u.neighbors
// 				if v.dist > u.dist + w(u,v)
// 					v.dist = u.dist +w(u,v)
// 					v.prev = u


// HW
// -1 no edge between cites
// 0 city is itself
// any other number and its a city you can travel to


// Quiz password: FirstWatch