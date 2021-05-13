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

int Height(TreeNode* root) {
    if(!root) return 0;
    int l = Height(root->left);
    int r = Height(root->right);
    return (1 + max(l, r));
}