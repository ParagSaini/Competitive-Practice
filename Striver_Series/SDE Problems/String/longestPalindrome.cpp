#include<bits/stdc++.h>
using namespace std;


// *********************Optimal Solution ***************************
//T.c O(n^2)
 int findLength(string s, int left, int right){
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return (right - left - 1);
}
string longestPalindrome(string s) {
    if(s.empty() || s.length() < 2) return s;
    int start = 0, end = 0;
    
    for(int i=0; i<s.length(); i++) {
        int oddPalindrome = findLength(s, i, i);
        int evenPalindrome = findLength(s, i, i+1);
        int len = max(oddPalindrome, evenPalindrome);
        if(len > (end - start + 1)) {
            // below line are very clever handle both the even and odd palindromes length, run it on both the test cases "cbbd" and "babad", it will handle both cases
            start = i - ( (len-1)/2);
            end = i + (len/2);
        }
    }
    return s.substr(start, end - start + 1);
}


// *******************WITH DP ***************************
// T.C O(n^2), checking every substring only once, make recursive tree diagram to understand the complexity.

bool Helper(string& str, int s, int e, pair<int, int>& longestString, unordered_map<string, bool>& dp) {
    string dpString = to_string(s) + "|" + to_string(e);
    
    if(s == e || (s+1 == e && str[s] == str[e])) {
        int length = e - s + 1;
        int longestLen = longestString.second - longestString.first + 1;
        if(length > longestLen) longestString = {s, e};
        dp[dpString] = true;
        return dp[dpString];
    }
        if(s+1 == e && str[s] != str[e]) {
        dp[dpString] = false;
        return dp[dpString];
    }
    if(dp.count(dpString)) return dp[dpString];
    
    Helper(str, s+1, e,longestString, dp);
    Helper(str, s, e-1, longestString, dp);
    if(str[s] == str[e]){
        bool restString = Helper(str, s+1, e-1,longestString, dp);
        if(restString) {
            int length = e - s + 1;
            int longestLen = longestString.second - longestString.first + 1;
            if(length > longestLen) longestString = {s, e};  
            dp[dpString] = true;
            return dp[dpString];
        }
    }
    dp[dpString] = false;
    return dp[dpString];
    
}
string longestPalindrome(string s) {
    string result;
    if(s.empty()) return result;
    int start = 0;
    int end = s.length()-1;
    pair<int, int> longeststring = {0,0};
    unordered_map<string, bool> dp;
        
    Helper(s, start, end,longeststring, dp);
    
    result = s.substr(longeststring.first, longeststring.second - longeststring.first + 1);
    return result;
}

// ****************WITH RECURSION ***********************
// exponential time complexity.
void Helper(string& str, int s, int e, pair<int, int> startend, pair<int, int>& longestString) {
    if(s == e || (s+1 == e && str[s] == str[e])) {
        int length = startend.second - startend.first + 1;
        int longestLen = longestString.second - longestString.first + 1;
        if(length > longestLen) longestString = {startend.first, startend.second};
        return;
    }
        if(s+1 == e && str[s] != str[e]) {
        return;
    }
    Helper(str, s+1, e, {s+1, e}, longestString);
    Helper(str, s, e-1, {s, e-1}, longestString);
    
    if(str[s] == str[e]) Helper(str, s+1, e-1, startend, longestString);
}
string longestPalindrome(string s) {
    string result;
    if(s.empty()) return result;
    int start = 0;
    int end = s.length()-1;
    pair<int, int> longeststring = {0,0};
    pair<int, int> startend = {start, end};
    Helper(s, start, end, startend, longeststring);
    
    result = s.substr(longeststring.first, longeststring.second - longeststring.first + 1);
    return result;
}



// brute force approach, T.c O(n^3);

bool checkPalindrome(string& str) {
    int s = 0;
    int e = str.length()-1;
    while(s < e) {
        if(str[s++] != str[e--]) return false;
    }
    return true;
}
string longestPalindrome(string s) {
    if(s.length() <= 1) return s;
    string result;
    
    for(int i=0; i<s.length(); i++) {
        for(int j=0; j<s.length(); j++) {
            string cur = s.substr(i, j - i +1);
            if(checkPalindrome(cur)) {
                if(cur.length() > result.length()) result = cur;
            }
        }
    }
    return result;
}

