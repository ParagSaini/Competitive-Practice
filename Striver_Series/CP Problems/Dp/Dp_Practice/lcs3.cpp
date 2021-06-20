int helper(string& a, string& b, string& c, int s1, int s2, int s3, vector<vector<vector<int>>>& dp) {
    if(s1 >= a.length() || s2 >= b.length() || s3 >= c.length()) return 0;

    if(dp[s1][s2][s3] != -1) return dp[s1][s2][s3];

    if(a[s1] == b[s2] && b[s2] == c[s3]) {
        dp[s1][s2][s3] = (1 + helper(a, b, c, s1+1, s2+1, s3+1, dp));
        return dp[s1][s2][s3];
    }
    int x = helper(a, b, c, s1, s2+1, s3, dp);
    int y = helper(a, b, c, s1, s2, s3+1, dp);
    int z = helper(a, b, c, s1+1, s2, s3, dp);

    dp[s1][s2][s3] = max({x, y, z});
    return dp[s1][s2][s3];
}
int solve(string a, string b, string c) {
    vector<vector<vector<int>>> dp(a.length(), vector<vector<int>>(b.length(), vector<int>(c.length(), -1)));
    return helper(a, b, c, 0, 0, 0, dp);
}