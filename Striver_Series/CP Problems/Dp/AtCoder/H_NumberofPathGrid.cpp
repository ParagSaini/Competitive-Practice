#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
vector<vector<int>> dp(1001, vector<int>(1001, -1));

int helper(vector<string>& grid, int r, int c) {
	int n = grid.size(), m = grid[0].size();
	if(r == n-1 && c == m-1) return 1;
	if(dp[r][c] != -1) return dp[r][c];

	int cnt = 0;
	grid[r][c] = '#';
	for(int i=0; i<dir.size(); i++) {
		int nR = r + dir[i].first, nC = c + dir[i].second;
		if(nR >= n || nR < 0 || nC >= m || nC < 0 || grid[nR][nC] == '#') continue;

		cnt = ( cnt + helper(grid, nR, nC)) % mod;
	}
	grid[r][c] = '.';
	dp[r][c] = cnt;
	return dp[r][c];
}

void solve() {
	int n, m;
	cin>>n>>m;
	vector<string> grid(n);
	for(int i=0; i<n; i++) {
		cin>>grid[i];
	}
	cout<<helper(grid, 0, 0);
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