#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;


bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   unordered_set<int> explored;
   unordered_map<int, unordered_set<int>> discoveredEdge;
   
   for(int i=0; i<V; i++) {
        if(!explored.count(i)) {
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int x = q.front();
                for(int i=0; i<adj[x].size(); i++) {
                    int temp = adj[x][i];
                    bool isdiscovered = (discoveredEdge.count(x) && discoveredEdge[x].count(temp)) || (discoveredEdge.count(temp) && discoveredEdge[temp].count(x));
                    if(explored.count(temp) && !isdiscovered ) {
                        return true;
                    }
                    else if(!explored.count(temp)) {
                        explored.insert(temp);
                        q.push(temp);
                        discoveredEdge[x].insert(temp);
                    }
                }
                explored.insert(x);
                q.pop();
            }
        }
    }
    return false;
}