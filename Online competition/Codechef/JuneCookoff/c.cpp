#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {
	int n, m;
	cin>>n>>m;
	vector<string> arr(n);
	int res = 0;
	for(int i=0; i< n; i++) {
		cin>>arr[i];
	}
	// whichever sequence we fold the matrix, the end result of the matrix will be the xor of all the elements. visualise it for betttr understanding.
	for(int i=0; i<n; i++) {
		for(int j= 0; j<m; j++) {
			res ^= (arr[i][j] - '0');
		}
	}
	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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