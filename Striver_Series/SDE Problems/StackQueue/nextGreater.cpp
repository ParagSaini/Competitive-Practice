#include<bits/stdc++.h>
using namespace std;

// O(n) approach..
/* traverse the array and check, if the cur value is less than the s.top(), then push it in the stack, but if it greater than top value, we know that it is the next greater element, so we continuously pop from the stack until we hit the value which is greater than cur value;
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if(nums1.size() == 0) return result;
    stack<int> st;
    unordered_map<int, int> nextgreater;
    for(int i=0; i<nums2.size(); i++) {
        while(!st.empty() && st.top() < nums2[i]) {
            nextgreater[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    while(!st.empty()) {
        nextgreater[st.top()] = -1;
        st.pop();
    }
    
    for(int i = 0; i<nums1.size(); i++) {
        result.push_back(nextgreater[nums1[i]]);
    }
    return result;
}