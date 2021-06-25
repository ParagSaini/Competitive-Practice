#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int lcs(string& a, string& b, int s1, int s2, vector<vector<int>>& dp, int len) {

    if(s1 >= a.length() || s2 >= b.length()) {
    	return 0;
    }

    if(dp[s1][s2] != -1) {
    	return dp[s1][s2];
    }

    int l = 0;
    if(a[s1] == b[s2]) {
        l = lcs(a, b, s1+1, s2+1, dp, len+1) % mod;
        if(len+1 == b.length()) {	
 			l++;
    	}
    }
    int y = lcs(a, b, s1+1, s2, dp, len) % mod;

    dp[s1][s2] = (l + y) % mod;
    return dp[s1][s2];

}
void solve(string s, string t) {
    int n1 = s.length(), n2 = t.length();
    int cnt =0;
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout<<lcs(s, t, 0, 0, dp, 0);
}