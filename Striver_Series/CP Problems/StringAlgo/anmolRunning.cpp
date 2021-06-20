
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve(vector<int> dist, string pat, int k) {
    string str;
    for(int i =1; i<dist.size(); i++) {
        int diff = dist[i] - dist[i-1];
        // cout<<diff<<" ";
        str.append(to_string(diff));
        str.push_back('$');
    }
    // cout<<pat<<" "<<str<<endl;
    int cnt = 0;
    int ind = str.find(pat);
    while(ind != str.npos) {
        cnt++;
        ind = str.find(pat, ind+2);
    }
    cout<<cnt<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> dist(n);
        for(int i=0; i<n; i++)  scanf("%d", &dist[i]);
        string pat;
        for(int i=0; i<k; i++) {
            int x;
            scanf("%d", &x);
            pat.append(to_string(x));
            pat.push_back('$');
        }

        solve(dist, pat, k);
    }
    return 0;
}