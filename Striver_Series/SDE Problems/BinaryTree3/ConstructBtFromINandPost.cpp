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

TreeNode* buildTreeHelper(vector<int>& in, vector<int>& post, int rootInd, int s, int e, unordered_map<int, int>& index) {
    if(s > e || rootInd < 0) return nullptr;
    TreeNode* root = new TreeNode(post[rootInd]);
    
    int ind = index[post[rootInd]];
    // int ind = 0;
    // for(int i=s; i<=e; i++) {
    //     if(in[i] == post[rootInd]) {
    //         ind = i;
    //         break;
    //     }
    // }
    int elementOnright = e - ind;
    root->left = buildTreeHelper(in, post, rootInd-(elementOnright+1), s, ind-1, index);
    root->right = buildTreeHelper(in, post, rootInd-1, ind+1, e, index);
    
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int s = 0;
    int e = inorder.size()-1;
    unordered_map<int, int> index;
    for(int i=0; i<inorder.size(); i++ ){
        index[inorder[i]] = i;
    }
    return buildTreeHelper(inorder, postorder, postorder.size()-1, s, e, index);
}