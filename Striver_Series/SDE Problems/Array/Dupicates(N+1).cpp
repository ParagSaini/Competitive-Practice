#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-duplicate-number/
// optimal solution
//t.c O(n) && s.c O(1), and our array will not be modified.

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
        
    fast = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}


// t.c O(n) && s.c O(1), but the approach will modify the our given array, we don't want that.

int findDuplicate(vector<int>& nums) {
    int ind = nums[0];
    while(true) {
        if(nums[ind] == -1) return ind;
        int temp = nums[ind];
        nums[ind] = -1;
        ind = temp;
    }
}

// t.c O(n) && s.c O(n)
int findDuplicate(vector<int>& nums) {
    vector<int> freq(nums.size(), 0);
    for(int i=0; i<nums.size(); i++) {
        if(freq[nums[i]] != 0) return nums[i];
        freq[nums[i]] = 1;
    }
    return -1;
}


// t.c O(nlogn), s.c O(1)
int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++) {
        if(nums[i-1] == nums[i]) return nums[i];
    }
    return -1;
}

// t.c O(n2), s.c O(1)
int findDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size()-1; i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[j] == nums[i]) return nums[j];
        }
    }
    return -1;
    
}