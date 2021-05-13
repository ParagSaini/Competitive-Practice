#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
};
// optimal
// t.c O(n) && s.c O(n)
void topView(struct Node *root)
{
    unordered_map<int, int> tpView;
    int minWidth = INT_MAX;
    int maxWidth = INT_MIN;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        Node* curNode = q.front().first;
        int width = q.front().second;
        q.pop();
        
        if(!tpView.count(width)) {
            tpView[width] = curNode->data;
            minWidth = min(minWidth, width);
            maxWidth = max(maxWidth, width);
        }
        if(curNode->left) q.push({curNode->left, width-1});
        if(curNode->right) q.push({curNode->right, width+1});
    }
    for(int i=minWidth; i<=maxWidth; i++) cout<<tpView[i]<<" ";
}

// t.c O(nlogn) && s.c O(n)
void topView(struct Node *root)
{
    map<int, int> tpView;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        Node* curNode = q.front().first;
        int width = q.front().second;
        q.pop();
        
        if(!tpView.count(width)) tpView[width] = curNode->data;
        if(curNode->left) q.push({curNode->left, width-1});
        if(curNode->right) q.push({curNode->right, width+1});
    }
    for(auto it : tpView) cout<<it.second<<" ";
}
