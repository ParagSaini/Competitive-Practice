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

// t.c O(n) && s.c O(H),  worst case H == n(linear tree)
bool isMirror(TreeNode* l, TreeNode* r) {
    if(l == nullptr && r == nullptr) return true;
    if(l == nullptr || r == nullptr) return false;
    if(l->val != r->val) return false;
    return (isMirror(l->left, r->right) && isMirror(l->right, r->left));
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isMirror(root->left, root->right);
}

// t.c O(n) && s.c O(n)
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while(!q.empty()) {
        TreeNode* leftNode = q.front();
        q.pop();
        TreeNode* rightNode = q.front();
        q.pop();
        if(leftNode == nullptr && rightNode == nullptr) {
            continue;
        }
        if(leftNode == nullptr || rightNode == nullptr || (leftNode->val != rightNode->val)) return false;
        
        q.push(leftNode->left);
        q.push(rightNode->right);
        q.push(leftNode->right);
        q.push(rightNode->left);
    }
    return true;
}


// Naive approach ..
bool palindromeCheck(vector<int>& ar) {
    int s = 0;
    int e = ar.size()-1;
    while(s < e) {
        if(ar[s++] != ar[e--]) return false;
    }
    return true;
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        while(size--) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == nullptr) {
                level.push_back(INT_MIN);
                continue;
            }
            level.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            else q.push(nullptr);
            if(temp->right) q.push(temp->right);
            else q.push(nullptr);
        }
        if(!palindromeCheck(level)) {
            return false;
        }
    }
    return true;
}

