#include<bits/stdc++.h>
using namespace std;

void subsetsHelper(vector<int>& nums, vector<int>& combination, vector<vector<int>>& result, int start) {
    
    if(start == nums.size()) {
        result.push_back(combination);
        return;
    }
    
    combination.push_back(nums[start]);
    subsetsHelper(nums, combination, result, start+1);
    combination.pop_back();
    subsetsHelper(nums, combination, result, start+1);
}
// nums doesn't contains the duplicates.
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> combination;
    vector<vector<int>> result;
    int start = 0;
    subsetsHelper(nums, combination, result, start);
    return result;
}
