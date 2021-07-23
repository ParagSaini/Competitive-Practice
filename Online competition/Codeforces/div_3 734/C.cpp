#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n;
	cin>>n;
	vector<string> arr(n);
	vector<vector<int>> occ(n, vector<int>(5, 0));
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		for(auto ch : arr[i]) {
			occ[i][ch - 'a']++;
		}
	}
	int final_ans = 0;
	for(int k=0; k<5; k++) {
		vector<int> val(n);
		for(int i=0; i<n; i++) {
			int sum = 0;
			for(int j =0; j<5; j++) {
				if(k == j) {
					sum += occ[i][j];
				}
				else sum -= occ[i][j];
			}
			val[i] = sum;
		}
		sort(val.begin(), val.end(), greater<int>());
		int ans = 0, sum = 0;
		for(int i=0; i<val.size(); i++) {
			sum += val[i];
			if(sum > 0) ans++;
			else break;
		}
		final_ans = max(final_ans, ans);
	}
	cout<<final_ans<<endl;

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