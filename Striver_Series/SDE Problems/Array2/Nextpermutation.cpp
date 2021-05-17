#include<bits/stdc++.h>
using namespace std;

// using std library
void nextPermutation(vector<int>& nums) {
    // next_permutation require two arguments, starting iterator, ending iterator.
   // prev_permutation(nums.begin(), nums.end()); for previous permutation finding.
    next_permutation(nums.begin(), nums.end());
}

// Intuition: 
/*  Step 1: Traversing from back, finding the index for which, finding that dip. 
a[i] < a[i+1];
Step 2: traverse the array from end to index+1, find the just greater element index in array and break;
Step 3: swap the index and justGreaterIndex element and Reverse the array from index+1 to end;
*/


void reverse(vector<int>& nums, int s, int e) {
    while(s < e) {
        swap(nums[s++], nums[e--]);
    }
}
void nextPermutation(vector<int>& nums) {
    int ind1 = -1, ind2 = -1;
    for(int i=nums.size()-2; i>=0; i--) {
        if(nums[i] < nums[i+1]) {
            ind1 = i;
            break;
        }
    }
    if(ind1 == -1) {
        reverse(nums, 0, nums.size()-1);
        return;
    }
    for(int i=nums.size()-1; i>ind1; i--) {
        if(nums[i] > nums[ind1]) {
            ind2 = i;
            break;
        }
    }
    
    swap(nums[ind1], nums[ind2]);
    reverse(nums, ind1+1, nums.size()-1);
}