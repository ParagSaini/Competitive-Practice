#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// two pointer approach
ll count_below(vector<int> arr, int cutoff) {
    int n = arr.size();
    ll cnt = 0;
    int i = 0, j = n-1;
    while(i < j) {
        ll sum = arr[i] + arr[j];
        if(sum > cutoff) j--;
        else {
            cnt += (j-i);
            i++;
        }
    }
    return cnt;
}

// binary search approach.
ll solve(vector<int> arr, int l, int r) {
    int n = arr.size();
    ll cnt = 0;
    for(int i=0; i<n-1; i++) {
        int cur = arr[i];
        int a1 = l-cur, a2 = r-cur;         // a+b >= l && a+b <=r
        int ind1 = lower_bound(arr.begin()+(i+1), arr.end(), a1) - arr.begin();
        if(ind1 == n || (arr[ind1] > a2)) continue;

        int ind2 = upper_bound(arr.begin()+(i+1), arr.end(), a2) - arr.begin();
        //cnt += (ind2 - ind1)  same thing below.
        if(ind2 == n) cnt += (n-ind1);
        else {
            cnt += (ind2 - ind1);
        }
    }
    return cnt;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(), arr.end());
        // cout<<solve(arr, l, r)<<endl;
        cout<<(count_below(arr, r) - count_below(arr, l-1))<<endl;
    }
    return 0;
}