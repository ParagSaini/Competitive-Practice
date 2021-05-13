#include<iostream>
#include<queue>
using namespace std;

class avlTree
{
public:
    class node
    {
    public:
        int val;
        int ht;
        node* left;
        node* right;
        node(int d)
        {
            val = d;
            ht = 0;
            left = nullptr;
            right = nullptr;
        }

    };
    node* root = nullptr;

};
int height(avlTree::node*& root)
{
    if(root == nullptr)
        return -1;
    return root->ht;
}
void updateheight(avlTree::node*& cur)
{
    cur->ht = 1 + max(height(cur->left), height(cur->right));
}
void rotateleft(avlTree::node*& cur)
{
    avlTree::node* x = cur;
    avlTree::node* y = cur->right;
    cur = y;

    x->right = y->left;
    y->left = x;
    
    updateheight(x);
    updateheight(y);
}
void rotateright(avlTree::node*& cur)
{
    avlTree::node* x = cur;
    avlTree::node* y = cur->left;
    cur = y;
    
    x->left = y->right;
    y->right = x;    

    updateheight(x);
    updateheight(y);
}
void rotateleftright(avlTree::node*& cur)
{
    avlTree::node* x = cur->left;
    avlTree::node* y = x->right;
    
    cur->left = y;
    x->right = y->left;
    y->left = x;
    
    updateheight(x);
    updateheight(y);
    
    rotateright(cur);
}
void rotaterightleft(avlTree::node*& cur)
{
    avlTree::node* x = cur->right;
    avlTree::node* y = x->left;
    
    cur->right = y;
    x->left = y->right;
    y->right = x;
    
    updateheight(x);
    updateheight(y);
    
    rotateleft(cur);
}

void ensurebalance(avlTree::node*& cur)
{
    int balance = height(cur->right) - height(cur->left);
    
    if(balance == -2)    // slant to left side
    {
        int l_balance = height(cur->left->right) - height(cur->left->left);
        if(l_balance == -1)
        {
            rotateright(cur);         // stick slant to left side.
        }
        else // l_balance == 1
            rotateleftright(cur);           // elbow
    }
    
    else if(balance == 2)              // slant to right side.
    {
        int r_balance = height(cur->right->right) - height(cur->right->left);
        if(r_balance == 1)              // stick, slant to right side.
            rotateleft(cur);
        else
            rotaterightleft(cur);             // elbow.
    }
}
void in(avlTree::node*& root, int val)
{
    if(root == nullptr )          // || root->val == val
    {
        avlTree::node* temp = new avlTree::node(val);
        root = temp;
        return;
    }
    else if(root->val < val)
    {
        in(root->right, val);
    }
    else
    {
        in(root->left, val);
    }
    
    updateheight(root);
    
    int balancefactor = height(root->right) - height(root->left);   // back tracking.
    
    if(balancefactor == 2 || balancefactor == -2)
    {
        ensurebalance(root);    
    }
        
}
avlTree::node * insert(avlTree::node *& root,int val)
{
    in(root, val);
    return root;
  
}
void levelOrder(avlTree::node* root) {

        // using the Queue for level ordering traversal
        queue<avlTree::node*> root_address;
        root_address.push(root);
        while( !root_address.empty() )
        {
            avlTree::node* temp = root_address.front();
            cout<<temp->val <<" ";
    
            if( temp->left != nullptr)
                root_address.push(temp->left);
            if( temp->right != nullptr)
                root_address.push(temp->right);

            root_address.pop();
        }

    }
int main()
{
    system("cls");
    avlTree t;
    insert(t.root, 1);
    insert(t.root, 2);
    insert(t.root, 3);
    insert(t.root, 4); 
    insert(t.root, 5); 
    levelOrder(t.root);
    return 0;
}