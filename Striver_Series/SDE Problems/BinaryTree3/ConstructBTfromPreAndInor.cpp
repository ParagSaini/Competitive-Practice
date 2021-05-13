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

TreeNode* buildTreeHelper(vector<int>& pre, vector<int>& ino, int rootInd, int s, int e, unordered_map<int, int>& index) {
    if(s > e || rootInd > pre.size()-1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(pre[rootInd]);
    
    int ind = index[pre[rootInd]];
    // int ind = 0;
    // for(int i=s; i<=e; i++) {
    //     if(ino[i] == pre[rootInd]) {
    //         ind = i;
    //         break;
    //     }
    // }
    
    int elementOnLeft = ind - s;
    root->left = buildTreeHelper(pre, ino, rootInd+1, s, ind-1, index);
    root->right = buildTreeHelper(pre, ino, rootInd+(elementOnLeft+1), ind+1, e,index);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int s = 0;
    int e = preorder.size()-1;
    unordered_map<int, int> index;
    for(int i=0; i<inorder.size(); i++) {
        index[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, inorder, 0, s, e, index);
}