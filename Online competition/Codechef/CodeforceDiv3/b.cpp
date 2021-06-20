#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// bool isPossible(vector<int> arr, int k) {
//     int n = arr.size();
//     int x = n-1, candies = 0, sum = 0;
//     for(int i=0; i<n; i++) {
//         sum += arr[i];
//     }
//     if(sum % n != 0) return false;
//     sum /= n;
//     while(k) {
//         candies += arr[x];
//         arr[x] = 0;
//         x--;
//         k--;
//     }
//     int candReq = 0;
//     for(int i=0; i<n; i++) {
//         if(arr[i] > sum) return false;
//         candReq += (sum - arr[i]);
//     }
//     if(candReq == candies) return true;
//     return false;
// }
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll sum = 0, cnt = 0;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        // int minK = 0, maxK = n;
        // int ans = -1;
        // while(minK <= maxK) {
        //     int mid = (minK + maxK)/2;
        //     if(isPossible(arr, mid)) {
        //         ans = mid;
        //         maxK = mid-1;
        //     } else {
        //         minK = mid+1;
        //     }
        // }
        // cout<<ans<<endl;
        if((sum % n) != 0) printf("-1\n");
        else {
            sum /= n;
            for(int i=0; i<n; i++) {
                if(arr[i] > sum) cnt++; 
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}