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
// doing the reverse of inorderTraveral, i.e RSL
void inorder(TreeNode* root, int k, int& ans, int& count) {
    if(!root) return; 
    inorder(root->right, k, ans, count);
    if(count == k) return;
    count++;
    ans = root->val;
    inorder(root->left, k, ans, count);
}
int kthLargest(TreeNode* root, int k) {
    int ans = 0;
    int count = 0;
    inorder(root, k, ans, count);
    return ans;
}