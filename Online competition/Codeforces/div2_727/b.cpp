// https://codeforces.com/contest/1539/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {

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
		int n, q;
		cin>>n>>q;
		ll sum =0 ;
		string str;
		cin>>str;
		vector<ll> prefixSum;

		for(int i=0; i<str.length(); i++) {
			sum += (str[i] - 'a'  + 1);
			prefixSum.push_back(sum);
		}
		// for(auto it : prefixSum) cout<<it<<" ";
		for(int i=0; i<q; i++) {
			int l, r;
			cin>>l>>r;
			l--;
			r--;
			int ans = prefixSum[r]-prefixSum[l] + (str[l]-'a'+1);
			cout<<ans<<endl;
		}

		// solve();
	}
	return 0;
}