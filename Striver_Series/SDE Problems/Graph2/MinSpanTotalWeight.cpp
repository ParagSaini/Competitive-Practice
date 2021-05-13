#include<bits/stdc++.h>
using namespace std;

// using the prim's algo
// t.c O(ElogE)
class graphEdge {
	public:
	int src, dest, weight;
	graphEdge(int s, int d, int w) {
		src = s;
		dest = d;
		weight = w;
	}
};
class compare{
    public:
    bool operator()(graphEdge a, graphEdge b) {
    	return a.weight > b.weight;
    }
};
void calculateWeight(priority_queue<graphEdge, vector<graphEdge>, compare>& q, vector<vector<int>>& graph, int curV, int& ans, vector<bool>& visited) {
    if(visited[curV] == true) return;
    visited[curV] = true;
    // traversing the each edge conneted to curV
    for(int i=0; i<graph.size(); i++) {
        if(graph[curV][i] != INT_MAX && visited[i] == false) {
            q.push(graphEdge(curV, i, graph[curV][i]));
        }
    }
    // this is possible that q.top().dest is also visited, this can occur when all the edges are already visited by us
    while(!q.empty() && visited[q.top().dest] == true) q.pop();
    if(q.empty()) return;        // all edges visited.
    ans += q.top().weight;
    int nextV = q.top().dest;
    q.pop();
    calculateWeight(q, graph,nextV,ans, visited);
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    int ans = 0;
    vector<bool> visited(V, false);
    priority_queue<graphEdge, vector<graphEdge>, compare> q;
    calculateWeight(q, graph, 0, ans, visited);
    return ans;
}


// using the krushal algo for calculating the total weight in the min spanning tree.

class disjointSet{
	public:
	vector<int> ar;
	disjointSet(int n) {
		for(int i=0; i<n; i++) ar.push_back(-1);
	}
	int find(int val) {
		if(ar[val] == -1) return val;
		int Up_parent = find(ar[val]);
		ar[val] = Up_parent;   // path compression
		return Up_parent;
	}
	bool setUnion(int val1, int val2) {
		int leader1 = find(val1);
		int leader2 = find(val2);
		if(leader1 != leader2) ar[leader2] = val1;
		if(leader1 != leader2) return true;
		return false;
	}
};
class graphEdge {
	public:
	int src, dest, weight;
	graphEdge(int s, int d, int w) {
		src = s;
		dest = d;
		weight = w;
	}
};
bool compare(graphEdge a, graphEdge b) {
	return a.weight < b.weight;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    
    vector<graphEdge> temp;
    for(int i=0; i<V; i++) {
        for(int j=i+1; j<V; j++) {
            if(graph[i][j] != INT_MAX) {
                temp.push_back(graphEdge(i, j, graph[i][j]));
            }
        }
    }
    sort(temp.begin(), temp.end(), compare);
    int ans = 0;
    disjointSet d_set(V);
	for(int i=0; i<temp.size(); i++) {
		int curW = temp[i].weight;
		int curS = temp[i].src;
		int curD = temp[i].dest;

		if(d_set.setUnion(curS, curD)) {
			ans += curW;
		}
	}
	return ans;
}