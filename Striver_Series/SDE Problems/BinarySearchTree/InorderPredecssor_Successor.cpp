#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int key;
    Node* left;
    Node* right; 
};

// t.c O(n) && s.c O(H) for recursive calls
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return;
    findPreSuc(root->left, pre, suc, key);
    
    if(suc == nullptr && root->key > key) {
        suc = root;
        return;
    }else if(root->key < key) pre = root;
    
    findPreSuc(root->right, pre, suc, key);
}

// t.c O(2n) && s.c O(n) + recursive stack
void inorder(Node* root, vector<Node*>& arr) {
    if(!root) return;
    inorder(root->left, arr);
    arr.push_back(root);
    inorder(root->right, arr);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    vector<Node*> arr;
    int i;
    inorder(root, arr);
    for(i=0; i<arr.size(); i++) {
        if(arr[i]->key > key) break; // key is not present
        if(arr[i]->key == key) {
            if(i-1 >= 0) pre = arr[i-1];
            if(i+1 < arr.size()) suc = arr[i+1];
            return;
        }
    }
    if(i-1 >= 0) pre = arr[i-1];
    if(i < arr.size()) suc = arr[i];
}