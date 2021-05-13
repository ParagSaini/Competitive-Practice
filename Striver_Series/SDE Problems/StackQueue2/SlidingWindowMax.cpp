#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if(nums.size() == 0) return result;
    
    deque<int> dq;
    for(int i=0; i<k; i++) {
        while(!dq.empty() && dq.back() < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }
// i should be < nums.size() - k not equal to, to avoid the segmentation fault in getting nums[i+k]
    for(int i=0; i<(nums.size() - k); i++) {
        result.push_back(dq.front());
        int Willremove = nums[i];
        int Willadd = nums[i+k];
        
        if(Willremove == dq.front()) {
            dq.pop_front();
        }
        while(!dq.empty() && dq.back() < Willadd) {
            dq.pop_back();
        }
        dq.push_back(Willadd);
    }
    result.push_back(dq.front());
    
    return result;
}