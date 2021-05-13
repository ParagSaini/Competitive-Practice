// This map DS used here is different from unordered_map, in map we can map the keyvalue and data in either ascending or descending value according to keyvalue.
// like map<int, int, greater<int>> m;   means 'm' map map int key to a int value in a descending order of key.
void topView(Node* root) {
        map<int,int> hd_to_value;      // a ascending order map which maps key value to data in the node.
        queue<Node*> root_address;     // queue for level ordering traversal
        queue<int> hd;            // another queue for storing the horizontal distance(hd) of a node.

        hd.push(0);               
        root_address.push(root);

        while( !root_address.empty() )         // level ordering traversal
        {
            Node* temp = root_address.front();

            if(!hd_to_value.count(hd.front()))        // checking is the map already contain the given hd value, if not then map that value to node data.
            {
                hd_to_value[hd.front()] = temp->data;
            }
            if( temp->left != nullptr)
            {
                root_address.push(temp->left);
                hd.push(hd.front()-1);
            }
            if( temp->right != nullptr)
            {
                root_address.push(temp->right);
                hd.push(hd.front()+1);
            }

            root_address.pop();
            hd.pop();
        }
        for(auto k:hd_to_value)
        {
            cout<<k.second<<" ";
        }
    }