#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

int solve(vector<vector<int>>& edges, int root) {
    if()
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
        vector<vector<int>> edges(n+1);
        for(int i=1; i<=(n-1); i++) {
            int a, b;
            cin>>a>>b;
            edges[a].push_back(b);
        }
        cout<<solve(edges, 1)<<endl;     // starting from the '1'
    }
    return 0;
}