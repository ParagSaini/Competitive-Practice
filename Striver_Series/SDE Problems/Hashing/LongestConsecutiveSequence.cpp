#include<bits/stdc++.h>
using namespace std;

// Sorting the array and then out, O(nlg(n));
int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int maxL = 1;
    sort(nums.begin(), nums.end());
    int l = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) continue;
        if(nums[i] == nums[i-1] + 1){
            l++;
            maxL = max(maxL, l);
        } else {
            maxL = max(maxL, l);
            l = 1;
        }
    }
    return maxL;   
    
}

// O(n) approach, actualling finding the starting number of every possible sequence, and count the length.

int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int maxL = 1;
    unordered_set<int> numbers;
    for(auto i : nums) numbers.insert(i);
    for(auto i : numbers) {
        if(!numbers.count(i-1)) {
            int k = i;
            int l = 0;
            // calculating the sequence length.
            while(numbers.count(k)) {
                l++;
                k++;
            }
            maxL = max(maxL, l);
        }
    }
    return maxL;
}