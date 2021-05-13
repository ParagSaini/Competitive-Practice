#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    if(s.empty()) return true;
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        if(st.empty()) {
            st.push(s[i]);
            continue;
        }
        char top = st.top();
        if(top == '(' && s[i] == ')') {
            st.pop();
        } else if(top == '{' && s[i] == '}') {
            st.pop();
        } else if(top == '[' && s[i] == ']'){
            st.pop();
        }else {
            st.push(s[i]);
        }
    }
    if(st.empty()) return true;
    return false;
}