#include<bits/stdc++.h>
using namespace std;

// using the dfs search and keep track of the nodes which are on the current path, and if cur node is present in the node which is already present in the path, means a cycle.

bool isCyclicUti(vector<int> adj[], int curNode, vector<int>& onPath) {
    if(onPath[curNode] == 1) return true;
    onPath[curNode] = 1;
    // traversing the neighbors.
    for(int i=0; i<adj[curNode].size(); i++) {
        if(isCyclicUti(adj, adj[curNode][i], onPath)) {
            return true;
        }
    }
    onPath[curNode] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> onPath(V, 0);
    for(int i=0; i<V; i++) {
        if(isCyclicUti(adj, i, onPath)) return true;
    }
    return false;
}




