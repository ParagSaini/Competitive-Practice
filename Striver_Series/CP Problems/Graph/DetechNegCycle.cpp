#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
const ll INF = 1e10;
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
	dist[0] = 0;    // starting the bellman ford from node 0. We must start from here in order to tackle the case when there are multi component in the graph.

	vector<int> parent(n+1, -1);  // to print the negative cycle
	// exactly (n-1) time , n -- number of total nodes

	for(int i=0; i<=(n-1); i++) {
		for(auto it : edges) {
			if(dist[it.s] != INF && dist[it.s] + it.w < dist[it.d]) {
				dist[it.d] = dist[it.s] + it.w;
				parent[it.d] = it.s;
			}
		}
	}
	int cycleNode = -1;
	// doing it for the 1 more time to detect the cycle
	for(auto it : edges) {
		if(dist[it.s] != INF && dist[it.s] + it.w < dist[it.d]) {
			cycleNode = it.d;
			break;			
		}
	}
	if(cycleNode == -1) cout<<"NO \n";
	else {
		cout<<"YES\n";
		// doing n times to get in the loop of negative cycle.
		for(int i=0; i<=n; i++) cycleNode = parent[cycleNode];

		vector<int> cycle;
		cycle.push_back(cycleNode);
		int v = cycleNode;
		do {
			v = parent[v];
			cycle.push_back(v);
		} while(v != cycleNode);

		reverse(cycle.begin(), cycle.end());
		for(auto it : cycle) cout<<it<<" ";
	}
	
}
void solve() {
	cin>>n>>m;
	dist.resize(n+1, INF);
	for(int i=0; i<m; i++) {
		int s, d, w;
		cin>>s>>d>>w;
		edges.push_back(node(s, d, w));
	}
	for(int i=1; i<=n; i++) {
		edges.push_back(node(0, i, 0));   // making a auxillary node connected to each node with weight == 0, so we can also able to detect cycle in multiple component in the graph.
	}
	bellmanFord();
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