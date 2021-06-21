#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

bool comp(pair<ll, ll> a, pair<ll, ll> b ) {
	// don't use <= , unnecessary may give the tle in some questions.
	return (a.second < b.second);
}
void solve() {
	int n;
	cin>>n;
	vector<pair<ll, ll>> items(n);
	for(int i=0; i<n; i++) {
		ll a, b;
		scanf("%lld %lld", &items[i].first, &items[i].second);
	}

	sort(items.begin(), items.end(), comp);

	int i=0, j = n-1;
	ll minCost = 0, itembought = 0;
	while(i <= j) {
		if(itembought >= items[i].second) {
			itembought += items[i].first;
			minCost += items[i].first;
			i++;
		} 
		else {
			ll req = min(items[i].second - itembought, items[j].first);
			items[j].first -= req;
			itembought += req;
			minCost += (req*2);
			if(items[j].first == 0) {
				j--;
			}
		}
	}
	cout<<minCost<<endl;
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