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
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr && q != nullptr) return false;
    if(p != nullptr && q == nullptr) return false;
    if(p->val != q->val) return false;
    
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) ;
}