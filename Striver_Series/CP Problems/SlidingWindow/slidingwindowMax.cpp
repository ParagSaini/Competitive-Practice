#include<bits/stdc++.h>
using namespace std;

// t.c O(n) && s.c O(n)       // not in the problem set, there are much more tougher in the sheet.
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    // maintaing the ascending order sorted deque using index not val.
    for (int i=0; i<nums.size(); i++) {
        if (!dq.empty() && dq.back() == i-k) dq.pop_back();  // checking is maxVal still in our window.
        while (!dq.empty() && nums[dq.front()] < nums[i])
            dq.pop_front();
        dq.push_front(i);
        
        // dq.back() contains the maximum value of that window.
        if (i>=k-1) ans.push_back(nums[dq.back()]);
    }
    return ans;
}