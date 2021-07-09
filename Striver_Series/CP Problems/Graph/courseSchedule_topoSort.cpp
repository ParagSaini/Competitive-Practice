#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<vector<int>> edges;
int n, m;
vector<int> topoOrder;
vector<bool> visited;

void cycleDetection(int node, vector<bool>& curSeqVisited, bool& isExist) {

	if(curSeqVisited[node] == true) {
		isExist = true;
		return;
	}
	if(visited[node] == true) return;

	visited[node] = true;
	curSeqVisited[node] = true;

	for(auto child : edges[node]) {
		cycleDetection(child, curSeqVisited, isExist);
	}

	curSeqVisited[node] = false;
}
bool hasCycle() {
	bool isExist = false;
	vector<bool> curSeqVisited(n+1, false);
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			cycleDetection(i, curSeqVisited, isExist);
		}
	}
	return isExist;
	
}
void dfs(int node, stack<int>& st) {

	visited[node] = true;
	for(auto child : edges[node]) {
		if(visited[child] == false) {
			dfs(child, st);
		}
	}
	st.push(node);
}
void topoSort() {
	stack<int> st;
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			dfs(i,st);
		}
	}
	while(!st.empty()) {
		topoOrder.push_back(st.top());
		st.pop();
	}
	for(auto it : topoOrder) cout<<it<<" ";

}
void solve() {
	cin>>n>>m;
	edges.resize(n+1);
	visited.resize(n+1, false);
	for(int i=0; i<m; i++) {
		int s, d;
		cin>>s>>d;
		edges[s].push_back(d);
	}
	if(hasCycle()) cout<<"IMPOSSIBLE\n";
	else {
		for(int i=1; i<=n; i++) visited[i] = false;
		topoSort();
	}
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