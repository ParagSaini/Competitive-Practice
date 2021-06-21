// https://codeforces.com/contest/1539/problem/C

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {
	ll n, k, x;
	cin>>n>>k>>x;
	vector<ll> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(), arr.end());

	vector<ll> studentNeeded;
	for(int i=1; i<n; i++) {
		ll diff = arr[i] - arr[i-1];
		if(diff > x) {
			ll needed = ceil((arr[i] - arr[i-1])/(double)x) - 1;
			studentNeeded.push_back(needed);
		}
	}
	sort(studentNeeded.begin(), studentNeeded.end());   // to join the maximum number of groups using k students.

	ll ans = studentNeeded.size()+1;   // we can make atmost size+1 groups, without adding any students
	for(auto needed: studentNeeded) {
		k -= needed;
		if(k >= 0) {
			ans--;
		} else break;
	}
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