// link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1#
// t.c O(n) && s.c O(n)
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};
void connect(Node *p)
{
    if(p == nullptr) return;
    queue<Node*> q;
    Node* prev = nullptr;
    q.push(p);
    
    while(!q.empty()) {
        int s = q.size();
        // prev = q.front();
        while(s--) {
            Node* front = q.front();
            q.pop();
            if(prev == nullptr) prev = front;
            else {
                prev->nextRight = front;
            }
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            prev = front;
        }
        prev->nextRight = nullptr;
        prev = nullptr;
    }
}