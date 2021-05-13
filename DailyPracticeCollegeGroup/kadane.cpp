#include<bits/stdc++.h>
using namespace std;
// we don't need a subarray of negative sum, as our goal is to maximise the sum. so we set it to zero whenever it get negative.
//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
int maxSubarraySum(int arr[], int n){
    int subarraySum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++) {
        subarraySum += arr[i];
        maxSum = max(maxSum, subarraySum);
        if(subarraySum < 0) subarraySum = 0;
    }
    return maxSum;
}