
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

int KmpArray(string pat) {
    int len = pat.length(); 
    vector<int> arr(len);
    arr[0] = 0;
    int i=0, j=1;
    while(j < len) {
        // there is a match
        if(pat[i] == pat[j]) {
            arr[j] = i+1;
            i++;
            j++;
        }else if(i == 0){
            arr[j] = 0;
            j++;
        }else {
            i = arr[i-1]; 
        }
    }
    return arr[len-1];
}

string solve(string str) {
    int n = str.length();
    int maxPreSuffixLen = KmpArray(str);
    if(maxPreSuffixLen == 0) return "Just a legend";
    // if(2*maxPreSuffixLen > n) {
    //     maxPreSuffixLen = (n - maxPreSuffixLen);
    // }
    string prefix(str.begin(), str.begin() + maxPreSuffixLen);
    cout<<prefix<<endl;
    int ind = str.find(prefix, 1);
    if(ind != (n-maxPreSuffixLen)) return prefix;
    return "Just a legend";

}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--) {
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
    }
    return 0;
}