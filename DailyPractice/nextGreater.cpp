// link: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
#include<bits/stdc++.h>
using namespace std;

vector <long long> nextLargerElement(long long arr[], int n){
    vector<long long> result(n);
    stack<pair<long long, int>> st;
    for(int i=0; i<n; i++) {
        long long cur = arr[i];
        if(st.empty()) st.push({arr[i], i});
        else {
            while(!st.empty() && st.top().first < cur) {
                result[st.top().second] = cur;
                st.pop();
            }
            st.push({cur, i});
        }
    }
    while(!st.empty()) {
        result[st.top().second] = -1;
        st.pop();
    }
    return result;
}