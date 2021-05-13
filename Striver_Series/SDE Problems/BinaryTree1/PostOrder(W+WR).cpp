#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};

vector<int> postOrderIterative(TreeNode* root) {
    vector<int> result;
    if(root == nullptr) return result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(!st.empty() || cur != nullptr) {
        
        while(cur != nullptr) {
            st.push(cur);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
        
        TreeNode* top = st.top();
        result.push_back(top->val);
        st.pop();
        if(!st.empty() && st.top()->left == top) {
            cur = st.top()->right;
        } 
    }
    return result;
}


void postOrderHelper(TreeNode* root, vector<int>& ar) {
    if(!root) return;
    postOrderHelper(root->left, ar);
    postOrderHelper(root->right, ar);
    ar.push_back(root->val);
}
vector<int> postOrderRecursive(TreeNode* root) {
    vector<int> result;
    if(!root) return result;
    postOrderHelper(root, result);
    return result;
}