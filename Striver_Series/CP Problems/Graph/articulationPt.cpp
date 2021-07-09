#include<bits/stdc++.h>
using namespace std;
// given a undirected graph, finding all the articulation points.
void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vector<int> tin, low;
vector<bool> visited;
const int INF = 1e9 + 7;

void dfs(int par, int node, vector<int> adj[], int& t, vector<bool>& articulation) {
    
    visited[node] = true;
    tin[node] = t;
    low[node] = t;
    t++;
    int individualChild = 0;

    for(auto child : adj[node]) {
        if(child == par) continue;
        if(visited[child] == false) {
            dfs(node, child, adj, t, articulation);
            low[node] = min(low[node], low[child]);

            if(low[child] >= tin[node] && par != -1) {
                // node is the articulation node.
                articulation[node] = true;
                // this may happen that same articulation point came many times in complete function run, therefore we are not printing them, because on printing we might get some duplicate vertices.
                
            }
            individualChild++;
        }
        else {
            low[node] = min(low[node], tin[child]);
        }
    }
    if(par == -1 && individualChild > 1) {
        articulation[node] = true;
    }
}
void articulationPoints(int V, vector<int> adj[])    // vertices from 0 to V-1.
{
    tin.resize(V, INF);
    low.resize(V, INF);
    visited.resize(V, false);
    vector<bool> articulation(V, false);
    for(int i=0; i<V; i++) {
        if(visited[i] == false) {
            int t = 1;
            dfs(-1, i, adj, t, articulation);  
        }
    }
    for(int i=0; i<articulation.size(); i++) {
        if(articulation[i] == true) cout<<i<<" ";
    }
}

int main() {
    init_code();

    vector<int> adj[] = {{1, 3}, {0, 2}, {1, 3}, {0, 2, 4}, {3, 5}, {4, 6, 8}, {5, 7}, {6, 8, 9}, {5, 7}, {7, 10, 11}, {9, 11}, {9, 10}};
    articulationPoints(12, adj);
}