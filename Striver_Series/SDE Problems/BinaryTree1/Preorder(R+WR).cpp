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
void preorderHl(TreeNode* root, vector<int>& r) {
    if(!root) return;
    r.push_back(root->val);
    preorderHl(root->left, r);
    preorderHl(root->right, r);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root == nullptr) return result;
    preorderHl(root, result);
    return result;
}
vector<int> preorderLoop(TreeNode* root) {
    vector<int> result;
    if(root == nullptr) return result;
    stack<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()) {
        TreeNode* top = nodes.top();
        nodes.pop();
        result.push_back(top->val);
        if(top->right) nodes.push(top->right);
        if(top->left) nodes.push(top->left);
    }
    return result;
}