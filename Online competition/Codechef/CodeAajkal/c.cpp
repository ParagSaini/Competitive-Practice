#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);

        long long sum = 0, maxSum = LLONG_MIN;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        if(maxSum > 0) cout<<"Can study - "<<maxSum<<endl;
        else cout<<"Cannot study - "<<maxSum<<endl;
    }
    return 0;
}