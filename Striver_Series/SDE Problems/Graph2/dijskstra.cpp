#include<bits/stdc++.h>
using namespace std;
// see striver video , https://www.youtube.com/watch?v=eKsJUlWwxic
// t.c O(mlog(n)), m -- edge, n-- vertices
// s.c O(m + n)
// vertices from 0 to n;
vector<int> shortestPath(int src, unordered_map<int, vector<pair<int, int>>> graph )
{
    // suppose graph is given as adjacent matrix form
    set<pair<int, int>> setds;
    vector<int> dist(graph.size(), INT_MAX);
    dist[src] = 0; // we are starting from the source itself, thats because 0.
    // MAKE PAIR IS SAME AS WE DID USING THE CURLY BRACKET, BUT SOME COMPILER GIVE ERROR WHEN USING CURLY BRACKET.
    setds.insert(make_pair(0,src));
    while(!setds.empty()) {
        pair<int, int> minWeightNode = *(setds.begin());
        // go to adjacent nodes 
        for(auto it : graph[minWeightNode.second]) {
            int adjNode = it.second;
            int adjDist = it.first;
            int curDis = minWeightNode.first + adjDist;
            if(curDis < dist[adjNode]) {
                if(dist[adjNode] != INT_MAX) {
                    setds.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = curDis;
                setds.insert(make_pair(curDis, adjNode));
            }
        }
        setds.erase(minWeightNode);

    }
    return dist;
}
int main() {
    unordered_map<int, vector<pair<int, int>>> graph;
    graph[0] = {{6,1}, {4,2}};
    graph[1] = {{6,0}, {1,2}, {6,4}};
    graph[2] = {{4,0}, {1,1}, {2,3}};
    graph[3] = {{2,2}, {3,4}, {11,5}};
    graph[4] = {{6,1}, {3,3}, {1,5}};
    graph[5] = {{1,4}, {11,3}};
    vector<int> ans = shortestPath(0, graph);
    for(int i=0; i<ans.size(); i++) {
        cout<<i<<" "<<ans[i]<<endl;
    }
}