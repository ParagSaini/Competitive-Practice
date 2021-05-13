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
int DiameterHelper(TreeNode* root, int& maxLength) {
    if(!root) return 0;
    int l = DiameterHelper(root->left, maxLength);
    int r = DiameterHelper(root->right, maxLength);
    if(maxLength < (l+r)) maxLength = (l+r);
    return (1 + max(l, r));
}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int maxLength = INT_MIN;
    DiameterHelper(root, maxLength);
    return maxLength;
}
