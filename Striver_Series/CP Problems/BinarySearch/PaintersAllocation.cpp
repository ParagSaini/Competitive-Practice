#include<bits/stdc++.h>
using namespace std;

// This problem is same as the page allocation problem.

bool isPossibleToAllocatePainter(vector<int>& C, int A, int B, long long mid) {
    long long sum = 0;
    int painterRequired = 1;
    for(int i=0; i<C.size(); i++) {
        long long curTime = (long long)C[i] * B;
        if(curTime > mid) {
            return false;
        }
        if(sum + curTime > mid) {
            painterRequired++;
            sum = curTime;
        } else {
            sum += curTime;
        }
    }
    if(painterRequired > A) return false;
    return true;
}
int minTimeRequired(int A, int B, vector<int> &C) {
    int n = C.size(), mod = 10000003;
    if(A >= n) {
        int maxi = *max_element(C.begin(), C.end());
        return ((maxi%mod) * B)%mod;
    }

    long long sum = 0, mini = LLONG_MAX,ans = LLONG_MAX;
    for(int i=0; i<n; i++) {
        sum += (long long)C[i];
        mini = min(mini, (long long)C[i]);
    }

    sum *= (long long)B;   // maxTime
    mini *= (long long)B;   // minTime;
    // our Answer lies between minTime and maxTime, Therefore doing binary search in between.

    while(mini <= sum) {
        long long mid = (mini + sum)/2;
        if(isPossibleToAllocatePainter(C, A, B, mid)){
            ans = min(ans, mid);
            sum = mid -1;
        } else {
            mini = mid + 1;
        }
    }
    return (int)(ans%mod);
}
int main() {
    vector<int> arr = {1,10};
    cout<<minTimeRequired(2, 5, arr);
    return 0;
}