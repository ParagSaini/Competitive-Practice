#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

ll solve(vector<ll> arr, ll k, ll x, ll s) {
	int n = arr.size();
	if(k < 0) return INT_MAX;
	if(s >= (n-1)) return 1;

	ll ans1 = INT_MAX	, ans2 = INT_MAX;
	int i;
	for(i=s; i<n; i++) {
		ll diff = arr[i] - arr[i-1];
		if(diff > x) {
			ans1 = 1 + solve(arr, k, x, i+1);
		
			ll needed = ceil((arr[i] - arr[i-1])/(double)x);
			needed--;
			// cout<<needed<<" ";
			ans2 = solve(arr, k-needed, x, i+1);
			break;
		}
	}
	if(i == n) return 1;
	return min(ans1, ans2);
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
		ll n, k, x;
		cin>>n>>k>>x;
		vector<ll> arr(n);
		for(int i=0; i<n; i++) cin>>arr[i];
		sort(arr.begin(), arr.end());

		cout<<solve(arr, k, x, 1);
	}
	return 0;
}