#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

bool found(int n, int a, int b, unordered_map<int, bool>& dp) {
	if(n == 1) {
		return true;
	}
	if(dp.count(n)) return dp[n];
	if(n%a == 0 && a != 1) {
		if(found(n/a, a, b, dp)) return true;
	}
	if(n > b) {
		if(found(n-b, a, b, dp)) return true;
	}
	return false;
}
void solve() {
	int n, a, b;
	cin>>n>>a>>b;
	unordered_map<int, bool> dp;
	if(found(n, a, b, dp)) cout<<"Yes\n";
	else cout<<"No\n";
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
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}