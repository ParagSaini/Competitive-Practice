#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int key;
    node* left;
    node* right;
    node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

int Ceil(node* root, int input) 
{ 
    // Base case 
    if (root == nullptr) 
        return -1; 
  
    // We found equal key 
    if (root->key == input) 
        return root->key; 
  
    // If root's key is smaller, ceil must be in right subtree 
    if (root->key < input) 
        return Ceil(root->right, input); 
  
    // Else, either left subtree or root has the ceil value 
    int ceil = Ceil(root->left, input); 
    return (ceil >= input) ? ceil : root->key; 
} 