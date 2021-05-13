#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node* left;
    Node* next;
    Node* right;
    Node(int d) {
        val = d;
        left = right = next = nullptr;
    }
};

Node* connect(Node* root) {
    if(!root) return root;
    Node* firstNodeAtLevel = root;
    
    // break if it is a leaf node.
    while(firstNodeAtLevel->left != nullptr) {
        Node* cur = firstNodeAtLevel;
        while(cur) {
            // by the way, no need to check the cur->left, as the given tree is a perfect tree and cur can never be leaf node.
            if(cur->left) cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        firstNodeAtLevel = firstNodeAtLevel->left;
    }
    return root;
}