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


// *************** Optimal Solution ******************
// T.c O(n) & S.c O(1).         // excluding the recursive stack space

bool inorder(TreeNode* root, TreeNode*& prev_Node) {
    if(root == nullptr) return true;
    bool l = inorder(root->left, prev_Node);
    if(prev_Node != nullptr && prev_Node->val >= root->val) return false;
    prev_Node = root;
    bool r = inorder(root->right, prev_Node);
    return (l && r);
    
}
bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    TreeNode* prev_Node = nullptr;
    return inorder(root, prev_Node);
}


// *************** optimal Solution and very Good Approach *********
// T.c O(n) & S.c O(1).         // excluding the recursive stack space
// The below code FAILS when tree contains the either INT_MIN or INT_MAX value;

bool isValidHelper(TreeNode* root, int min_Val, int max_Val){
    if(!root) return true;
    if(root->val <= min_Val || root->val >= max_Val) return false;
    return (isValidHelper(root->left, min_Val, root->val) && isValidHelper(root->right, root->val, max_Val));
}
bool isValidBST(TreeNode* root) {
    if(!root) return true;
    int min_Val = INT_MIN;
    int max_Val = INT_MAX;
    return isValidHelper(root, min_Val, max_Val);
}



// T.c O(n) & S.c O(n).
void inorder(const TreeNode* root, vector<int>& ar) {
    if(root == nullptr) return;
    inorder(root->left, ar);
    ar.push_back(root->val);
    inorder(root->right, ar);
}
bool isSorted(const vector<int>& ar) {
    for(int i=1; i<ar.size(); i++) {
        if(ar[i] <= ar[i-1]) return false;
    }
    return true;
}
bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    vector<int> inorderTraversal;
    inorder(root, inorderTraversal);
    return isSorted(inorderTraversal);
}


