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

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if(!root) return 0;
    // think the problem as you have only +ve number in the tree, and try modify the approach to deal with -ve numbers also, as below max(0, maxPathSumHelper....) did .
    int l = max(0, maxPathSumHelper(root->left, maxSum));// very nice modification if we have positive numbers.
    int r = max(0, maxPathSumHelper(root->right, maxSum));
        
    if((l+r+root->val) > maxSum) maxSum = (l+r+root->val);
    
    return (max(l, r) + root->val);
    
}

int maxPathSum(TreeNode* root) {
    if(!root) return 0;
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}