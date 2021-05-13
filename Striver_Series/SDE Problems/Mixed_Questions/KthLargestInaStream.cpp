#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int min_heap_size = 0;
    KthLargest(int k, vector<int>& nums) {
        min_heap_size = k;
        for(int i=0; i<nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        int cur = val;
        if(min_heap.size() == min_heap_size) {
            int top = min_heap.top();
            if(cur > top) {
                min_heap.pop();
                min_heap.push(cur);
            }
        }else {
            min_heap.push(cur);
        }
        return min_heap.top();
    }
};