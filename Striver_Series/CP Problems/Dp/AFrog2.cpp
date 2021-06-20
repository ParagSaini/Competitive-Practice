#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
vector<int> ht(100005), dp(100005);
int n, k;

int solve(int ind) {
    if(ind == (n-1)) return 0;
    if(dp[ind] != -1) return dp[ind];

    int mini = INT_MAX;
    for(int i=1; i<=k; i++) {
        if((ind+i) < n) mini = min(mini, abs(ht[ind] - ht[ind+i]) + solve(ind+i));
    }
    dp[ind] = mini;
    return dp[ind];
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
        cin>>n>>k;
        for(int i=0; i<n; i++) {
            cin>>ht[i];
            dp[i] = -1;
        }

        cout<<solve(0)<<endl;
    }
    return 0;
}