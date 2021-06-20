// This problem may ask in different ways, like
// Given a string s and an integer k return whether you can delete at most k characters such that after the deletion s is a palindrome.
// find the length of longest palindromic subsequence.

int lcs(string& str1, string& str2, int s1, int s2, vector<vector<int>>& dp) {
    
    if(s1 >= str1.length() || s2 >= str2.length()) return 0;

    if(dp[s1][s2] != -1) return dp[s1][s2];

    if(str1[s1] == str2[s2] ) {
        dp[s1][s2] = 1 + lcs(str1, str2, s1+1, s2+1, dp);
        return dp[s1][s2];
    }
    int a = lcs(str1, str2, s1, s2+1, dp);
    int b = lcs(str1, str2, s1+1, s2, dp);

    dp[s1][s2] = max(a, b);
    return max(a, b);

}
bool solve(string s, int k) {
    int a = s.length();
    string temp(s.rbegin(), s.rend());    // reversing the string
    // finding the longest common subsequence, which is nothing but a longest palidromic subsequence
    vector<vector<int>> dp(a, vector<int>(a, -1));
    int len = lcs(s, temp, 0, 0, dp);
    if(k >= (a - len)) return true;
    return false;
}

