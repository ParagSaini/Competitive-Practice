#include<bits/stdc++.h>
using namespace std;

// t.c O(n2) && s.c O(1)
double findMaximumAverageWithRange(const vector<long long>& arr, int k) {
    long long sum = 0;
    long long maxSum = LLONG_MIN;
    for(int i=0; i<k; i++) sum += arr[i];
    maxSum = max(maxSum, sum);

    for(int i=k; i<arr.size(); i++) {
        sum += arr[i];
        sum -= arr[i-k];
        maxSum = max(maxSum, sum);
    }

    return maxSum/(double)k;
}
double findMaximumAverage(const vector<long long>& arr, int a, int b) {
    int n = arr.size();
    if( (a<1) || (b>n)) return 0;   // invalid ranges.
    double maxAverage = -1.0;
    for(int i=a; i<=b; i++) {
        double curMax = findMaximumAverageWithRange(arr, i);
        maxAverage = max(maxAverage, curMax);
    }
    return maxAverage;
}
int main() {
    int t;          // 1<=t<=5
    cin>>t;
    while(t--) {
        int n, b, a;     // 1<=n<=1000, b, a no constraints.
        cin>>n>>b>>a;
        vector<long long> arr(n);  // 0 to 10^10, Ai
        int i=0;
        while(n--) {
            cin>>arr[i++];
        }
        cout<<setprecision(6)<<fixed;
        cout<<findMaximumAverage(arr, a, b)<<endl;
    }
    return 0;
}