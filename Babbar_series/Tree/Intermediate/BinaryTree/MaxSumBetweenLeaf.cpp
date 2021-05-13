include<bits/stdc++.h>
using namespace std;

int Helper(Node* root, int& maxi) {
    if(root->left == nullptr && root->right == nullptr) return root->data;
    if(root->left != nullptr && root->right == nullptr) return Helper(root->left, maxi) + root->data;
    if(root->left == nullptr && root->right != nullptr) return Helper(root->right, maxi) + root->data;

    int l = Helper(root->left, maxi);
    int r = Helper(root->right, maxi);
    
    if(l+r+root->data > maxi) maxi = l+r+root->data;
    return max(l,r) + root->data;
}
int maxPathSum(Node* root)
{ 
    // code here 
    int maxi = INT_MIN;
Helper(root, maxi);
    return maxi;
}
