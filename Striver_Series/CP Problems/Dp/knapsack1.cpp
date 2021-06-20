#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// USE THE REFERENCE VARIABLE IN THE RECURSIVE CALLS IF POSSIBLE, DO NOT MAKE THE COPY OF SAME THING AGAIN AND AGAIN, IT WILL HUGELY INCREASE YOUR T.C (10 times)

// t.c O(n.W), s.c O(n.W)
vector<pair<int, int>> items(101);
vector<vector<ll>> dp(101);
int n, W;

ll solve(int ind, int curW) {
	if(ind == n) return 0;

	if(dp[ind][curW] != -1) return dp[ind][curW];

	ll a = INT_MIN;
	if(curW >= items[ind].first) a = (ll)items[ind].second + solve(ind+1,curW - items[ind].first);
	ll b = (ll)solve(ind+1, curW);

	dp[ind][curW] = max(a, b);

	return dp[ind][curW];
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
		cin>>n>>W;
		for(int i=0; i<n; i++) {
			int w, v;
			cin>>w>>v;
			items[i] = make_pair(w, v);
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<=W; j++) {
				dp[i].push_back(-1);
			}
		}
		cout<<solve(0, W)<<endl;
	}
	return 0;
}