#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {
		cin>>b[i];
	}
	vector<pair<int, int>> ans;
	for(int i=0; i<n; i++) {
		if(a[i] == b[i]) continue;
		int diff = abs(a[i] - b[i]);

		if(a[i] > b[i]) {
			for(int j=i+1; j<n; j++) {
				if(a[j] >= b[j]) continue;

				while((a[j] < b[j]) && diff > 0) {
					ans.push_back(make_pair(i+1, j+1));
					diff--;
					a[j]++;
				}
				if(diff == 0) break;
			}
			if(diff != 0) {
				cout<<"-1\n";
				return;
			}
		}
		else {
			for(int j=i+1; j<n; j++) {
				while(a[j] > 0 && diff != 0) {
					ans.push_back(make_pair(j+1, i+1));
					diff--;
					a[j]--;
				}
				if(diff == 0) break;
			}
			if(diff != 0) {
				cout<<"-1\n";
				return;
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto it : ans) cout<<it.first<<" "<<it.second<<"\n";
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