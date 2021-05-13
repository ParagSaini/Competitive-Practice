#include<bits/stdc++.h>
using namespace std;

// using the unordered<string, int> gives the Tle so, make sure of that too.
// Time complexity = O(n*m) , n->length of text1, m->length of text2

int LcsHelper(string& text1, string& text2, int start1, int start2,int** dp) {
    if(start1 >= text1.length() || start2 >= text2.length()) return 0;

    if(dp[start1][start2] != -1) return dp[start1][start2];
    
    if(text1[start1] == text2[start2]) {
        dp[start1][start2] = 1 + LcsHelper(text1, text2, start1+1, start2+1, dp);
        return dp[start1][start2];
    }
    int a = LcsHelper(text1, text2, start1+1, start2, dp);
    int b = LcsHelper(text1, text2, start1, start2+1, dp);
    dp[start1][start2] = max(a, b);
    return dp[start1][start2];
}
int longestCommonSubsequence(string text1, string text2) {
    int** dp = new int*[text1.length()];
    for(int i=0; i<text1.length(); i++) dp[i] = new int[text2.length()];
    // initialising the memoiazation table
    for(int i=0; i<text1.length(); i++) {
        for(int j=0; j<text2.length(); j++) dp[i][j] = -1;
    }
    return LcsHelper(text1, text2, 0, 0, dp);
}