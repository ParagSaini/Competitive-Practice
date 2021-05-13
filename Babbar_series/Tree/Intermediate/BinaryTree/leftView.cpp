void Helper(Node* root, int level, int& count) {
    if(root == nullptr) return;
    if(level > count) {
        cout<<root->data<<" ";
        count++;
    }
    Helper(root->left, level+1, count);
    Helper(root->right, level+1, count);
}
void leftView(Node *root)
{
    int count = 0;
    Helper(root, 1, count);
}

//                  OR
// using level order traversal.
void leftView(Node* root) {
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int k = q.size();
        cout<<q.front()->data<<" ";
        while(k) {
            Node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            k--;
        }
    }
}