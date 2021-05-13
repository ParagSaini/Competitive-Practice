#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* random;
    Node* next;
    Node(int v){val = v; next = nullptr;}
};

// t.c O(n) && s.c O(1)
Node* copyRandomList(Node* head) {
    if(head == nullptr) return nullptr;
    Node* h1 = head;
    Node* dummy = new Node(0);
    Node* h2 = dummy;
    
    while(h1) {
        Node* clone = new Node(h1->val);
        Node* next_node = h1->next;  // donot care much about nullptrs, no need to take reference for the null nodes.
        h1->next = clone;
        clone->next = next_node;
        h1 = next_node;
    }
    h1 = head;
    while(h1) {
        Node* rand = h1->random;
        if(rand == nullptr) h1->next->random = nullptr;
        else h1->next->random = rand->next;     //(rand->next) actually contains the address of the clone node
        h1 = h1->next->next;
    }
    // restore the original linked lists
    h1 = head;
    while(h1) {
        Node* clone = h1->next;
        h2->next = clone;
        h1->next = h1->next->next;
        h1 = h1->next;
        h2 = h2->next;
    }
    return (dummy->next);
    
}
// t.c O(n) && s.c O(n)
Node* copyRandomList(Node* head) {
    Node* dummy = new Node(0);
    Node* h1 = head;
    Node* h2 = dummy;
    unordered_map<Node*, Node*> CloneNodes;
    while(h1) {
        h2->next = new Node(h1->val);
        CloneNodes[h1] = h2->next;
        h2 = h2->next;
        h1 = h1->next;
    }
    h1 = head;
    h2 = dummy->next;
    
    while(h1) {
        if(h1->random == nullptr) h2->random = nullptr;
        else h2->random = CloneNodes[h1->random];
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return (dummy->next);
}