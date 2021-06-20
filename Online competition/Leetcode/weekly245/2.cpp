#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

bool makeEqual(vector<string>& words) {
    int n = words.size();
    if(n == 1) return true;
    unordered_map<char, int> charfreq;
    int character = 0;
    for(int i=0; i<n; i++) {
        string word = words[i];
        for(int j=0; j<word.length(); j++) {
            character++;
            charfreq[word[i]]++;
        }
    }      
    if(character % n != 0) return false;
    for(auto it : charfreq) {
        int cur = it.second;
        if(cur % n != 0) return false;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        solve();
    }
    return 0;
}