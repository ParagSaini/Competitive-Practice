#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int s1, int e1, int e2) {
    int pairs = 0;
    int s2 = e1+1;
    while((s1 <= e1) && (s2 <= e2)) {
        // we have to covert to long long before comparing to avoid interger overflow..
        long long val1 = nums[s1], val2 = nums[s2];
        if(val1 > (2*val2)) {
            pairs += (e1-s1 + 1);
            s2++;
        } else {
            s1++;
        }
    }
    return pairs;
}

// this is the merge method same as merge sort and inversion of array question..

int mergeAndCount(vector<int>& nums, int s1, int e1, int e2) {
    vector<int> sortArr;
    int start1 = s1, start2 = e1+1;
    
    // the only difference between inversion problem and this problem.
    int pairs = countPairs(nums, s1, e1, e2);

    while((start1 <= e1) && (start2 <= e2)) {
        if(nums[start1] <= nums[start2]) {
            sortArr.push_back(nums[start1]);
            start1++;
        } else {
            sortArr.push_back(nums[start2]);
            start2++;
        }
    }
    while(start1 <= e1) {
        sortArr.push_back(nums[start1++]);
    }
    while(start2 <= e2) {
        sortArr.push_back(nums[start2++]);
    }
    int k = 0;
    for(int i=s1; i<=e2; i++) {
        nums[i] = sortArr[k++];
    }
    return pairs;
}

int reversePairsHelper(vector<int>& nums, int s, int e) {
    if(s >= e) return 0;
    
    int mid = (s+e)/2;
    int l = reversePairsHelper(nums, s , mid);
    int r = reversePairsHelper(nums, mid+1, e);
    int m = mergeAndCount(nums, s, mid, e);
    return (l+r+m);
}
int reversePairs(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1 ) return 0;
    return reversePairsHelper(nums, 0, nums.size()-1); 
}