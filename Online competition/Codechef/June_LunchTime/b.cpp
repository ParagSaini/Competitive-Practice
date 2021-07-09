#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n;
	cin>>n;
	vector<int> lastZero, other;
	for(int i=0; i<n; i++) {
		int a;
		cin>>a;
		if((a&1) == 0) {
			lastZero.push_back(a);
		}
		else other.push_back(a);
	}
	for(auto it : lastZero) cout<<it<<" ";
	for(auto it : other) cout<<it<<" ";
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
		solve();
	}
	return 0;
}