/*Node * insert(Node * root, int data) {
 // if root is null, means their is no nodes in the tree then simply adding the first node.
    if(root == nullptr)
    {
        Node* temp = new Node(data);
        root = temp;
        return root;
    }

// if the tree is not empty, following below steps.
 LOGIC : Just write the coding steps, as we did it on the paper, jaise hum paper par insertion karte hai tree, mein bas vase hi karna 
    coding mein bhi. 
    Node* start = root;
    while(1)
    {
        if(data > start->data)
        {
            if(start->right == nullptr)
            {
                Node* temp = new Node(data);
                start->right = temp;
                break;
            }
            else
                start = start->right;
        }
        else
        {
            if(start->left == nullptr)
            {
                Node* temp = new Node(data);
                start->left = temp;
                break;
            }
            else
                start = start->left;
        }
    }
    return root;
}
*/
// ANOTHER METHOD : MORE LOGICAL AND EASY 
// Node*& means the reference of the address variable
Node*& find(Node*& root, int& d)
    {
        if(root == nullptr || root->data == d)
            return root;
        if(root->data > d)
            return find(root->left, d);
        else
            return find(root->right, d);
    }
    Node * insert(Node * root, int data) {

        Node*& x = find(root, data);
        if(x == nullptr)       // means data is not present in current tree.
        {
            Node* temp = new Node(data);
            x = temp;
        }
        //else if(x != nullptr)  // means the given data is already in the tree, do nothing.
        //{ }
        return root;
    }