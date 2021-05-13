#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
class TreeNode
{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// much optimised version of earlier method, 
// t.c O(n) && s.c O(max(nodes at level)), much optimised in space terms
void convert(Node *head, TreeNode *&root) {
    if(head == nullptr) return;
    Node* h = head;
    root = new TreeNode(h->data);
    h = h->next;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty() && h != nullptr) {
        TreeNode* cur = q.front();
        q.pop();
        cur->left = new TreeNode(h->data);
        q.push(cur->left);
        h = h->next;
        if(h != nullptr) {
            cur->right = new TreeNode(h->data);
            q.push(cur->right);
            h = h->next;
        }
    }
}

//  t.c O(n) && s.c O(n) + recursive stack
TreeNode* constructTree(vector<int>& nodes,int curInd) {
    if(curInd >= nodes.size()) return nullptr;
    TreeNode* root = new TreeNode(nodes[curInd]);
    root->left = constructTree(nodes, 2 * curInd + 1);
    root->right = constructTree(nodes, 2*curInd+2);
    return root;
}
void convert(Node *head, TreeNode *&root) {
    vector<int> nodes;
    Node* h1 = head;
    while(h1) {
        nodes.push_back(h1->data);
        h1 = h1->next;
    }
    root = constructTree(nodes, 0);
}