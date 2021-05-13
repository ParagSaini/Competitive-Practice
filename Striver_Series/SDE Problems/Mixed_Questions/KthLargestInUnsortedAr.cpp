#include<bits/stdc++.h>
using namespace std;

// t.c O(nLog(k)) & s.c O(k), can be optimized using some partitioned algorithm.
int findKthLargest(vector<int>& nums, int k) {
    if(nums.size() == 0) return -1;
    
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<k; i++) {
        min_heap.push(nums[i]);
    }
    for(int i=k; i<nums.size(); i++) {
        if(nums[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(nums[i]);
        } 
    }
    return min_heap.top();
}