#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

bool powerOfTwo(ll n) {
	return (n & (n-1LL)) ? false : true;
}
void solve() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	if(powerOfTwo(b)) printf("Yes\n");
	else printf("No\n");
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