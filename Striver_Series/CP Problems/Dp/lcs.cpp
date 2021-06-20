#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

class node{
public:
	int len;
	pair<int, int> parent;
	node(int a, pair<int, int> b) {
		len = a;
		parent = b;
	}
};

string a, b;
vector<vector<node>> dp(3001);

int solve(int s1, int s2) {
	if(s1 >= a.size() || s2 >= b.size()) return 0;

	if(dp[s1][s2].len != -1) return dp[s1][s2].len;


	if(a[s1] == b[s2]) {
		int c = 1 + solve(s1+1, s2+1);
		return c;
		// dp[s1][s2] = cur1;
		// return cur1;
	}
	int a = solve(s1+1, s2);
	int b = solve(s1, s2+1);
	return max(a, b);
	// return dp[s1][s2];
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
		cin>>a>>b;
		int n = a.length(), m = b.length();
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				dp[i].push_back(node(-1, {-1,-1}));
			}
		}
		cout<<solve(0, 0)<<endl;
	}
	return 0;
}