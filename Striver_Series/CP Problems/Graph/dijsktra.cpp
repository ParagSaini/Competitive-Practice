#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<vector<pair<int, int>>> edges;
int n, m;

void dijsktra() {
	set<pair<ll, ll>> setds;   // for getting node in ascending order of their weight till now.
	vector<ll> dist(n+1, LLONG_MAX);
	vector<int> parent(n+1);
	parent[1] = -1;

	dist[1] = 0;     // starting from node 1.
	setds.insert(make_pair(0, 1));
	while(!setds.empty()) {
		pair<ll, ll> minWeightNode = (*setds.begin());
		setds.erase(minWeightNode);  

		for(auto child : edges[minWeightNode.second]) {
			ll node = child.first;
			ll w = child.second;
			ll tillDist = minWeightNode.first + w;

			if(tillDist < dist[node]) {
				if(dist[node] != LLONG_MAX) {
					setds.erase(make_pair(dist[node], node));
				}
				parent[node] = minWeightNode.second;
				dist[node] = tillDist; 	 
				setds.insert(make_pair(tillDist, node));
			}
		}

	}

	if(dist[n] == LLONG_MAX) cout<<-1<<endl;
	else {
		int node = n;
		vector<int> path;
		path.push_back(n);
		while(parent[node] != -1) {
			path.push_back(parent[node]);
			node = parent[node];
		}
		reverse(path.begin(), path.end());
		for(auto p : path) printf("%d ", p);
	}
}

void solve() {
	scanf("%d %d", &n, &m);
	edges.resize(n+1);
	for(int i=0; i<m; i++) {
		int s, d, w;
		scanf("%d %d %d", &s, &d, &w);
		edges[s].push_back(make_pair(d, w));
		edges[d].push_back(make_pair(s, w));
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