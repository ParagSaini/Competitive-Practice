#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

string a, b;
int n, m;
vector<vector<int>> dp(3005, vector<int>(3005, -1));	
vector<vector<int>> choice(3005, vector<int>(3005, -1));
// choice[i][j] == 0 means we move to +1 character in string 'a', choice[i][j] == 1 means we move to +1 character in string 'b' and choice[i][j] == 2 means we pick the cur character and move +1 in both the strings. 


int solve(int s1, int s2) {
	if(s1 >= n || s2 >= m) return 0;

	if(dp[s1][s2] != -1) return dp[s1][s2];


	if(a[s1] == b[s2]) {
		dp[s1][s2] = 1 + solve(s1+1, s2+1);
		choice[s1][s2] = 2;
		return dp[s1][s2];
	}

	int a = solve(s1+1, s2);
	int b = solve(s1, s2+1);

	if(a > b) choice[s1][s2] = 0;   // this is better choice for maxlength subsequence. 
	else choice[s1][s2] = 1;

	dp[s1][s2] = max(a, b);
	return dp[s1][s2];
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
		cin>>a>>b;
		n = a.length(), m = b.length();

		solve(0, 0);

		string result = "";
		int i=0, j = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cout<<choice[i][j]<<" ";
			}
			cout<<endl;
		}
		while(i < n && j < m) {
			if(choice[i][j] == 0) {
				i++;
			}
			else if(choice[i][j] == 1) {
				j++;
			}
			else if(choice[i][j] == 2) {
				result.push_back(a[i]);
				i++;
				j++;
			}
		}
		cout<<result<<endl;
	}

	return 0;
}