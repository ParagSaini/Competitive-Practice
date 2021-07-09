// basically counting all the articulation points.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
const int INF = 1e9 + 7;

void dfs(int par, int node, vector<vector<int>>& graph, int& t, vector<bool>& articulation, vector<int>& tin, vector<int>& low, vector<bool>& visited) {
    
    visited[node] = true;
    tin[node] = t;
    low[node] = t;
    t++;
    int individualChild = 0;

    for(auto child : graph[node]) {
        if(child == par) continue;
        if(visited[child] == false) {
            dfs(node, child, graph, t, articulation, tin, low, visited);
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
int countArticulationPoints(int n, vector<vector<int>>& graph)    // vertices from 1 to n.
{
	vector<int> tin(n+1, INF), low(n+1, INF);
	vector<bool> visited(n+1, false);
    vector<bool> articulation(n+1, false);
    int cnt = 0;

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            int t = 1;
            dfs(-1, i, graph, t, articulation, tin, low, visited);  
        }
    }
    for(int i=0; i<articulation.size(); i++) {
        if(articulation[i] == true) cnt++;
    }
    return cnt;
}


void init_code() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main() {
	
	init_code();

	int n, m;
	cin>>n>>m;
	while(n != 0 && m != 0) {
		vector<vector<int>> graph(n+1);
		
		for(int i=0; i<m; i++) {
			int s, d;
			cin>>s>>d;
			graph[s].push_back(d);
			graph[d].push_back(s);
		}
		cout<<countArticulationPoints(n, graph)<<"\n";
		cin>>n>>m;
	}
	return 0;
}