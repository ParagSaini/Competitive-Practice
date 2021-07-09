#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
const ll INF = 1e17;
vector<vector<pair<int, int>>> edges;
vector<ll> dist;
int n, m;

// void dijsktra() {
// 	dist[1] = 0;
// 	set<pair<ll, ll>> setds;
// 	setds.insert(make_pair(0, 1));

// 	while(!setds.empty()) {
// 		pair<ll, ll> minWeightNode = (*setds.begin());
// 		setds.erase(minWeightNode);
		
// 		for(auto node : edges[minWeightNode.second]) {
// 			ll child = node.first;
// 			ll d = node.second;
// 			ll total = minWeightNode.first + d;
// 			if(total < dist[child]) {
// 				if(dist[child] != INF) {
// 					setds.erase(make_pair(dist[child], child));
// 				}
// 				dist[child] = total;
// 				setds.insert(make_pair(total, child));
// 			}
// 		}
// 	}
// 	if(dist[n] == INF) cout<<"-1";
// 	else cout<<dist[n];
// }

void improvedDijsktra() {       // or 0 1 bfs
	// we are using the completely same code of dijsktra, but instead of sets we are using the deque, we know that there are only two weights 0 and 1, in sets the edges with weight 0 is always on the top and turn of edge weight '1' will only come after when there are no '0' weight edges. similarly when weight is '0' we are pushing it front of deque. and we always pop the front elemenst, this make sure that the all '0' edge weight will come before the '1' edge weights.

	dist[1] = 0;
	deque<pair<ll, ll>> dq;
	dq.push_front(make_pair(0, 1));

	while(!dq.empty()) {
		pair<ll, ll> minWeightNode = dq.front();
		dq.pop_front();
		
		for(auto node : edges[minWeightNode.second]) {
			ll child = node.first;
			ll d = node.second;
			ll total = minWeightNode.first + d;
			if(total < dist[child]) {
				dist[child] = total;
				if(d == 0) dq.push_front(make_pair(total, child)); // if weight is '0' make suring that it will come before all '1' edge weights. therefore pushing front of deque.
				else dq.push_back(make_pair(total, child));
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
	improvedDijsktra();

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