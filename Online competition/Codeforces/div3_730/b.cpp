#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    int i=0, j = n-1;
    ll ans = 0;
    vector<int> prefixSum(n);
    

    while(i < j) {
        int sum = arr[i] + arr[j];
        if(sum % 2 == 0) {
            arr[i] = sum/2;
            arr[j] = sum/2;
        } 
        else {
            arr[i] = sum/2 + 1;
            arr[j] = sum/2;
        }
        i++;
        j--;
    }
    prefixSum[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        prefixSum[i] = prefixSum[i+1] + arr[i];
    }

    for(int i=0; i<n; i++) {
        int m = n - i - 1;
        ans += abs((ll)m*arr[i] - ((ll)prefixSum[i] - (ll)arr[i]));
    }
    cout<<ans<<"\n";
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}