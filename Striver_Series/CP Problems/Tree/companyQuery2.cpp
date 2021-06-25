#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
void getNodeLevel(vector<int>& nodeLevel, int level, int root, vector<vector<int>>& edges) {

	nodeLevel[root] = level;
	for(auto child : edges[root]) {
		getNodeLevel(nodeLevel, level+1, child, edges);
	}
}
void solve() {
	int n, q;
	cin>>n>>q;
	vector<vector<int>> edges(n+1);
	vector<int> parent(n+1), nodeLevel(n+1, 0);
	parent[1] = -1;

	for(int i=2; i<=n; i++) {
		int boss;
		cin>>boss;
		edges[boss].push_back(i);
		parent[i] = boss;
	}
	getNodeLevel(nodeLevel, 0, 1, edges);
	for(int k=0; k<q; k++) {
		int a, b;
		cin>>a>>b;
		int level_a = nodeLevel[a], level_b = nodeLevel[b];
		int lca1 = a, lca2 = b;

		if(level_a > level_b) {
			int diff = level_a - level_b;
			while(diff) {
				lca1 = parent[lca1];
				diff--;
			}
		}
		else {
			int diff = level_b - level_a;
			while(diff) {
				lca2 = parent[lca2];
				diff--;
			}
		}

		while(lca1 != lca2) {
			lca1 = parent[lca1];
			lca2 = parent[lca2];
		}
		
		cout<<lca1<<endl;
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