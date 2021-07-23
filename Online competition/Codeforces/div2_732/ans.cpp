#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
	int n;
	cin>>n;
	unordered_map<int, pair<int, int>> m1, m2;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		if(m1.find(arr[i]) != m1.end()) {
			if(i%2 == 0) m1[arr[i]].first++;
			else m1[arr[i]].second++;
		}
		else {
			int a = 0, b = 0;
			if(i%2 == 0) a = 1;
			else b = 1;
			m1.insert({arr[i], make_pair(a, b)});
		}
	}
	vector<int> temp(arr.begin(), arr.end());
	sort(temp.begin(), temp.end());

	for(int i=0; i<n; i++) {
		if(m2.find(temp[i]) != m2.end()) {
			if(i%2 == 0) m2[temp[i]].first++;
			else m2[temp[i]].second++;
		}
		else {
			int a = 0, b = 0;
			if(i%2 == 0) a = 1;
			else b = 1;
			m2.insert({temp[i], make_pair(a, b)});
		}
	}

	for(auto it : m1) {
		int k = it.first;
		int evenCnt1 = it.second.first, oddCnt1 = it.second.second;
		int evenCnt2 = m2[k].first, oddCnt2 = m2[k].second;

		if(evenCnt1 != evenCnt2 || oddCnt2 != oddCnt1) {
			cout<<"No\n";
			return;
		}

	}
	cout<<"Yes\n";
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