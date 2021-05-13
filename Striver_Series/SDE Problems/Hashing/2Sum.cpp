#include<bits/stdc++.h>
using namespace  std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int,int> m;
    for(int i=0; i<nums.size(); i++) {
        if(m.count(nums[i])) {
            result.push_back(m[nums[i]]);
            result.push_back(i);
            break;
        }
        m[target-nums[i]] = i;
    }
    return result;
}