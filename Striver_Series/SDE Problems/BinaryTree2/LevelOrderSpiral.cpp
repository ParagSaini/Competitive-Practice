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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    queue<TreeNode*> q;
    bool leftToRight = true;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> row(size);
        int s = 0;
        while(size--) {
            TreeNode* temp = q.front();
            q.pop();
            
            if(leftToRight) {
                row[s++] = temp->val;
            }
            else {
                row[size] = temp->val;
            }
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        result.push_back(row);
        leftToRight = !leftToRight;
    }
    return result;
}