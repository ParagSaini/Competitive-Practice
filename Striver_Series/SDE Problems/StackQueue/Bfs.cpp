#include<bits/stdc++.h>
using namespace std;

vector<int> Bfs(vector<int> adj[], int N) {
    vector<int> result;
    unordered_set<int> vertices;
    int s = 0;
    for(int i=0; i<N; i++) {              // putting all vertex in the set
        vertices.insert(i);
    }
    unordered_set<int> explored;
    unordered_map<int, unordered_set<int>> discoveredEdge;
   
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int x = q.front();
        for(int i=0; i<adj[x].size(); i++) {
            int temp = adj[x][i];
            if(!explored.count(temp)) {
                explored.insert(temp);
                q.push(temp);
                discoveredEdge[x].insert(temp);
            }
        }
        explored.insert(x);
        result.push_back(x);
        q.pop();
    }
    return result;
}

vector <int> bfs(vector<int> g[], int N) {

    vector<int> result = Bfs(g, N);
    return result;
}