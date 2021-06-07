#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr, int k, long long mid) {
    long long sum = 0;
    for(int i=0; i<arr.size(); i++) {
        sum += min((long long)arr[i], mid);
    }
    int r = sum/mid;
    return r>=k;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    long long sum = 0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        sum += arr[i];
    }
    long long ans = 0;
    long long s = 0, e = sum;
    while(s <= e) {
        long long mid = (s+e)/2;
        if(isValid(arr, k, mid)) {
            s = mid+1;
            ans = mid;
        } else e = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}