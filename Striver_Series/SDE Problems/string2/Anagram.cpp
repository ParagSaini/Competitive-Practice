#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    // using hastable
    unordered_map<char, int> _count;
    for(int i=0; i<s.length(); i++) {
        if(_count.count(s[i])) _count[s[i]]++;
        else _count[s[i]] = 1;
    }
    for(int i=0; i<t.length(); i++) {
        if(!_count.count(t[i])) return false;
        _count[t[i]]--;
    }
    for(auto i : _count) if(i.second != 0) return false;
    return true;


    // using sorting
    if(s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i=0; i<s.length(); i++) {
        if(s[i] != t[i]) return false;
    }
    return true;


    // using frequency array
    int ar[26] = {};
    for(int i=0; i<s.length(); i++){
        ar[s[i] - 'a']++;
        ar[t[i] - 'a']--;
    }
    for(int i=0; i<26; i++) if(ar[i] != 0) return false;
    return true;
}