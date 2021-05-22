#include<bits/stdc++.h>
using namespace std;

// Very good problem on the Binary Search.
int main() {
	int n,m, ans = 0;
	cin>>n>>m;
	vector<int> ht(n);
	for(int i=0; i<n; i++) {
		cin>>ht[i];
	}

	sort(ht.begin(), ht.end());

	vector<long long> suffixSum(n);   // ith element contains the sum from [i,n-1] index.
	suffixSum[n-1] = (long long)ht[n-1];
	for(int i=n-2; i>=0; i--) {
		suffixSum[i] = suffixSum[i+1] + (long long)ht[i];
	}

	// the ht of the sawblade lies between 0 to max-1;
	int s = 0, e = ht[n-1] - 1;
	while(s <= e) {
		int curBladeHt = (s+e)/2;

		int ind = lower_bound(ht.begin(), ht.end(), curBladeHt) - ht.begin();

		if(ind == n) {
			e = curBladeHt-1;   // lower down the blade ht.
		}else {
			int numberOfTreeToCut = n-ind;

			long long htCut = suffixSum[ind] -  ( (long long)curBladeHt * numberOfTreeToCut);

			if(htCut < m) { // reduce the ht of blade, so that it cuts more.
				e = curBladeHt-1;
			} else {
				ans = curBladeHt;  // this is also important.
				s = curBladeHt+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}