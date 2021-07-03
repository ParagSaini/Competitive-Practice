#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
const ll INF = 1e17;
vector<vector<pair<int, int>>> edges;
vector<ll> dist;
int n, m;

void dijsktra() {
	dist[1] = 0;
	set<pair<ll, ll>> setds;
	setds.insert(make_pair(0, 1));

	while(!setds.empty()) {
		pair<ll, ll> minWeightNode = (*setds.begin());
		setds.erase(minWeightNode);
		
		for(auto node : edges[minWeightNode.second]) {
			ll child = node.first;
			ll d = node.second;
			ll total = minWeightNode.first + d;
			if(total < dist[child]) {
				if(dist[child] != INF) {
					setds.erase(make_pair(dist[child], child));
				}
				dist[child] = total;
				setds.insert(make_pair(total, child));
			}
		}
	}
	if(dist[n] == INF) cout<<"-1";
	else cout<<dist[n];
}

void solve() {
	cin>>n>>m;
	edges.resize(n+1);
	dist.resize(n+1, INF);
	for(int i=0; i<m; i++) {
		int s, d;
		cin>>s>>d;
		edges[s].push_back(make_pair(d, 0));
		edges[d].push_back(make_pair(s, 1));
	}
	dijsktra();

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