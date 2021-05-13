#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) : val(d), next(nullptr) {}
};

// t.c O(n) && s.c O(1) 

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;   
}

// tc O(n) && s.c O(n) 
bool hasCycle(ListNode *head) {
    ListNode* h = head;
    unordered_set<ListNode*> repeat;
    while(h) {
        if(repeat.count(h)) return true;
        repeat.insert(h);
        h = h->next;
    }
    return false;
}