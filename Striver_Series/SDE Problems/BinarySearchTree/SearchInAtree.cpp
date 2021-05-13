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
// recursively
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return root;
    if(root->val == val) return root;
    if(val > root->val ) return searchBST(root->right, val);
    return searchBST(root->left, val);
}

// iteratively
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return root;
    TreeNode* cur = root;
    while(cur) {
        if(cur->val == val) return cur;
        if(val > cur->val) cur = cur->right;
        else cur = cur->left;
    }
    return nullptr;
}