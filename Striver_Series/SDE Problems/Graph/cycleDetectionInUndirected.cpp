#include<bits/stdc++.h>
using namespace std;
// doing the bfs search, and keep track of the visited nodes, and if cur node is visited but the edge is not discovered yet, means there is a cycle in it;

bool isCyclic(vector<int> adj[], int V)
{
   unordered_set<int> explored;
   unordered_map<int, unordered_set<int>> discoveredEdge;
   
   for(int i=0; i<V; i++) {
       // to process the different connected components in graph
        if(!explored.count(i)) {
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int x = q.front();
                // traversing the neighbors
                for(int i=0; i<adj[x].size(); i++) {
                    int temp = adj[x][i];
                    if(explored.count(temp) && !(discoveredEdge.count(x) && discoveredEdge[x].count(temp)) ) {
                        return true;
                    }
                    if(!explored.count(temp)) {
                        explored.insert(temp);
                        q.push(temp);
                        discoveredEdge[x].insert(temp);
                        discoveredEdge[temp].insert(x);
                    }
                }
                explored.insert(x);
                q.pop();
            }
        }
    }
    return false;
   
}