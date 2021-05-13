#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int d){
        data = d;
        next = nullptr;
    }
};

// t.c O(n) && s.c O(1)
void reverse(ListNode* h1, ListNode* h2) {
    ListNode* cur = h1;
    ListNode* prev = nullptr;
    ListNode* next_node = nullptr;
    ListNode* end = h2->next;
    while(cur != end) {
        next_node = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node;
    }
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr || k == 1) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* h1 = head;
    ListNode* h2 = head;
    ListNode* prev = dummy;
    ListNode* next_node = nullptr;
    
    while(h2) {
        for(int i=1; i<k && h2 != nullptr; i++) {
            h2 = h2->next;
        }
        if(h2 == nullptr) break;
        next_node = h2->next;
        reverse(h1, h2);
        if(dummy->next == head) dummy->next = h2;
        prev->next = h2;
        h1->next = next_node;
        prev = h1;
        h1 = h1->next;
        h2 = h1;
        
    }
    return dummy->next;
}