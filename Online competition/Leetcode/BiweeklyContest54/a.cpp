#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

int minOperationsToFlip(string expression) {
    int val = -1;
    stack<char> st;
    int n = expression.size();
    for(int i=n-1; i>=0; i--) {
        if(expression[i] == ')') st.push(expression[i]);
        else if(expression[i] == '(') {
            while(!st.empty()) {

            }
        } else {
            st.push(expression[i]);
        }
    }
}
int main() {
    cout<<minOperationsToFlip("(1|0)");
    return 0;
}