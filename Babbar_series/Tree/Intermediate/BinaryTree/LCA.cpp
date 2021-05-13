void preorder(Node* root, int n, vector<Node*>& ar, bool& flag) {
    if(root == nullptr) return;
    if(root->data == n ) {
        ar.push_back(root);
        flag = false;
        return;
    }
    if(flag) {
        ar.push_back(root);
        preorder(root->left, n, ar, flag);
        preorder(root->right, n, ar, flag);
        if(flag)
            ar.pop_back();
    }
}
Node* lca(Node* root ,int n1 ,int n2 )
{
   if(root == nullptr) return nullptr;
   vector<Node*> r1;
    vector<Node*> r2;
    bool flag = true;
    preorder(root, n1, r1, flag);
    flag = true;
    preorder(root, n2, r2, flag);
    int sSize = r1.size() > r2.size() ? r2.size() : r1.size();
    int index = 0;
    for(int i=sSize-1; i>=0; i--) {
        if(r1[i] == r2[i]) {
            return r1[i];
        }
    }
    return nullptr;

}