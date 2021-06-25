#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1e9+7;

ll solve(vector<vector<int>> arr) {
    int n = 2, m = arr[0].size();
    ll cnt = 0;
    unordered_map<int, int> ind;
    for(int i=0; i<m; i++) {
        ind[arr[1][i]] = i;
    }
    for(int i =0; i<m; i++) {
        int cur = arr[0][i];
        if(ind.count(cur) && arr[0][ind[cur]] == arr[1][i]) {
            cnt++;
            cnt %= mod;
            ind.erase(arr[1][i]);
        }
    }
    cnt = (cnt*4) % mod;
    if(cnt == 0) return 2;
    else return (cnt);

}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(2);
        for(int i=0; i<2; i++) {
            for(int j = 0; j<n; j++) {
                int temp;
                cin>>temp;
                arr[i].push_back(temp);
            }
        }

        cout<<solve(arr)<<endl;
    }
    return 0;
}