#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<vector<int>> edges;
vector<bool> visited;
int n, m;
vector<int> parent;

void printPath(int start, int end) {
	int cnt = 1;
	vector<int> path;
	path.push_back(end);
	// cout<<end<<" ";
	while(start != end) {
		// cout<<start<<" ";
		path.push_back(start);
		start = parent[start];
	}
	// cout<<end<<" ";
	path.push_back(end);
	cout<<path.size()<<endl;
	for(auto p : path) cout<<p<<" ";
}
bool dfs(int par, int root) {

	parent[root] = par;
	visited[root] = true;
	for(auto child : edges[root]) {

		if(child == par) continue;

		if(visited[child] == true) {
			// found the chain.
			printPath(root, child);
			return true;
		}
		else {
			bool found = dfs(root, child);
			if(found) return true;
		}
	}
	return false;
}
void solve() {
	cin>>n>>m;
	edges.resize(n+1);
	visited.resize(n+1, false);
	parent.resize(n+1);
	for(int i=0; i<m; i++) {
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	// there may be many components of the graph.
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			if(dfs(-1, i)) return;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}

void init_code() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main() {
	
	init_code();

	int t;
	// cin>>t;
	t = 1;
	while(t--) {
		solve();
	}
	return 0;
}