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

// t.c O(n + n - k) && s.c O(1)
ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr) return head;
    
    int len = 1;
    ListNode* h = head;
    ListNode* tail = head;
    
    while(tail->next) {
        len++;
        tail = tail->next; 
    }
    
    int node_from_start = len - (k % len);
    
    for(int i=1; i<node_from_start; i++) {
        h = h->next;
    }
    
    tail->next = head;
    head = h->next;
    h->next = nullptr;
    return head;        
}