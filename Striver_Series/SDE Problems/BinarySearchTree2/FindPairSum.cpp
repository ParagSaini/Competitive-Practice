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
// can be done in t.c O(n) && s.c O(log(n)) using normal inorder and reverse inorder traversal together.


// inorder traversal of Bst is always a sorted Array. and finding the pair sum in sorted it took O(n), so therfore t.c O(n) & s.c O(n)
void inorder(TreeNode* root, vector<int>& sortedAr) {
    if(!root) return;
    inorder(root->left, sortedAr);
    sortedAr.push_back(root->val);
    inorder(root->right, sortedAr);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> sortedAr;
    inorder(root, sortedAr);
    int s = 0;
    int e = sortedAr.size()-1;
    while(s < e) {
        int sum = sortedAr[s] + sortedAr[e];
        if(sum == k) return true;
        if(sum > k) e--;
        else s++;
    }
    return false;
}



// HashSet and treeTraversal, t.c O(n) s.c O(n)--------same solution if tree is binary
bool preorder(TreeNode* root, int k, unordered_set<int>& visited){
    if(!root) return false;
    if(visited.count(root->val)) return true;
    visited.insert(k - root->val);
    return (preorder(root->left, k,visited) || preorder(root->right, k, visited));
}
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> visited;
    return preorder(root, k, visited);
}