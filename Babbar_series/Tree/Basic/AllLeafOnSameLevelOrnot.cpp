void helper(Node* root,int h, unordered_set<int>& height) {
    if(root->left == nullptr && root->right == nullptr) {
        height.insert(1+h);
        return;
    }
    if(root->left != nullptr) {
        helper(root->left, 1+h, height);
    }
    if(root->right != nullptr) {
        helper(root->right, 1+h, height);
    }
}
bool check(Node *root)
{
    unordered_set<int> height;
    helper(root, 0,  height);
    if(height.size() > 1) return 0;
    return 1;
}