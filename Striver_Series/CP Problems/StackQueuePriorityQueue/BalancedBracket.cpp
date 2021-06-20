#include<bits/stdc++.h>
using namespace std;


string isBalanced(string s) {
    int n = s.length();
    if((n % 2) != 0) return "NO";
    stack<char> st;
    for(int i=0; i<n; i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') st.push(s[i]);
        else {
            if(st.empty()) return "NO";
            if(s[i] == '}' && st.top() == '{')  st.pop();
            else if(s[i] == ')' && st.top() == '(') st.pop();
            else if(s[i] == ']' && st.top() == '[') st.pop();
            else return "NO";
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}

int main() {
    string s;
    cin>>s;
    cout<<isBalanced(s)<<endl;
    return 0;
}