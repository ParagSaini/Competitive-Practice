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
int BalancedHeightHelper(TreeNode* root, bool& balanced) {
    if(!root) return 0;
    int l = BalancedHeightHelper(root->left, balanced);
    int r = BalancedHeightHelper(root->right, balanced);
    if(abs(l-r) > 1)  balanced = false;
    return (1 + max(l, r)); 
}
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    bool balanced = true;
    BalancedHeightHelper(root, balanced);
    return balanced;
}