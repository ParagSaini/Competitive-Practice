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

TreeNode* BSTHelper(vector<int>& nums, int s, int e) {
    if(s > e) return nullptr;
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = BSTHelper(nums, s, mid-1);
    root->right = BSTHelper(nums, mid+1, e);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) return nullptr;
    return BSTHelper(nums, 0, nums.size()-1);
}