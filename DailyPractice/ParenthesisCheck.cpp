// link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1/?company[]=Amazon&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1

// more efficient in time, less ifelse statements
#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    if(x.length() == 0) return true;
    stack<char> st;
    for(int i=0; i<x.length(); i++) {
        if(x[i] == '{' || x[i] == '(' || x[i] == '[') st.push(x[i]);
        else {
            if(st.empty() || (x[i] - st.top() > 2) ) return false;
            st.pop();
        }
    }
    if(st.empty()) return true;
    return false;
}
// naive
bool ispar(string x)
{
    if(x.length() == 0) return true;
    stack<char> st;
    for(int i=0; i<x.length(); i++) {
        if(st.empty()) st.push(x[i]);
        else {
            if(x[i] == '}' && st.top() == '{') {
                st.pop();
            } else if(x[i] == ')' && st.top() == '('){
                st.pop();
            } else if(x[i] == ']' && st.top() == '[') {
                st.pop();
            }else {
                st.push(x[i]);
            }
        }
    }
    if(st.empty()) return true;
    return false;
}