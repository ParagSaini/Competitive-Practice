#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

vector<int> LpsArray(string str) {
    int n = str.length();
    vector<int> lps(n);
    lps[0] = 0;
    int i=0, j = 1;
    while(j < n) {
        if(str[i] == str[j]) {
            lps[j] = i+1;
            j++;
            i++;
        }
        else if(i == 0) {
            lps[j] = 0;
            j++;
        }
        else {
            i = lps[i-1];
        }
    }
    return lps;
}
int solve(string str) {
    int n = str.length();
    if(n == 1) return 1;

    vector<int> lps = LpsArray(str);
    int len = n - lps[n-1];
    if(n%len != 0) return n;
    return len;
    // string smallStr = str.substr(0, len), temp = smallStr;
    // int diff = n/len;
    // while(--diff) {
    //     smallStr.append(temp);
    // }
    // if(smallStr == str) return (len);
    // return n;
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