//Time complexity = O(n), space complexity O(h) recursive stack.
void isBstHelper(Node* root,int& prevVal, bool& flag) {
    if(!root) return;
    if(flag) {
        isBstHelper(root->left, prevVal, flag);
        if(root->data <= prevVal) {
            flag = false;
            return;
        }
        if(flag) {
            prevVal = root->data;
            isBstHelper(root->right, prevVal, flag);
        }
    }
}
bool isBST(Node* root) {
    bool flag = true;
    int prevVal = INT_MIN;
    isBstHelper(root, prevVal, flag);
    return flag;
}