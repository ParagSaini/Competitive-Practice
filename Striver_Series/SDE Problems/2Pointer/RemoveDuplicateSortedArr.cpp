#include<bits/stdc++.h>
using namespace std;

// return length of the modified array(by reference).
int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    
    int index = 0;
    nums[index] = nums[0];
    index++;
    
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            continue;
        }else {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

// if you want to decrease the line of code, you should consider the below implementation..

int removeDuplicated(vector<int>& A) {
    int n = A.size();
    int count = 0;
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]) count++;
        else A[i-count] = A[i];
    }
    return n-count;
}