#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
const ll INF = 1e18;

vector<vector<ll>> dist;
int n, m, q;

// dist[i][j] contains the minimum distance between the node i and j. 
void floydMarshall() {
	// choosing all nodes between the any two nodes, may we got a shorter path from there.
	for(int k=1; k<=n; k++) {
		// traversing each pair of node.
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > (dist[i][k] + dist[k][j]) ) {
					dist[i][j] = (dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}
void solve() {
	scanf("%d %d %d", &n, &m, &q);
	dist.resize(n+1, vector<ll>(n+1, INF));

	for(int i=0; i<m; i++) {
		int s, d, w;
		scanf("%d %d %d ", &s, &d, &w);
		// there is no need to maintain a edge matrix, we only need the dist matrix. 
		// edges[s].push_back(make_pair(d, w));
		// edges[d].push_back(make_pair(s, w));

		// the below line are important, there may be multiple edges between the same source and destination so, we should maintain a min value between source and destination. because we do next operation only on behalf of the current value in the dist matrix.
		if(dist[s][d] > w) dist[s][d] = w;
		if(dist[d][s] > w) dist[d][s] = w;
	}
	for(int i=1; i<=n; i++) dist[i][i] = 0;
	floydMarshall();
	for(int i=0; i<q; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		if(dist[n1][n2] == INF) cout<<"-1\n";
		else cout<<dist[n1][n2]<<"\n";
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