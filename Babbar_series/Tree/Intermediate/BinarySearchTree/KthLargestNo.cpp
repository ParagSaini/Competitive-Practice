void RSL(Node* root, int& k, int& ans, bool& flag) {
    if(!root) return;
    if(flag) {
        RSL(root->right, k, ans, flag);
        k--;
        if(k == 0) {
            ans = root->data;
            flag = false;
        }
        if(flag) 
            RSL(root->left, k, ans, flag);
    }
}
int kthLargest(Node *root, int K)
{
    int ans = root->data;
    bool flag = true;
    RSL(root, K, ans, flag);
    return ans;
}