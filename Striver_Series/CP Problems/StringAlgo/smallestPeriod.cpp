#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

bool possible(string str, int k) {
    int n = str.length();
    // string pat;
    for(int i=k; i<n; i++) {
        if(str[i] != str[i%k]) return false;
    }
    return true;
    // int cnt = 0;
    // for(int i =0; i<k; i++) {
    //     pat.push_back(str[i]);
    // }
    // int ind = str.find(pat);
    // while(ind != str.npos) {
    //     cnt++;
    //     ind = str.find(pat, ind+k);
    // }
    // if(cnt == (n/k)) return true;
    // return false;
}
int solve(string str) {
    int n = str.length();
    for(int i=1; i<=n; i++) {
        if((n % i) != 0) continue;
        if(possible(str, i)) return i;
    }  
    return n;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
int main() {
    vector<int> arr = {2,2,2};
    sort(arr.begin(), arr.end());
    for(auto it : arr) cout<<it<<" ";
}