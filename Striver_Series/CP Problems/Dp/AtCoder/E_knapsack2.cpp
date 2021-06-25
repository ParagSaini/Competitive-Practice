#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// USE THE REFERENCE VARIABLE IN THE RECURSIVE CALLS IF POSSIBLE, DO NOT MAKE THE COPY OF SAME THING AGAIN AND AGAIN, IT WILL HUGELY INCREASE YOUR T.C (10 times)

// t.c O(n.W), s.c O(n.W)
vector<pair<int, int>> items(101);
vector<vector<ll>> dp(101, vector<ll>(1e5+10, -1));
int n, W;

ll solve(int ind, int curVal) {
	if(ind == n) {
		return curVal == 0 ? 0 : LLONG_MAX;
	}
	if(dp[ind][curVal] != -1) return dp[ind][curVal];

	ll a = LLONG_MAX, b = LLONG_MAX;

	if(items[ind].second <= curVal) {
		a = solve(ind+1, curVal - items[ind].second);
		if(a != LLONG_MAX) a += items[ind].first;
	}
	
	b = solve(ind+1, curVal);

	dp[ind][curVal] = min(a, b);
	return dp[ind][curVal];
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
		int maxVal = 0;
		for(int i=0; i<n; i++) {
			// int w, v;
			scanf("%d %d", &items[i].first, &items[i].second);
			maxVal += items[i].second;
			
		}
		for(int i=maxVal; i>=1; i--) {
			ll ans = solve(0, i);
			if(ans != -1 && ans <= W) {
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}