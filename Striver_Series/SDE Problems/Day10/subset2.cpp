#include<bits/stdc++.h>
using namespace std;

// same as the problem combSum2 , as it solution.
void subsetsHelper(vector<int>& nums, vector<int>& combination, vector<vector<int>>& result, int start, bool prevTaken) {
    
    if(start == nums.size()) {
        result.push_back(combination);
        return;
    }
    if(start != 0 && prevTaken == false && nums[start] == nums[start-1]) {
        subsetsHelper(nums, combination, result, start+1, false);
        return;
    }
    
    combination.push_back(nums[start]);
    subsetsHelper(nums, combination, result, start+1, true);
    combination.pop_back();
    subsetsHelper(nums, combination, result, start+1, false);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> combination;
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int start = 0;
    bool prevTaken = false;
    subsetsHelper(nums, combination, result, start, false);
    return result;
}