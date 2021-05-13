#include<bits/stdc++.h>
using namespace std;
class et {
    public:
    int data;
    et* left;
    et* right;
    et(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^') return true;
    return false;
}

// t.c O(n) && s.c O(n)
et* constructTree(char postfix[])
{
    if(postfix[1] == '\0') return new et(postfix[0]);
    stack<et*> st;
    int i = 0;
    while(postfix[i] != '\0') {
        if(isOperator(postfix[i]) && !st.empty()) {
            et* op2 = st.top(); st.pop();
            et* op1 = st.top(); st.pop();
            et* operand = new et(postfix[i]);
            operand->left = op1;
            operand->right = op2;
            st.push(operand);
        }else st.push(new et(postfix[i]));
        i++;
    }
    return st.top();
}