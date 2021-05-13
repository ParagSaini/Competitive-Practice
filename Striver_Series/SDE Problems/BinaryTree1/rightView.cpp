#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        val = d;
        left = nullptr;
        right = nullptr;
    }
};

// SRL traversal
void rightSideHelper(TreeNode* root, vector<int>& result, int& count, int level) {
    if(!root) return;
    if(count < level) {
        result.push_back(root->val);
        count++;
    }
    rightSideHelper(root->right, result, count, level+1);
    rightSideHelper(root->left, result, count, level+1);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    int count = 0, level = 1;
    if(!root) return result;
    rightSideHelper(root, result, count, level);
    return result;
}