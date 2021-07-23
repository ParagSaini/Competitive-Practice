#include<bits/stdc++.h>
using namespace std;
// Kmp lpsay contanins the len of the prefix which is also the suffix at each index.
// overall t.c O(n+m) && s.c O(m) for kmp lps(longest prefix suffix)
vector<int> LpsArray(string& pat) {
    int len = pat.length(); 
    vector<int> lps(len);
    lps[0] = 0;
    int i=0, j=1;
    while(j < len) {
        // there is a match
        if(pat[i] == pat[j]) {
            lps[j] = i+1;
            i++;
            j++;
        }else if(i == 0){
            lps[j] = 0;
            j++;
        }else {
            i = lps[i-1]; 
        }
    }
    // for(auto it : lps) cout<<it<<" ";
    return lps;
}
int strStr(string str, string pat) {
    int l1 = str.length();
    int l2 = pat.length();
    if(l2 == 0) return 0;
    vector<int> lps = LpsArray(pat);
    int i = 0, j = 0;
    
    while(i < l1) {
        if(str[i] == pat[j]) {
            if(j == l2-1) return (i - l2 + 1);      // starting index of substring
            i++; j++;
        }else if(j == 0) {
            i++;
        } else {
            j = lps[j-1];
        }
    }
    return -1;
}

int main() {
    string str = "my name is parag saini and i am name is parag saini";
    string pat = "aacecaaaa";
    cout<<strStr(str, pat);
    return 0;
}