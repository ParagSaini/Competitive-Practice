#include<bits/stdc++.h>
using namespace std;
class A {
    public:
    int a, b;
    A(int x, int y) {
        a = x;
        b = y;
    }
};
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
bool isSame(Node* root1, Node* root2) {
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 == nullptr || root2 == nullptr) return false;
    if(root1->data != root2->data) return false;
    return (isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
}
void isSubtree(Node* root1, Node* root2, bool& count) {
    if(root1 == nullptr) return;
    if(!count) {
        if(root1->data == root2->data) {
            count = isSame(root1, root2);
        }
    }
    isSubtree(root1->left, root2, count);
    isSubtree(root1->right, root2, count);
}
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
int main(){
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7);
    // Node* root2 = new Node(3); 
    // root2->left = new Node(6); 
    // // root2->right = new Node(6);
    // bool count = false;
    // isSubtree(root, root2, count);
    // cout<<count;
    preorder(root);
    return 0;
}
