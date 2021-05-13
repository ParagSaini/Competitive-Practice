Tree::node*& find(Tree::node*& root, int d) {
    if(root == nullptr) {
        return root;
    } 
    else if(root->data == d) {
        return root;
    }
    else if(d > root->data) {
        return find(root->right, d);
    }
    else {
        return find(root->left, d);
    }
}

Tree::node*& iop(Tree::node*& Rootleft) {
    if(Rootleft->right == nullptr) {
        return Rootleft;
    }
    else {
        return iop(Rootleft->right);
    }
}

void deletion(Tree::node*& root, int d) {
    Tree::node*& temp = find(root, d);
    if(temp == nullptr) {                // data is not present in our tree.
        // do nothing 
    }   
    else if(temp->right == nullptr && temp->left == nullptr) {           // no child case
        temp = nullptr;
    }
    else if(temp->right == nullptr && temp->left != nullptr) {        // one child remove case
        Tree::node* x = temp;
        temp = temp->left;
        delete(x);
    }
    else if(temp->right != nullptr && temp->left == nullptr) {             // one child remove case
        Tree::node* x = temp;
        temp = temp->right;
        delete(x);
    }
    else {                                                                       // two child remove case
        Tree::node*& x = iop(root->left);
        swap(x->data, temp->data);
        if(x->left == nullptr){                  // x is a leaf node
            x = nullptr;
        }
        else {
            Tree::node* y = x;
            x = x->left;
            delete(y);
        }
    }
}