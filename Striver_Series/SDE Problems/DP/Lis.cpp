#include<bits/stdc++.h>
using namespace std;
// all the elements are +ve, thats why INT_MIN works, but if negative numbers are also present then we have to use the LLONG_MIN instead of INT_MIN.

// Time complexity = O(n^2)

int LisHelper(vector<int>& nums, int start, int lastElofSeq, int dp[]) {
    if(start >= nums.size()) return 0;
    if(dp[start] != -1) return dp[start];
    int maxLen = 0;
    for(int i=start; i<nums.size(); i++) {
        // starting the new sequence whose first element is nums[i]
        if(nums[i] > lastElofSeq ) {
            int len = 1 + LisHelper(nums, i+1, nums[i], dp);
            maxLen = max(len, maxLen);
        }
    }
    dp[start] = maxLen;
    return dp[start];
}
int lengthOfLIS(vector<int>& nums) {
    int dp[nums.size()];
    for(int i=0; i<nums.size(); i++) dp[i] = -1;
    return LisHelper(nums, 0, INT_MIN, dp);
}