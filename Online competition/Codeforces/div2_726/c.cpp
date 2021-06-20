#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve(vector<int> ht) {
	sort(ht.begin(), ht.end());
	int n = ht.size();
	int k1 = 0, k2 = 1, diff = (ht[k2] - ht[k1]);

	for(int i=2; i<n; i++) {
		if(ht[i] - ht[i-1] < (diff)) {
			k1 = i-1;
			k2 = i;
			diff = ht[i] - ht[i-1];
		}
	}
	cout<<ht[k1]<<" ";
	for(int i=k2+1; i<n; i++) {
		cout<<ht[i]<<" ";
	}
	for(int i=0; i<k1; i++) {
		cout<<ht[i]<<" ";
	}
	cout<<ht[k2]<<endl;
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
		int n;
		cin>>n;
		vector<int> ht(n);
		for(int i=0; i<n; i++) cin>>ht[i];

		solve(ht);
	}
	return 0;
}