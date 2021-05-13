#include<bits/stdc++.h>
using namespace std;

// time complexity = O(V+E) same as bfs
bool isBipartite(vector<vector<int>>& graph) {
	int V = graph.size();
	bool visited[V];
	// using 2-color method, 1 and 0 color
	int col[V];
	// initialising the visited array to false
	for(int i=0; i<V; i++) visited[i] = false;
	queue<int> q;

	// the below for loop is for in case there are multiple component in the graph
	for(int i=0; i<V; i++) {
		if(!visited[i]) {
			q.push(i);
			visited[i] = true;
			col[i] = 1;
			// doing the bfs
			while(!q.empty()) {
				int cur = q.front();
				q.pop();
				for(int i=0; i<graph[cur].size(); i++) {
					int neighbor = graph[cur][i];
					if(!visited[neighbor]) {
						visited[neighbor] = true;
						q.push(neighbor);
						col[neighbor] = !col[cur];
					} else {
						// if the neighbor as the same color as parent then, it is impossible to partition the graph in two parts.
						if(col[neighbor] == col[cur]) return false;
					}
				}
			}
		}
	}
	return true;	
}