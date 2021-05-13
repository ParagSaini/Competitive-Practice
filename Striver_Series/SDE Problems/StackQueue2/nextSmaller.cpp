// Exactly same as the next greatest element problem.
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> nextGreaterElement(vector<int>& ar) {
    unordered_map<int, int> nextgreater;
    stack<int> st;
    
    if(ar.size() == 0) return nextgreater;

    for(int i=0; i<ar.size(); i++) {
        while(!st.empty() && st.top() > ar[i]) {
            nextgreater[st.top()] = ar[i];
            st.pop();
        }
        st.push(ar[i]);
    }

    while(!st.empty()) {
        nextgreater[st.top()] = -1;
        st.pop();
    }
    
    return nextgreater;
}