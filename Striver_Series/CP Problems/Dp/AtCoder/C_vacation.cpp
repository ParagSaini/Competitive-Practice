#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
vector<vector<int>> arr(100005, vector<int>(3)), dp(100005, vector<int>(3));
int n;

int solve(int ind, int choose) {
    if(ind == (n-1)) return arr[ind][choose];
    int maxi = INT_MIN;
    if(dp[ind][choose] != -1) return dp[ind][choose];

    for(int i=0; i<3; i++) {
        if(choose == i) continue; // cann't choose same work on two consecutive day
        maxi = max(maxi, arr[ind][choose] + solve(ind+1,i));
    }
    dp[ind][choose] = maxi;
    return dp[ind][choose];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int main() {
    init_code();

    int t;
    // cin>>t;
    t = 1;
    while(t--) {
        cin>>n;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<3; j++) {
                cin>>arr[i][j];
                dp[i][j] = -1;
            }
        }
        for(int i=0; i<3; i++) {
            int cur = solve(0, i);
            maxi = max(maxi, cur);   // starting with ith work to do
        }
        cout<<maxi<<endl;
    }
    return 0;
}