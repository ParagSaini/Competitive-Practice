#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<vector<int>> edges(3*100000);
vector<bool> visited(3*100000, false);
vector<int> foundedBy(3*100000);
int n, m;
void printPath(int lastComp) {

	vector<int> path;
	// cout<<lastComp<<" ";
	path.push_back(lastComp);
	while(foundedBy[lastComp] != -1) {
		// cout<<foundedBy[lastComp]<<" ";
		path.push_back(foundedBy[lastComp]);
		lastComp = foundedBy[lastComp];
	}
	cout<<path.size()<<endl;
	reverse(path.begin(), path.end());
	for(auto p : path) cout<<p<<" ";
}
void bfs(int root) {

	visited[root] = true;
	foundedBy[root] = -1;
	queue<int> q;
	q.push(root);

	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(auto child : edges[front]) {
			if(visited[child] == false) {
				if(child == n) {
					foundedBy[child] = front;
					printPath(n);
					return;
				}
				visited[child] = true;
				foundedBy[child] = front;
				q.push(child);
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
void solve() {
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	bfs(1);
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
	// cin>>t
	t = 1;
	while(t--) {
		solve();
	}
	return 0;
}