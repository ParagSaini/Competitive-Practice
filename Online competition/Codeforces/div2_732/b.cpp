#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n, m;
	cin>>n>>m;
	vector<string> arr(n);
	vector<string> reorder(n-1);
	string str;

	for(int i =0; i<n; i++) cin>>arr[i];
	for(int i =0; i<(n-1); i++) cin>>reorder[i];

	for(int i=0; i<m; i++) {
		vector<int> ans(26, 0);
		for(int j=0; j<n; j++) ans[arr[j][i] - 'a']++;

		for(int j=0; j<(n-1); j++) ans[reorder[j][i] - 'a']--;
		for(int j=0; j<26; j++) {
			if(ans[j] != 0) {
				char ch = 'a' + j;
				str.push_back(ch);
			}
		}
	}
	cout<<str<<"\n";

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