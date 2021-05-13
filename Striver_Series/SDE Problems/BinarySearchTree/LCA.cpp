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

// iteratively
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    // this is given that p and q are unique and they both are present in the BST.
    while (true) {
        if (p->val < cur->val && q->val < cur->val) {
            cur = cur->left;
        } else if (p->val > cur->val && q->val > cur->val) {
            cur = cur->right;
        } else {
            // we found the lca
            break;
        }
    }
    return cur;
}


// recursively..
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val == p->val || root->val == q->val) return root;
    if( (p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val) ) return root;
    if(p->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return lowestCommonAncestor(root->left, p, q);
}