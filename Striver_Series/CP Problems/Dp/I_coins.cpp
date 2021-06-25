#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
vector<vector<double>> dp(3005, vector<double>(3005, -1.0));
double recurHelper(int heads, vector<double>& arr, int ind) {
	
	if(ind >= arr.size()) {
		if(heads == 0) return 1.0;
		return 0.0;
	}
	if(dp[ind][heads] != -1.0) return dp[ind][heads];
	// head 
	double a = arr[ind] * recurHelper(heads-1, arr, ind+1);
	// tail
	double b = (1.0- arr[ind]) * recurHelper(heads, arr, ind+1);
	dp[ind][heads] = (a + b);
	return dp[ind][heads]; 
}
void solve() {
	int n;
	cin>>n;
	vector<double> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	double ans = 0.0;
	int heads = (n/2 +1);
	for(int i=heads; i<=n; i++) {
		ans += (recurHelper(i, arr, 0));
	}
	cout<<setprecision(10);
	cout<<ans<<endl;
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