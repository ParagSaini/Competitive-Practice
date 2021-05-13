#include<bits/stdc++.h>
using namespace std;

void permuteHelper(vector<int> nums, int start, vector<vector<int>>& result) {
    // finally get our one of the permutation.
    if(start == nums.size()-1){
        result.push_back(nums);
        return;
    }
    for(int i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        permuteHelper(nums, start + 1, result);  
        // backtracking.          
        swap(nums[i], nums[start]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size() == 0) {
        // done because, output should have atleast one row to get accepted on leetcode.
        vector<vector<int>> result(1);
        return result;
    };
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}
