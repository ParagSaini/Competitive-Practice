#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

int findWays(vector<int>& coins, int sum, vector<int>& dp) {

	if(sum == 0) return 1;
	if(sum < 0) return 0;

	if(dp[sum] != -1) return dp[sum];

	int n = coins.size();
	int cnt = 0;
	for(int i=0; i<n; i++) {
		cnt = (cnt + findWays(coins, sum - coins[i], dp)) % mod;
	}
	dp[sum] = cnt;
	return cnt;
}
void solve() {
	int n, sum ;
	cin>>n>>sum;
	vector<int> coins(n);
	vector<int> dp(1e6+10, -1);
	for(int i=0; i<n; i++) cin>>coins[i];
	cout<<findWays(coins, sum, dp);
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