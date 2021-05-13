#include<bits/stdc++.h>
using namespace std;

int minThree(int a, int b, int c) {
    return min(min(a, b), c);
}
int editDistanceHelper(string& s, string& t, int s1, int s2, int** dp) {
    
    if(s1 >= s.length()) {
        //insert remaining elements
        return (t.length() - s2);
    } 
    if(s2 >= t.length()) {
        // remove remaining elements.
        return (s.length() - s1);
    }
    
    if(dp[s1][s2] != -1) return dp[s1][s2];
    
    int len1 = s.length() - s1;
    int len2 = t.length() - s2;
    int removeOp = INT_MAX, replaceOp = INT_MAX, insertOp = INT_MAX;
    
    if(s[s1] == t[s2]) {
        dp[s1][s2] =  editDistanceHelper(s, t, s1+1, s2+1, dp);
        return dp[s1][s2];
    }
    replaceOp = 1 + editDistanceHelper(s, t, s1+1, s2+1, dp); // replace
    removeOp = 1 + editDistanceHelper(s, t, s1+1, s2, dp); // remove
    insertOp = 1 + editDistanceHelper(s, t, s1, s2+1, dp);    // insert

    dp[s1][s2] =  minThree(replaceOp, removeOp, insertOp);
    return dp[s1][s2];
}
int editDistance(string s, string t)
{
    int** dp = new int*[s.length()];
    for(int i=0; i<s.length(); i++) {
        dp[i] = new int[t.length()];
    }
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<t.length(); j++) {
            dp[i][j] = -1;
        }
    }
    return editDistanceHelper(s, t, 0, 0, dp);
}