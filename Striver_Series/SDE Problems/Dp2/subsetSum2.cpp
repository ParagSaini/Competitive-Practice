#include<bits/stdc++.h>
using namespace std;

// we have to find whether or not we can divide the numbers in two sets such that all numbers should be present and sum of both the sets are equal. 
// using the array is just superfast, always use the array dp not vector one


bool equalPartitionHelper(int N, int nums[], int sum1, int& totalSum, int start, int** dp) {
    if(sum1 == totalSum/2 ) return true;
    if(start >= N || sum1 > totalSum/2) return false;
    
    if(dp[start][sum1] != -1) return dp[start][sum1];
    
    bool a = equalPartitionHelper(N, nums, sum1+nums[start], totalSum, start+1, dp);
    bool b = equalPartitionHelper(N, nums, sum1, totalSum, start+1, dp);
    
    dp[start][sum1] = (a||b);
    return dp[start][sum1];
}
bool canPartition(int N, int nums[]) {
    int start = 0, totalSum = 0, sum1 = 0;
    
    for(int i=0; i<N; i++) totalSum += nums[i];
    if(totalSum % 2 != 0) return false;
    
        int** dp = new int*[N];
    for(int i=0; i<N; i++) dp[i] = new int[totalSum/2 + 1];
    for(int i=0; i<N; i++) {
        for(int j=0; j<=totalSum/2; j++) dp[i][j] = -1;
    }        

    return equalPartitionHelper(N, nums, sum1, totalSum, start, dp);
}