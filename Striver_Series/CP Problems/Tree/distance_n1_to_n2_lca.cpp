// kartik arora dp on trees - > https://www.youtube.com/watch?v=s9zZOVsF_eo
// the structure is like the tree and it is sure that all the nodes are connected, means only 1 component.
// finding the lca and then doing simple mathematics.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
vector<vector<int>> edges;
vector<vector<int>> dp;
vector<int> level;
vector<bool> visited;
int n, q;

void binary_lifting(int node, int par) {
	visited[node] = true;
	dp[node][0] = par;   // lifting of 2^0 == 1, above one height 

	for(int i=1; i<=29; i++) {
		if(dp[node][i-1] != -1) dp[node][i] = dp[dp[node][i-1]][i-1];
		// else dp[node][i] = -1  already done 
	}
	for(auto child : edges[node]) {
		if(visited[child] == false) binary_lifting(child, node);
	}
}
int liftnode(int node, int k) {
	int i = 0;
	int parent = node;
	while(k != 0) {
		if(k&1) {
			parent = dp[parent][i];
			if(parent == -1) return -1;
		}
		k = (k>>1);
		i++;
	}
	return parent;
}
void getlevel() {
	queue<int> q;
	q.push(1);
	int l = 0;
	level[1] = l;
	visited[1] = true;

	while(!q.empty()) {
		l++;
		int s = q.size();
		while(s--) {
			int front = q.front();
			q.pop();
			for(auto child : edges[front]) {
				if(visited[child] == false) {
					visited[child] = true;
					level[child] = l;
					q.push(child);
				}
			}
		}
	}
}
void solve() {
	// cin>>n>>q;
	scanf("%d %d", &n, &q);
	edges.resize(n+1);
	dp.resize(n+1, vector<int>(30, -1));
	level.resize(n+1, 0);
	visited.resize(n+1, false);

	for(int i=1; i<=(n-1); i++) {
		int s, d;
		scanf("%d %d", &s, &d);
		edges[s].push_back(d);
		edges[d].push_back(s); 
	}
	getlevel();
	for(int i=0; i<=n; i++) visited[i] = false;
	binary_lifting(1, -1);
	
	for(int i=0; i<q; i++) {
		int x, y;
		// cin>>x>>y;
		scanf("%d %d", &x, &y);
		int u = x, v = y;

		if(level[u] < level[v]) swap(u, v);
		int l1 = level[u], l2 = level[v];
		int diff = l1 - l2;
		if(diff != 0) u = liftnode(u, diff);
		int lca;
		if(u == v) {
			lca = u;
			int dist = level[x] - level[lca] + level[y] - level[lca];
			// cout<<dist<<"\n";
			printf("%d\n", dist);
			continue;
		}
		for(int i=29; i>=0; i--) {
			if(dp[u][i] != dp[v][i]) {
				u = dp[u][i];
				v = dp[v][i];
			}
		}
		lca = liftnode(u, 1);
		int dist = level[x] - level[lca] + level[y] - level[lca];
		// cout<<dist<<"\n";
		printf("%d\n", dist);
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