#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {
	int n , q;
	cin>>n>>q;
	vector<int> arr(n);
	bool oddNums = false;
	unordered_set<int> nums;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		nums.insert(arr[i]);
	}
	if(n % 2 != 0) oddNums = true;
	sort(arr.begin(), arr.end());

	for(int i=0; i<q; i++) {
		int a;
		cin>>a;
		if(nums.count(a)) cout<<0<<endl;
		else {
			int ind = upper_bound(arr.begin(), arr.end(), a) - arr.begin();
			int cntGreater = (n-ind);
			if(cntGreater %2 == 0) {
				if(oddNums) cout<<"NEGATIVE"<<endl;
				else cout<<"POSITIVE"<<endl;
			} else {
				if(oddNums) cout<<"POSITIVE"<<endl;
				else cout<<"NEGATIVE"<<endl;
			}

		}
	}

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