#include<bits/stdc++.h>
using namespace std;

// time complexity = O(n+m), s.c O(n+m)
vector<int> Zalgo(string str) {
    int n = str.length();
    vector<int> zVal(n);
    zVal[0] = 0;
    int i = 0; 
    int j = 1;
    while(j < n) {
        int boxStart = j;
        int boxEnd = j;
        while(boxEnd < n && str[i] == str[boxEnd]) {
            i++;
            boxEnd++;
        }
        boxEnd--;
        int boxLen = boxEnd - boxStart + 1;
        zVal[boxStart] = boxLen;
        boxStart++;
        if(boxLen > 1) {
            while(boxStart <= boxEnd && (boxStart+zVal[boxStart-j]) < (boxEnd)) {
                zVal[boxStart] = zVal[boxStart - j];
                boxStart++;
            }
        }
        i = 0;
        j = boxStart;
    }
    return zVal;
}

vector<int> strStr(string str, string pat) {
    vector<int> result;
    string comb = pat;
    comb.push_back('$');
    comb.append(str);
    vector<int> zVal = Zalgo(comb);
    for(int i=0; i<zVal.size(); i++) {
        if(zVal[i] == pat.length()) {
            result.push_back(i-pat.length()-1);
        }
    }
    return result;
}
int main() {
    string str = "my name is parag saini and i am name is parag saini";
    for(int i=0; i<str.length(); i++) {
        cout<<str[i]<<" "<<i<<endl;
    }
    string pat = "ara";
    vector<int> ans = strStr(str, pat);
    for(auto it : ans) cout<<it<<" ";
    return 0;
}