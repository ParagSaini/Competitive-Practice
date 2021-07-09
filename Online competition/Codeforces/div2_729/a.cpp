#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n;
	cin>>n;
	int cnt1 = 0, cnt2 = 0;
	for(int i=1; i<=(2*n); i++) {
		int x;
		cin>>x;
		if(x%2 == 0) cnt1++;
		else cnt2++;
	}	
	if(cnt1 == n && cnt2 == n) cout<<"Yes\n";
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