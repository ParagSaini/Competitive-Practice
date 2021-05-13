#include<bits/stdc++.h>
using namespace std;

// overall time compelxity = O(n2) && s.c O(n2)
void checkPalindrome(string& str, int s, vector<vector<bool>>& result) {
	// odd length palindrome
	int i = s, j = s;
	while(i >= 0 && j < str.length()) {
		if(str[i] != str[j]) break;
		result[i][j] = 1;
		i--; j++;
	}
	// even length palindrome
	i = s, j = s+1;
	while(i >=0 && j < str.length()) {
		if(str[i] != str[j]) break;
		result[i][j] = 1;
		i--; j++;
	}
}
// making the palindrome table for fast caching
vector<vector<bool>> IsPalindrome(string str, int s, int e) {
    vector<vector<bool>> result(e+1);
	for(int i=0; i<=e; i++) {
		for(int j=0; j<=e; j++) {
			if(i == j) result[i].push_back(1);
			else result[i].push_back(0);
		}
	}

	for(int i=s; i<e; i++) {		
		checkPalindrome(str, i, result);
	}
	return result;

}
// main Helper function
int MinSpaces(string str, int s, int e, int* dp, vector<vector<bool>>& palindrome) {
    if(s > e) return -1;
    if(s == e) return 0;
    if(dp[s] != -1) return dp[s];
    int mini = e-s;
    for(int i=s; i<=e; i++) {
        if(palindrome[s][i]){
            int cand = 1 + MinSpaces(str, i+1, e, dp, palindrome);
            mini = min(mini, cand);
        }
    }
    dp[s] = mini;
    return dp[s];
}
int palindromicPartition(string str)
{
    int* dp = new int[str.length()];
    vector<vector<bool>> palindrome = IsPalindrome(str, 0, str.length()-1);
    for(int i=0; i<str.length(); i++) dp[i] = -1;
    return MinSpaces(str, 0, str.length()-1, dp, palindrome);
}


// t.c O(n3) && s.c O(n) 
/* we can optimised it further to O(n2) by making isPalindrome array before hand, the implementation is above*/
bool isPalindrome(string str, int s, int e) {
    while(s < e) {
        if(str[s] != str[e]) return false;
        s++; e--;
    }
    return true;
}
int MinSpaces(string str, int s, int e, int* dp) {
    if(s > e) return -1;
    if(s == e) return 0;
    if(dp[s] != -1) return dp[s];
    int mini = e-s;
    for(int i=s; i<=e; i++) {
        if(isPalindrome(str, s, i)) {
            int cand = 1 + MinSpaces(str, i+1, e, dp);
            mini = min(mini, cand);
        }
    }
    dp[s] = mini;
    return dp[s];
}
int palindromicPartition(string str)
{
    int* dp = new int[str.length()];
    for(int i=0; i<str.length(); i++) dp[i] = -1;
    return MinSpaces(str, 0, str.length()-1, dp);
}