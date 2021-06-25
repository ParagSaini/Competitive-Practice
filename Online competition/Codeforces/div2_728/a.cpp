#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n;
	cin>>n;
	vector<int> arr;
	int x = n/2;
	int cat = 2;
	while(x) {
		arr.push_back(cat);
		arr.push_back(cat-1);
		cat += 2;
		x--;
	}
	if(n%2 != 0) {
		arr.pop_back();
		arr.push_back(cat-1);
		cat -= 3;
		arr.push_back(cat);
	}
	for(auto it : arr) cout<<it<<" ";
	cout<<endl;
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