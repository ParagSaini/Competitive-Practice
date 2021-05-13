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

// doing LSR traversal
void inorder(TreeNode* root, int k, int& ans, int& count) {
    if(!root) return; 
    inorder(root->left, k, ans, count);
    if(count == k) return;
    count++;
    ans = root->val;
    inorder(root->right, k, ans, count);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    int count = 0;
    inorder(root, k, ans, count);
    return ans;
}