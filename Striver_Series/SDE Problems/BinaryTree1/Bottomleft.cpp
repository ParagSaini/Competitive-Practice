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
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        // Just flipping the ordering of the level order traversal
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
    return (temp->val);
}