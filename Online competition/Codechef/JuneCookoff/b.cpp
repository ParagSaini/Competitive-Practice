#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {
	int n;
	cin>>n;
	vector<int> arr(n);
	unordered_set<int> s = {1,2,3,4,5,6,7};
	for(int i =0; i<n; i++) cin>>arr[i];
	int i;
	for(i=0; i<n; i++) {
		s.erase(arr[i]);
		if(s.empty()) {cout<<(i+1)<<endl;return;}
	}
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