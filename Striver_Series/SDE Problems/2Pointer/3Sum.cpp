#include<bits/stdc++.h>
using namespace std;

// Time complexity = O(n^2);

vector<pair<int, int>> twoPointerSearch(int s, int e, int val, vector<int>& nums) {
    int start = s;
    int end = e;
    
    vector<pair<int, int>> result;
    
    while(start < end) {
        // to skip the duplicates..
        if(start > s && end < e && nums[start] == nums[start-1] && nums[end] == nums[end+1]) {
            start++;
            end--;
            continue;
        }
        // the below line are not necessary to skip the duplicate, above line handle all the cases.

        // if(start > s && nums[start] == nums[start-1]) {
        //     start++;
        //     continue;
        // }
        // if(end < e && nums[end] == nums[end+1]) {
        //     end--;
        //     continue;
        // }
        int sum = nums[start] + nums[end];
        if(sum == val) {
            result.push_back({nums[start], nums[end]});
            start++;
            end--;
        } 
        else if(sum > val) end--;
        else start++;
    }
    return result;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int val = 0;
    vector<vector<int>> result;
    if(nums.size() <= 2) return result;
    
    // sorting the array.
    sort(nums.begin(), nums.end());

    for(int i=0; i<=nums.size() - 3; i++) {
        // skipping the duplicates
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        // finding the pair with value = (val - nums[i])..
        vector<pair<int, int>> P = twoPointerSearch(i+1, nums.size()-1, val - nums[i], nums);
        for(int k=0; k<P.size(); k++) {
            pair<int, int> cur = P[k];
            vector<int> ar = {nums[i], cur.first, cur.second};
            result.push_back(ar);
        }
    }
    return result;
}