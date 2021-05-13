#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        val = d;
        left = right = nullptr;
    }
};
/* Approach 1: if we traverse the whole tree in inorder fashion we get a sorted Array, and each time we have to give the smallest element we return that from array, 
s.c O(n) & t.c O(1) for next and hasNext operations.

Approach 2 : Do a inorder traversal in iterative way, don't do complete but do it O(h), and continue traversing the array on next operation.
t.c O(1) --average not exactly.
s.c O(h) -- we are maintaing the only one stack
*/

class BSTIterator {
public:
    // vector<int> sortedAr;
    // int next_val = 0;
    // void inorder(TreeNode* root) {
    //     if(!root) return;
    //     inorder(root->left);
    //     sortedAr.push_back(root->val);
    //     inorder(root->right);
    // }
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        // inorder(root);
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    
    /** @return the next smallest number */
    int next() {
        // return sortedAr[next_val++];
        int val = st.top()->val;
        TreeNode* cur = st.top()->right;
        st.pop();
        while(cur) {
            st.push(cur);
            cur = cur->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        // if(next_val < sortedAr.size()) return true;
        // return false;
        if(st.empty()) return false;
        return true;
    }
};
