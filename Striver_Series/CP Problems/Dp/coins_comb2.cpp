#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

int findWays(int ind, vector<int>& coins, int sum, vector<vector<int>>& dp) {

	if(sum == 0) return 1;
	if(ind >= coins.size() || sum < 0) return 0;

	if(dp[ind][sum] != -1) return dp[ind][sum];

	int include = findWays(ind, coins, sum - coins[ind], dp) % mod;
	int notInclude = findWays(ind+1, coins, sum, dp) % mod;

	dp[ind][sum] = (include + notInclude) % mod;
	return dp[ind][sum];
}

void solve() {
	int n, sum ;
	cin>>n>>sum;
	vector<int> coins(n);
	vector<vector<int>> dp(n, vector<int>(sum + 10, -1));
	for(int i=0; i<n; i++) cin>>coins[i];
	cout<<findWays(0, coins, sum, dp);
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