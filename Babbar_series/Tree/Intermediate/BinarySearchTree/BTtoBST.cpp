void inorder(Node* root, vector<int>& ar, vector<Node*>& address) {
    if(root == nullptr) return;
    inorder(root->left, ar, address);
    ar.push_back(root->data);
    address.push_back(root);
    inorder(root->right, ar, address);
}
Node *binaryTreeToBST (Node *root)
{
    if(root == nullptr) return root;
    vector<int> ar;
    vector<Node*> address;
    inorder(root, ar, address);
    vector<int> sortedar = ar;
    sort(sortedar.begin(), sortedar.end());
    
    for(int i=0; i<ar.size(); i++) {
        address[i]->data = sortedar[i];
    }
    return root;
}