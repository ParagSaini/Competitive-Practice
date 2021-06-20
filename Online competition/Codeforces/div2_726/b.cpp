#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p32;

void solve(ll n, ll m, ll i, ll j) {
	ll maxi = 0, maxi2 = 0;
	ll maxval = LLONG_MIN;
	pair<ll, ll> ans1, ans2;

	vector<pair<ll, ll>> corner = {{1,1}, {n,1}, {n,m}, {1, m}};

	for(ll k=0; k<corner.size(); k++) {
		if(abs(i-corner[k].first) + abs(j-corner[k].second) > maxval) {
			maxval = abs(i-corner[k].first) + abs(j-corner[k].second);
			maxi = k;
		}
	}
	ans1 = corner[maxi];
	maxval = LLONG_MIN;

	for(ll k=0; k<corner.size(); k++) {
		ll sum1 = abs(i-corner[k].first) + abs(j-corner[k].second) + abs(ans1.first - corner[k].first) + abs(ans1.second - corner[k].second);

		if(sum1 > maxval) {
			maxval = sum1;
			maxi2 = k;
		}
	}
	ans2 = corner[maxi2];
	cout<<ans1.first<<" "<<ans1.second<<" "<<ans2.first<<" "<<ans2.second<<endl;

}

void init_code() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main() {
	
	init_code();

	ll t;
	cin>>t;
	while(t--) {
		ll n, m, i, j;
		cin>>n>>m>>i>>j;
		solve(n, m, i, j);
	}
	return 0;
}