#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
vector<int> ht(100005), dp(100005);
int n;

int solve(int s) {
    if((s+1) == n) return 0;
    if(dp[s] != -1) return dp[s];

    int a = INT_MAX, b = INT_MAX;
    a = abs(ht[s] - ht[s+1]) + solve(s+1);
    
    if((s+2) < n) b = abs(ht[s] - ht[s+2]) + solve(s+2);
    
    dp[s] = min(a, b);
    return dp[s];
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
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>ht[i];
            dp[i] = -1;
        }
        cout<<solve(0)<<endl;
    }
    return 0;
}