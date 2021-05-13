#include<bits/stdc++.h>
using namespace std;


// optimal solution
// Moore Voting Algorithm       T.c O(n) and S.c O(1);

int majorityElement(vector<int>& nums) {
    int count = 0;
    int ele = 0;
    for(int i=0; i<nums.size(); i++) {
        if(count == 0) ele = nums[i];
        if(ele == nums[i]) count++;
        else count--;
    }
    return ele;
}

// HashMap solution T.c O(n) and S.c O(n);
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m;
    int n = nums.size()/2;
    
    for(int i=0; i<nums.size(); i++) {
        if(m.count(nums[i])) m[nums[i]]++;
        else m[nums[i]] = 1;
        if(m[nums[i]] > n) return nums[i];
    }
    return -1;
}
