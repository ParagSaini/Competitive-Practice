#include<bits/stdc++.h>
using namespace std;


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