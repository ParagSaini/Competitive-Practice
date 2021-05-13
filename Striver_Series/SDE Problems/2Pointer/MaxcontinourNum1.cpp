#include<bits/stdc++.h>
using namespace std;


int findMaxConsecutiveOnes(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    
    int maxcount = 0;
    int count = 0;
    for(int i = 0; i<nums.size(); i++) {
        if(nums[i] == 0) count = 0;
        else {
            count++;
            maxcount = max(count, maxcount);
        }
    }
    return maxcount;
}