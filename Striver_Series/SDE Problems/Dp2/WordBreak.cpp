#include<bits/stdc++.h>
using namespace std;

// bottom up O(n^2);
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    int dp[n+1];
    for(int i=0; i<=n; i++) dp[i] = 0;
    dp[n] = 1;
    unordered_set<string> dict;
    for(auto word : wordDict) dict.insert(word);
    
    for(int i=n-1; i>=0; i--) {
        string word;
        for(int j=i; j<n; j++) {
            word.push_back(s[j]);
            if(dict.count(word)) {
                if(dp[j+1]) dp[i] = 1;
            }
        }
    }
    return dp[0];
}

// Top down recursive approach, t.c O(n^2)

bool wordBreakHelper(string& s, int start, unordered_set<string>& DictSet, vector<int>& dp) {
    if(dp[start] != -1) {
        return dp[start];
    }
    for(int i = start; i < s.length(); i++) {
        string cur = s.substr(start,i - start +1);
        
        if(DictSet.count(cur)) {
            if(i == s.length() -1 ) {
                dp[start] = 1;
                return dp[start];
            }
            if(wordBreakHelper(s, i+1, DictSet, dp)) {
                dp[start] = 1;
                return dp[start];
            }
        }            
    }
    dp[start] = 0;
    return dp[start];
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> DictSet;
    vector<int> dp(s.length());
    for(int i = 0; i< s.length(); i++) dp[i] = -1;
    for(auto i : wordDict) {
        DictSet.insert(i);
    }
    return wordBreakHelper(s, 0, DictSet, dp);
    
}