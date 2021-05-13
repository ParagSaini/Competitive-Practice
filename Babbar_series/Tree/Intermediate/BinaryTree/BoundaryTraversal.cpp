void print_left(Node* root, vector<int>& result) {
    root = root->left;
    if(root == nullptr) return;
    while(root->left != nullptr || root->right != nullptr) {
        result.push_back(root->data);
        if(root->left != nullptr) root = root->left;
        else {
         root = root->right;   
        }
    }
}
void print_leaf(Node* root, vector<int>& result) {
    if(root->left == nullptr && root->right == nullptr) {
        result.push_back(root->data);
    }
    
    if(root->left != nullptr) print_leaf(root->left, result);
    if(root->right != nullptr) print_leaf(root->right, result);
}
vector<int> print_right(Node* root) {
    vector<int> temp;
    root = root->right;
    if(root == nullptr) return temp;
    while(root->right != nullptr || root->left != nullptr) {
        temp.push_back(root->data);
        if(root->right != nullptr) root = root->right;
        else {
         root = root->left;   
        }
    }
    return temp;
}
vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int> result;
     result.push_back(root->data);
     print_left(root, result);
     print_leaf(root, result);
     vector<int> temp = print_right(root);
     for(int i=temp.size()-1; i>=0; i--) {
         result.push_back(temp[i]);
     }
     return result;
}