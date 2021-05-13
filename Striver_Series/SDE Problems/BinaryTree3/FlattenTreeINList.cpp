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


// optimal approach.

// This approach uses the RLS( reverse preorder traversal)
void flattenHelper(TreeNode* root, TreeNode*& prev) {
    if(!root) return;
    flattenHelper(root->right, prev);
    flattenHelper(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}
void flatten(TreeNode* root) {
    if (root == nullptr)
        return;
    TreeNode* prev = nullptr;
    flattenHelper(root, prev);
}


// my approach .. 
// Doing preorder traversal iteratively, and joining the nodes.
void flatten(TreeNode* root) {
    if(!root) return;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* prev = nullptr;
    while(!s.empty()) {
        TreeNode* top = s.top();
        s.pop();
        if(prev == nullptr) prev = root;
        else {
            prev->right = top;
            prev = prev->right;
        }
        if(top->right) s.push(top->right);
        if(top->left) s.push(top->left);
    }
    TreeNode* cur = root;
    // assigning nullptr to all left sides.
    while(cur) {
        cur->left = nullptr;
        cur = cur->right;
    }
}
