#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(vector<int> arr){
    int n = arr.size();
    int small = find(arr.begin(), arr.end(), 1) - arr.begin();
    int big = find(arr.begin(), arr.end(), n) - arr.begin();
    if(small > big) swap(small, big);
    return min({big+1, n-small, small+1+(n-big)});
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<solve(arr)<<endl;
    }
    return 0;
}