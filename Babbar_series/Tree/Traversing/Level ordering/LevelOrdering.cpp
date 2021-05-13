void levelOrder(Node * root) {

        // using the Queue for level ordering traversal
        queue<Node*> root_address;
        root_address.push(root);
        while( !root_address.empty() )
        {
            Node* temp = root_address.front();
            cout<<temp->data <<" ";
    
            if( temp->left != nullptr)
                root_address.push(temp->left);
            if( temp->right != nullptr)
                root_address.push(temp->right);

            root_address.pop();
        }

    }