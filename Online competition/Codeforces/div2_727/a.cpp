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
	cin>>t;
	while(t--) {
		ll n, x, t;
		cin>>n>>x>>t;
		ll k = (t/x);  // number of participant collapsing with the start time. of current participant.
		
		ll ans = 0;
		if(k >= n) {
			ans += (n*(n-1)/2);
		}
		else {
			ans += (k*(n-k));
			// ll rem = (k-1);
			ans += (k*(k-1)/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}