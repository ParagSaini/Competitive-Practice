#include<bits/stdc++.h>
using namespace std;

int countPairInSortedArr(vector<int>& ar, int s1, int e1, int e2) {
    int count = 0;
    
    int start1 = s1;
    int end1 = e1;
    int start2 = end1+1;
    int end2 = e2;

    while(start1 <= end1 && start2 <= end2) {
        // we have to covert to long long before comparing to avoid interger overflow..
        
        if(ar[start1] > (long long)2 * ar[start2]) {
            count += end1 - start1 + 1;
            start2++;
        } else {
            start1++;
        }
    }
    return count;

}

// this is the merge method same as merge sort and inversion of array question..
int mergeAndCount(vector<int>& ar, int s1, int e1, int e2) {
    
    int count  = 0;
    int start1 = s1;
    int end1 = e1;
    int start2 = end1+1;
    int end2 = e2;
    int size = end2 - start1 + 1;

    // the only difference between inversion problem and this problem.    
    count = countPairInSortedArr(ar, s1, e1, e2);
        
    vector<int> temp(size);
    int i = 0;
    while(start1 <= end1 && start2 <= end2) {
        if(ar[start1] > ar[start2]) {
            temp[i] = ar[start2];
            start2++;            
        } else {
            temp[i] = ar[start1];
            start1++;   
        }
        i++;
    }
    if(start1 > end1) {
        while(start2 <= end2) {
            temp[i++] = ar[start2++];
        }
    }
    else if(start2 > end2 ) {
        while(start1 <= end1) {
            temp[i++] = ar[start1++];
        }
    }

    int k = 0;
    for(int i=s1; i<=e2; i++) {
        ar[i] = temp[k++];
    }

    return count;
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