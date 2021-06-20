#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {
	int x1, x2, y1, y2, z1, z2;
	cin>>x1>>x2>>y1>>y2>>z1>>z2;
	if(x2 >= x1 && y2 >= y1 && 	z2 <= z1) cout<<"YES"<<endl;
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