#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if(node == nullptr) return nullptr;
    if(node->neighbors.size() == 0) {
        Node* head = new Node(node->val);
        return head;
    }
    // using the bfs. 
    // clone Nodes Map is also taking care of the visitedNodes, so that we can't repeat the visited nodes.
    unordered_map<int, Node*> cloneNodesMap;
    queue<Node*> q;
    q.push(node);
    Node* head = new Node(node->val);
    cloneNodesMap[node->val] = head;

    while(!q.empty()) {
        Node* cur = q.front();
        Node* clone_cur = cloneNodesMap[cur->val];
        vector<Node*> cloneCurNeighbors;
        q.pop();
        
        for(auto neighbor : cur->neighbors) {
            if(!cloneNodesMap.count(neighbor->val)) {
                Node* newNode = new Node(neighbor->val);
                cloneNodesMap[newNode->val] = newNode;
                q.push(neighbor);
            }
            cloneCurNeighbors.push_back(cloneNodesMap[neighbor->val]);
        }
        clone_cur->neighbors = cloneCurNeighbors;
        
    }

    return head;
}