void inorder(Node* root, Node*& head) {
    if(root == nullptr) return;
    inorder(root->left, head);
    if(head != nullptr) {
        head->right = root;
        root->left = head;
        head = head->right;
    }else {
        head = root;
    }
    inorder(root->right, head);
}
Node * bToDLL(Node *root)
{
    if(root == nullptr) return nullptr;
    Node* head = nullptr;
    inorder(root, head);
    // we can do RSL( reverse of inorder) also to avoid the below for loop
    // getting the head of the linked list.
    while(head->left != nullptr) {
        head = head->left;
    }
    return head;
}

