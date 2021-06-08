#include<bits/stdc++.h>
using namespace std;

// using prefix and suffix sum.
string solve(vector<int> arr) {
    int n = arr.size();
    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum <= 0) return "NO";
    }
    sum = 0;
    for(int i=n-1; i>=0; i--) {
        sum += arr[i];
        if(sum <= 0) return "NO";
    }
    return "YES";
}

// using the kadane algo
void solve1(vector<int> arr) {
    int n = arr.size();
    long long yasserSum = arr[0], adelMaxSum1 = LLONG_MIN, adelMaxSum2 = LLONG_MIN, adelMaxSum, sum = 0;

    // we can't take the segment from [0,n-1], that why we have to find maxSumSubarray from [0,n-2] and [1,n-1];
    
    for(int i=1; i<n; i++) {
        yasserSum += arr[i];
        // kadane algo
        sum += arr[i];
        adelMaxSum1 = max(adelMaxSum1, sum);
        if(sum < 0) sum = 0;
    }
    sum = 0;
    for(int i=0; i<(n-1); i++) {
        sum += arr[i];
        adelMaxSum2 = max(adelMaxSum2, sum);
        if(sum < 0) sum = 0;
    }
    adelMaxSum = max(adelMaxSum1, adelMaxSum2);

    if(yasserSum > adelMaxSum) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        cout<<solve(arr)<<endl;
    }
    return 0;
}