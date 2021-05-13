#include<bits/stdc++.h>
using namespace std;
// Intuition: 
/*  Step 1: Traversing from back, finding the index for which 
a[index] > a[index-1];
Step 2: traverse the array from end to index+1, find the just greater element index in array and break;
Step 3: swap the index and justGreaterIndex element and Reverse the array from index+1 to end;
*/

void reverse(vector<int>& nums, int s, int e) {
    while(s < e) {
        swap(nums[s++], nums[e--]);
    }
}
void nextPermutation(vector<int>& nums) {
    int index = -1;
    for(int i=nums.size()-1; i>=1; i--) {
        if(nums[i] > nums[i-1]) {
            index = i-1;
            break;
        }
    }
    if(index == -1) {
        reverse(nums, 0, nums.size()-1);
        return;
    }
    
    int swapInd = -1;
    for(int i=nums.size()-1; i>index; i--) {
        if(nums[i] > nums[index]) {
            swapInd = i;
            break;
        }
    }
    
    swap(nums[index], nums[swapInd]);
    
    reverse(nums, index+1, nums.size()-1);
}