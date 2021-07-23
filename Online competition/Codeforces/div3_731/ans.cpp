#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n, k;
	cin>>n>>k;
	vector<ll> arr(n, INT_MAX);
	vector<int> pos(k), temp(k);
	for(int i=0; i<k; i++) cin>>pos[i];
	for(int i=0; i<k; i++) cin>>temp[i];

	for(int i=0; i<k; i++) {
		arr[pos[i]-1] = temp[i];
	}	
	vector<ll> left(n, INT_MAX), right(n, INT_MAX);
	ll prevMin = INT_MAX;

	for(int i=0; i<n; i++) {
		prevMin = min(prevMin+1, arr[i]);
		left[i] = prevMin;
	}
	prevMin = INT_MAX;
	for(int i=n-1; i>=0; i--) {
		prevMin = min(prevMin+1, arr[i]);
		right[i] = prevMin;
	}

	for(int i=0; i<n; i++) {
		cout<<(min(left[i], right[i]))<<" ";
	}
	cout<<"\n";
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
		getchar();
		solve();
	}
	return 0;
}