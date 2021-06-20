#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

int countBelow(int n, vector<vector<int>>& m, vector<int>& ans) {
    if(m[n].empty()) return 0;
    int cnt = 0;
    for(auto it : m[n]) {
        cnt += countBelow(it, m, ans);
    }
    ans[n] = cnt + m[n].size();
    return ans[n];
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
        int n;
        cin>>n;
        vector<vector<int>> children(n+1);  // ignores 0, each index represent the employee, and its element represnt its children
        for(int i=2; i<=n; i++) {
            int x; cin>>x;
            children[x].push_back(i);
        }
        vector<int> ans(n+1, 0);  // ignore 0th, 1 to n
        countBelow(1, children, ans);
        for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    }
    return 0;
}