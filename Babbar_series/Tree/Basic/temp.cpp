#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Tree {
    public:
    class node {
        public:
        int data;
        node* right;
        node* left;
        node(int d) {
            data = d;
            right = nullptr;
            left = nullptr;
        }
    };
    node* root = nullptr;
};
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
void insert(Tree::node*& root, int val) {
    Tree::node* x = new Tree::node(val);
    if(root == nullptr) {
        root = x;
        return;
    }
    queue<Tree::node*> q;
    q.push(root);
    while(!q.empty()) {
        Tree::node* temp = q.front();
        
        if(temp->left != nullptr) {
            q.push(temp->left);
        } 
        else {
            temp->left = x;
            return;
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
        else {
            temp->right = x;
            return;
        }
        q.pop();
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

void levelorder(Tree::node* root) {
    if(root == nullptr) {
        return;
    }
    queue<Tree::node*> q;
    q.push(root);
    while(!q.empty()) {
        Tree::node* temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left != nullptr) {
            q.push(temp->left);
        } 
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
        q.pop();
    }
}
void preorder(Tree::node* root) {                        // SLR
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Tree::node* root) {                // LSR
    if(root == nullptr) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Tree::node* root) {            // LRS
    if( root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool search(Tree::node*& root, int d) {
    Tree::node*& temp = find(root, d);
    if(temp == nullptr) return false;
    else return true;
}
Tree::node* inorders(Tree::node* rootRight) {                // inorder successor.
    if(rootRight->left == nullptr) {
        return rootRight;
    }
    return inorders(rootRight->left);
}

void printmin(Tree::node* root) {
    Tree::node* start = root;
    if(root == nullptr) return;
    while(start->left != nullptr) {
        start = start->left;
    }
    cout<<"Min value is "<<start->data<<endl;
}
void printmax(Tree::node* root) {
    if(root == nullptr) return;
    Tree::node* start = root;
    while(start->right != nullptr){
        start = start->right;
    }
    cout<<"Max value is "<<start->data<<endl;
}

vector<int> rootData;
void printVector() {
    for(int i=0; i<rootData.size(); i++){
        cout<<rootData[i]<<" ";
    }
}

void printRootToLeaf(Tree::node* root) {
    if(root == nullptr) return;
    rootData.push_back(root->data);
    if(root->right == nullptr && root->left == nullptr) {
        printVector();
        cout<<endl;
    }
    printRootToLeaf(root->left);
    printRootToLeaf(root->right);
    rootData.pop_back();
}
void inorderIt(Tree::node* root) {
    if(root == nullptr ) return;

    stack<Tree::node*> s;
    s.push(root);
    Tree::node* cur = root;

    while(!s.empty()) {
        if(cur == nullptr) {
            cout<<s.top()->data<<" ";
            cur = s.top()->right;
            s.pop();
            if(cur != nullptr) {
                s.push(cur);
            }
        }
        else {
            cur = cur->left;
            if(cur != nullptr) {
                s.push(cur);
            }
        }
    }

}
int main() {
    system("cls");
    Tree t;
    insert(t.root, 8);
    insert(t.root, 5);
    insert(t.root, 10);
    insert(t.root, 7);
    insert(t.root, 20);
    insert(t.root, 16);
    insert(t.root, 25);
    insert(t.root, 30);
    inorderIt(t.root);
    return 0;
}
