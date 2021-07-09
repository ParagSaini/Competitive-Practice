#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
int n, k;
vector<vector<int>> edges;
vector<int> level;
vector<bool> visited;
vector<int> descendant;

int dfs(int node, int lvl) {
	level[node] = lvl;
	visited[node] = true;
	int cnt = 0;
	for(auto child : edges[node]) {
		if(visited[child] == false) {
			cnt += dfs(child, lvl+1);
		}
	}
	descendant[node] = cnt;
	return (1 + cnt);
}

void solve() {
	cin>>n>>k;
	ll ans = 0;
	edges.resize(n+1);
	visited.resize(n+1, false);
	level.resize(n+1);
	descendant.resize(n+1);

	vector<int> contribution;
	for(int i=1; i<=(n-1); i++) {
		int s, d;
		cin>>s>>d;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	dfs(1, 0);
	for(int i=1; i<=n; i++) {
		contribution.push_back(level[i] - descendant[i]);
	}
	sort(contribution.begin(), contribution.end(), greater<int>());
	for(int i=0; i<k; i++) ans += (ll)contribution[i];
	cout<<ans<<"\n";

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