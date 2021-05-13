int height(Node* root) {
/* LOGIC : using the recursion to find the height of left and right tree, and whichever is greater, return that height
Basically, the height of tree = 1 + max(height of subtree), and using recursion to find the height of subtree */

    // if their is no children of a root node, return 0(means height of that node is '0')
        if(root->left == nullptr && root->right == nullptr)
            return 0;

        int height_left = 0;
        int height_right = 0;
    
        if(root->right != nullptr)
            height_right = 1 + height(root->right);

        if(root->left != nullptr)
            height_left = 1 + height(root->left);
            
    // returning the greater height
        return (height_right > height_left ? height_right : height_left);
    }