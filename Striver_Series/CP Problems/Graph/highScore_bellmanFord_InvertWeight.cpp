#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
const ll INF = 1e17, NINF = (-1) * INF;
// it is possible to get from 1 to n, means no need to add node '0' as we do in detect neg cycle problem.

class node {
public:
	int s, d, w;
	node(int a, int b, int c) {
		s = a; d = b; w = c;
	}
};
vector<node> edges;  // we only need the edges for bellman ford, so we only store edges.
vector<ll> dist;
int n, m;

void bellmanFord() {
	dist[1] = 0;    // starting the bellman ford from node 1

	for(int i=1; i<=(n-1); i++) {
		for(auto it : edges) {
			if(dist[it.s] == INF) continue;
			if(dist[it.s] + it.w < dist[it.d]) {
				dist[it.d] = dist[it.s] + it.w;
			}
			dist[it.d] = max(dist[it.d], NINF);  // such that every distance should be greater than NINF. This is a safety measure, but according to constraints in the question, we don't do this, we still pass the all cases. but suppose if don't do this and constrainst are different then may there is edge with weight less than NINF, and then when we another n-1 relaxation, and do NINF(dist[it.s]) + it.w this might less than dist[it.d], and it will create problem.
		}
	}
	
	for(int i=1; i<=(n-1); i++) {
		for(auto it : edges) {
			if(dist[it.s] == INF) continue;
			if(dist[it.s] + it.w < dist[it.d]) {
				dist[it.d] = NINF;   // so now we propogate this NINF to all the connected nodes.
			}
		}
	}

	
}

void solve() {
	cin>>n>>m;
	dist.resize(n+1, INF);
	for(int i=0; i<m; i++) {
		ll s, d, w;
		cin>>s>>d>>w;
		w = (-1)*w;     // converting w to -w.
		edges.push_back(node(s, d, w));
	}
	bellmanFord();
	if(dist[n] == NINF) cout<<"-1\n";
	else cout<<(-1)*dist[n]<<"\n";
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