#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

void inorder(Node* root, vector<int>& arr) {
    if(!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
vector<int> merge(Node *root1, Node *root2)
{
   vector<int> arr1, arr2, result;
   inorder(root1, arr1);
   inorder(root2, arr2);
   int s1 = 0, s2 = 0;
    while(s1 < arr1.size() && s2 < arr2.size()) {
        if(arr1[s1] < arr2[s2]) result.push_back(arr1[s1++]);
        else result.push_back(arr2[s2++]);
    }
    while(s1 < arr1.size()) result.push_back(arr1[s1++]);
    while(s2 < arr2.size()) result.push_back(arr2[s2++]);
    return result;
}