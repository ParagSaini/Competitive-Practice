#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

int n, sum;
vector<int> coins(101);
// vector<vector<int>> dp(101, vector<int>(1e6+10, -1));
int dp[101][1000010];

int recurhelper(int ind, int curSum) {
	if(curSum == 0) return 1;
	if(ind >= n) return 0;
	if(dp[ind][curSum] != -1) return dp[ind][curSum];

	int cnt = 0;
	for(int i=ind; i<n; i++) {
		if(curSum >= coins[i]) {
			int ans = recurhelper(ind, curSum - coins[i]);
			cnt = (cnt + ans) % mod;
		}
	}
	dp[ind][curSum] = cnt;
	return dp[ind][curSum];
}
void solve() {
	cin>>n>>sum;
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; i++) scanf("%d", &coins[i]);
	cout<<recurhelper(0, sum)<<endl;
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