#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) : val(d), next(nullptr) {}
};

// most optimal solution 
// see video if unclear, take me forward, clever way 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr) return nullptr;
    ListNode* a = headA;
    ListNode* b = headB;
    
    while(a != b) {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
    }
    return a;
}

// t.c O(max(m, n) + m + n) && s.c O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr) return nullptr;
    ListNode* h1 = headA;
    ListNode* slow = headA;
    ListNode* fast = headA;
    ListNode* tail_node = nullptr;
    
    while(h1->next != nullptr) h1 = h1->next;
    
    tail_node = h1;
    tail_node->next = headB;

    // this is important, initially slow and fast are same
    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast && fast != nullptr && fast->next != nullptr);
    
    if(fast != slow) {
        tail_node->next = nullptr;   // maintaining the original structure
        return nullptr;
    }
    fast = headA;
    while(fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    tail_node->next = nullptr;  // maintaining the original structure
    return slow;   
}

// t.c O(m+n) && s.c O(max(m,n))
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> address;
    ListNode* h1 = headA;
    ListNode* h2 = headB;
    while(h1) {
        address.insert(h1);
        h1 = h1->next;
    }
    while(h2) {
        if(address.count(h2)) return h2;
        h2 = h2->next;
    }
    return nullptr;
}