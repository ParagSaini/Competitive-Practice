#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n, cnt = 0;
	cin>>n;
	vector<pair<int, int>> arr(n);
	for(int i=0; i<n; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = make_pair(a, i+1);  // 1 based indexing.
	}
	sort(arr.begin(), arr.end());

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			ll val = (ll)arr[i].first * arr[j].first;
			if(val > 2*n-1) break;
			if(val == arr[i].second + arr[j].second) cnt++;
		}
	}
	cout<<cnt<<endl;
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