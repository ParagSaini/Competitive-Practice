#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<queue>
using namespace std;
class Node {
public:
    int destination;
    int distance;
    Node(int destination, int distance = 0) {
        this->destination = destination;
        this->distance = distance;
    }

};
class UndirectedGraph {
public:
    unordered_map<int, list<Node>> graph;
    void insertEdge(int s, int d, int dis);
    void printUndirectedGraph();
    void printAdj();
    unordered_map<int, vector<int>> Adjacent();
    bool Bfs(int start, int V, unordered_map<int, vector<int>> adj);
    bool Dfs(int start, unordered_map<int, vector<int>> adj );
    int ShortestPathLengthBfs(int start, int source, unordered_map<int, vector<int>> adj);
};
int UndirectedGraph::ShortestPathLengthBfs(int source, int destination, unordered_map<int, vector<int>> adj) {
    if(source == destination) return 0;
    int length = -1;
    queue<int> q;
    unordered_map<int, int> parentMap;
    unordered_set<int> explored;
    q.push(source);
    parentMap[source] = source;
    explored.insert(source);

    bool flag = false;
    while(!q.empty()) {
        int x = q.front();

        for(int i=0; i<adj[x].size(); i++) {
            int temp = adj[x][i];
            if(temp == destination) {
                parentMap[temp] = x;
                flag = true;
                break;
            }
            else if(!explored.count(temp)) {
                q.push(temp);
                explored.insert(temp);
                parentMap[temp] = x;
            }
        }
        if(flag) break;
        q.pop();
    }
    if(flag == false) return -1;             // there is no root between two vertices

    vector<int> pathVert;
    pathVert.push_back(destination);
    int sr = destination;
    while(sr != source) {
        pathVert.push_back(parentMap[sr]);
        sr = parentMap[sr];
    }
    for(auto i : pathVert) cout<<i<< " ";
    cout<<endl;
    return pathVert.size();
}
bool UndirectedGraph::Dfs(int start,unordered_map<int, vector<int>> adj ) {      //dfs for connected graph
    static unordered_set<int> explored;
    static unordered_map<int, unordered_set<int>> discoveredEdge;
    static bool cycle;
    int s = start;          // converting start to int
    explored.insert(s);
    cout<<s<<" ";
    vector<int> adjacNode = adj[s];
    for(int i=0; i<adjacNode.size(); i++) {
        bool isdiscovered = (discoveredEdge.count(s) && discoveredEdge[s].count(adjacNode[i]) )|| ( discoveredEdge.count(adjacNode[i]) && discoveredEdge[adjacNode[i]].count(s) );
        if(!explored.count(adjacNode[i])) {
            explored.insert(adjacNode[i]);
            discoveredEdge[s].insert(adjacNode[i]);
            int vert = adjacNode[i];
            Dfs(vert, adj );
        }
        else if(!isdiscovered) {
            cycle = true;
        }
    }
    return cycle;

}
bool UndirectedGraph::Bfs(int start, int V, unordered_map<int, vector<int>> adj) {         // bfs traversal for undirected as well as directed Graph(that may contain sub graph)
    // say the number of node = V, starting from 1 to V;
    int s = start;          // converting start to int
    unordered_set<int> vertices;
    for(int i=1; i<=V; i++) {              // putting all vertex in the set
        vertices.insert(i);
    }
    unordered_set<int> explored;
    unordered_map<int, unordered_set<int>> discoveredEdge;
   
    while(vertices.size() != 0) {           // starting from the 0th vertex
        if(vertices.count(start)) {
            s = start;
        }
        else {
            s = *vertices.begin();
        }
        if(!explored.count(s)) {
            queue<int> q;
            q.push(s);
            explored.insert(s);
            vertices.erase(s);

            while(!q.empty()) {
                int x = q.front();
                for(int i=0; i<adj[x].size(); i++) {
                    int temp = adj[x][i];
                    if(explored.count(temp) && ! ( (discoveredEdge.count(x) && discoveredEdge[x].count(temp)) || (discoveredEdge.count(temp) && discoveredEdge[temp].count(x)) ) ) {
                        // return true;             commented it so, that we traverse the full graph
                        // if only want to know graph has cycle or not, uncomment it.
                    }
                    else if(!explored.count(temp)) {
                        explored.insert(temp);
                        vertices.erase(temp);
                        q.push(temp);
                        discoveredEdge[x].insert(temp);
                    }
                }
                vertices.erase(x);
                cout<<x<<" ";
                q.pop();
            }
        }
    }
    return false;

}
unordered_map<int, vector<int>> UndirectedGraph::Adjacent() {
    unordered_map<int, vector<int>> result;
    for(auto i : graph) {
        result[i.first ];
        for(auto it = i.second.begin(); it != i.second.end(); it++) {
            result[i.first ].push_back(it->destination);
        }
    }
    return result;
}
void UndirectedGraph::insertEdge(int s, int d, int dis = 0) {
    graph[s].push_back(Node(d,dis));
    graph[d].push_back(Node(s,dis));
}
void UndirectedGraph::printUndirectedGraph() {
    for(auto i : graph) {
        for(auto it = i.second.begin(); it != i.second.end(); it++) {
            cout<<i.first<<" "<<it->destination<<" "<<it->distance<<"   ";
        }
    }
}
void UndirectedGraph::printAdj() {
    unordered_map<int, vector<int>> x = Adjacent();
    for(auto vert : x) {
        cout<<vert.first<<"    ";
        for(int i=0; i<vert.second.size(); i++ ) {
            cout<<vert.second[i]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    system("cls");
    UndirectedGraph g;
    // g.insertEdge(1,3);
    // g.insertEdge(1,2);
    // g.insertEdge(2,3);
    // g.insertEdge(5,2);
    // g.insertEdge(2,4);
    // g.insertEdge(4,3);
    // g.insertEdge(5,6);
    // g.insertEdge(6,7);
    // g.insertEdge(4,7);
    // g.insertEdge(4,8);
    // g.insertEdge(4,9);
    // g.insertEdge(8,11);
    // g.insertEdge(9,10);
    // g.insertEdge(11,10);
    // g.insertEdge(10,12);
    // g.insertEdge(12,13);
    // g.insertEdge(13,14);
    // g.insertEdge(12,14);
    g.insertEdge(1,2);
    g.insertEdge(1,0);
    g.insertEdge(0,3);
    g.insertEdge(3,7);
    g.insertEdge(3,4);
    g.insertEdge(7,4);
    g.insertEdge(4,6);
    g.insertEdge(7,6);
    g.insertEdge(4,5);
    g.insertEdge(6,5);
    // g.Bfs(1,14,g.Adjacent());
    // cout<<g.ShortestPathLengthBfs(3,6,g.Adjacent());
    cout<<"hello sirji "<<endl;
    cout<<"Hello ji Kaiso ho sarro"<<endl;
    
    return 0;
}