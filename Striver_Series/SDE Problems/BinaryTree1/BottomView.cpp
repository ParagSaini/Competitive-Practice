#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};
vector <int> bottomView(Node *root)
{
    vector<int> result;
    queue<Node*> nodes;
    map<int, int> m;
    queue<int> Hd;
    nodes.push(root);
    Hd.push(0);
    while(!nodes.empty()) {
        // performing the level order traversal and maintaing the latest Hd(Horizontal distance) value.
        Node* temp = nodes.front();
        int curHd = Hd.front();
        Hd.pop();
        nodes.pop();
        m[curHd] = temp->data;
        if(temp->left) {
            nodes.push(temp->left);
            Hd.push(curHd-1);
        }
        if(temp->right) {
            nodes.push(temp->right);
            Hd.push(curHd+1);
        }
    }
    for(auto k : m) {
        result.push_back(k.second);
    }
    return result;
}