vector<int> rootData;
void printVector() {
    for(int i=0; i<rootData.size(); i++){
        cout<<rootData[i]<<" ";
    }
}

void printRootToLeaf(Tree::node* root) {
    if(root == nullptr) return;
    rootData.push_back(root->data);
    if(root->right == nullptr && root->left == nullptr) {
        printVector();
        cout<<endl;
    }
    printRootToLeaf(root->left);
    printRootToLeaf(root->right);
    rootData.pop_back();
}