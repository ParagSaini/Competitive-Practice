#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// USE THE REFERENCE VARIABLE IN THE RECURSIVE CALLS IF POSSIBLE, DO NOT MAKE THE COPY OF SAME THING AGAIN AND AGAIN, IT WILL HUGELY INCREASE YOUR T.C (10 times)

// t.c O(n.V), s.c O(n.V)
vector<pair<int, int>> items(101);
vector<vector<pair<int, int>>> dp(101, vector<pair<int,int>>(1e5+10, make_pair(-1,-1)));
int n, W;

int solve(int ind, int curW, int value) {
	if(ind == n) return 0;

	if(dp[ind][value].first != -1 && curW >= dp[ind][value].first) return dp[ind][value].second;

	int a = INT_MIN;

	if(curW >= items[ind].first) a = items[ind].second + solve(ind+1,curW - items[ind].first, value + items[ind].second);

	int b = solve(ind+1, curW, value);

	dp[ind][value].first = curW;
	dp[ind][value].second = max(a, b);

	return dp[ind][value].second;
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
		cin>>n>>W;
		for(int i=0; i<n; i++) {
			int w, v;
			cin>>w>>v;
			items[i] = make_pair(w, v);
		}
		cout<<solve(0, W, 0)<<endl;
	}
	return 0;
}