//Link: https://www.youtube.com/watch?v=TEbr3edMzo0
#include<bits/stdc++.h>
using namespace std;

void step1(int curNode, stack<int>& st, bool visited[], int V, vector<int> adj[]) {
    if(visited[curNode]) return;
    
    visited[curNode] = true;
    for(int i=0; i<adj[curNode].size(); i++) {
        step1(adj[curNode][i], st, visited, V, adj);
    }
    st.push(curNode);
}
void transposeGraph(vector<int> adj[], int V, vector<int> tGraph[]) {
    for(int i=0; i<V; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            int adjNode = adj[i][j];
            tGraph[adjNode].push_back(i);
        }
    }
}
void step3Dfs(int curNode, stack<int>& st, bool visited[], int V, vector<int> adj[]) {
    if(visited[curNode]) return;
    
    visited[curNode] = true;
    for(int i=0; i<adj[curNode].size(); i++) {
        step3Dfs(adj[curNode][i], st, visited, V, adj);
    }
}
void step3(int V, vector<int> tGraph[], stack<int>& st, bool visited[], int& count) {
    while(!st.empty()) {
        int cur = st.top();
        st.pop();
        if(!visited[cur]) {
            step3Dfs(cur, st, visited, V, tGraph);
            count++;
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    bool visited[V];
    stack<int> st;
    int count = 0;
    for(int i = 0; i<V; i++) visited[i] = false;
    
    // graph may be disconnected
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            step1(i, st, visited, V, adj);
        }
    }
    
    // transposed graph
    vector<int> tGraph[V];
    transposeGraph(adj, V, tGraph);
    
    for(int i=0; i<V; i++) visited[i] = false;
    step3(V, tGraph, st, visited, count);
    return count;
}