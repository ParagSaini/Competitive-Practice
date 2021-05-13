#include<bits/stdc++.h>
using namespace std;

// t.c O(V+E) && s.c O(V)
// we can also use the freq array in place of the unordered_set
void dfs(int V, vector<int> adj[],int curNode, unordered_set<int>& visited, stack<int>& st) {
    if(visited.count(curNode)) return;
    
    visited.insert(curNode);       // market curNode as visited.
    // traversing the curNode children
    for(int i=0; i<adj[curNode].size(); i++) {
        dfs(V, adj, adj[curNode][i], visited, st);
    }
    st.push(curNode);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> Org_result;
    stack<int> result;
    unordered_set<int> visited;
    
    // traversing each component of the graph
    for(int i=0; i<V; i++) {
        if(!visited.count(i)) {
            dfs(V, adj, i, visited, result);
        }
    }
    // transfering the stack element into vector;
    while(!result.empty()) {
        Org_result.push_back(result.top());
        result.pop();
    }
    return Org_result;
}