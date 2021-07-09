// kartik arora dp on trees - > https://www.youtube.com/watch?v=FAfSArGC8KY&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=7
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
vector<vector<int>> edges;
vector<vector<int>> dp;
int n, q;

void binary_lifting(int node, int par) {

	dp[node][0] = par;   // lifting of 2^0 == 1, above one height 

	for(int i=1; i<=29; i++) {
		if(dp[node][i-1] != -1) dp[node][i] = dp[dp[node][i-1]][i-1];
		// else dp[node][i] = -1  already done 
	}
	for(auto child : edges[node]) {
		binary_lifting(child, node);
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
void solve() {
	cin>>n>>q;
	edges.resize(n+1);
	dp.resize(n+1, vector<int>(30, -1));

	for(int i=2; i<=(n); i++) {
		int boss;
		cin>>boss;
		edges[boss].push_back(i); 
	}
	binary_lifting(1, -1);
	for(int i=0; i<q; i++) {
		int emp, k;
		cin>>emp>>k;

		cout<<liftnode(emp, k)<<"\n";
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