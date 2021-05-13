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
void inorderRecursive(TreeNode* root, vector<int>& result) {
    if(root == nullptr) return;
    inorderRecursive(root->left, result);
    result.push_back(root->val);
    inorderRecursive(root->right, result);
}

vector<int> inorderiterative(TreeNode* root) {
    vector<int> result;
    if(root == nullptr) return result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(!st.empty() || cur != nullptr) {
        while(cur) {
            st.push(cur);
            cur = cur->left;
        }
        result.push_back(st.top()->val);
        cur = st.top()->right;
        st.pop();
    }
    return result;
}