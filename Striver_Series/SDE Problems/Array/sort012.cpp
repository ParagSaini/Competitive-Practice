#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// t.c O(n) && s.c O(1)
void sortColors(vector<int>& nums) {
    int cur = 0, low = 0, high = nums.size()-1;

    // cur must be <= high, not < high only ex [2,0,1] will help
    while(cur <= high) {
        if(nums[cur] == 0) {
            swap(nums[cur], nums[low]);
            cur++;
            low++;
        } else if(nums[cur] == 1) {
            cur++;
        } else {
            swap(nums[cur], nums[high]);
            high--;
        }
    }
}