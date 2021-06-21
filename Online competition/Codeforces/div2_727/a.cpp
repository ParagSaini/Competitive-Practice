// https://codeforces.com/contest/1539/problem/A
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
		ll k = (t/x);  // number of participant collapsing with the start time. of current participant. this will same for every participant having the future number of future participant >= k.

		ll ans = 0;
		if(k >= n) {
			ans += (n*(n-1)/2);  // 0 + 1 + 2 + 3 .. nterms
		}
		else {
			ans += (k*(n-k));   // (n-k) participants with future participant >= k. 
			// ll rem = (k-1);
			ans += (k*(k-1)/2);   // 0 + 1 + 2 + 3 .. k terms.
		}
		cout<<ans<<endl;
	}
	return 0;
}