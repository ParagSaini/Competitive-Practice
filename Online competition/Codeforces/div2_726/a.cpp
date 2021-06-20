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
		int n;
		cin>>n;
		vector<int> arr(n);
		ll sum = 0;
		for(int i =0; i<n ;i++) {cin>>arr[i];
			sum += arr[i];
		}
		if(sum == 0) cout<<1<<endl;
		else if(sum == n) cout<<0<<endl;
		else if(sum > n) cout<<(sum - n)<<endl;
		else if(sum < n || sum < 0) cout<<1<<endl;
		
	}
	return 0;
}		