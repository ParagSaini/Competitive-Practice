#include<bits/stdc++.h>
using namespace std;

string findPrefix(string s1, string s2) {
    string result = "";
    int i = 0, j = 0;
    while(i < s1.length() && j < s2.length() && s1[i] == s2[j] ) {
        result.push_back(s1[i]);
        i++;
        j++;
    }
    return result;
}
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    string result = strs[0];
    for(int i=1; i<strs.size(); i++) {
        result = findPrefix(strs[i], result);
        if(result.empty()) return "";
    }
    return result;
}