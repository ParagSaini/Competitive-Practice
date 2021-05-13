void preorder(Node* root) {
    if(root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right != nullptr) {
            s.push(temp->right);
        }
        if(temp->left != nullptr) {
            s.push(temp->left);
        }
    }
}