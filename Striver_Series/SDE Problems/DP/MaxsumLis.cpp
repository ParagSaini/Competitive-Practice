#include<bits/stdc++.h>
using namespace std;

// This question is same as the Lis, just replace the count with the current element.

int LisHelper(int nums[], int n, int start, int lastElofSeq, int dp[]) {
    if(start >= n) return 0;
    if(dp[start] != -1) return dp[start];
    int maxSum = 0;
    for(int i=start; i<n; i++) {
        // starting the new sequence whose first element is nums[i]
        if(nums[i] > lastElofSeq ) {
            int sum = nums[i] + LisHelper(nums, n, i+1, nums[i], dp);
            maxSum = max(sum, maxSum);
        }
    }
    dp[start] = maxSum;
    return dp[start];
}

int maxSumIS(int arr[], int n)  
{  
    int dp[n];
    for(int i=0; i<n; i++) dp[i] = -1;
    return LisHelper(arr, n, 0, INT_MIN, dp);
} 