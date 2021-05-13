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
// using dummy starting node -> useful in other linked list problem also, t.c and s.c  is same 
// in this their is actually n node between the nor and adv pointer
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* adv = dummy->next;
    ListNode* nor = dummy;
    
    for(int i=1; i<=n ; i++) adv = adv->next;
    while(adv != nullptr) {
        nor = nor->next;
        adv = adv->next;
    }
    ListNode* temp = nor->next;
    nor->next = nor->next->next;
    delete(temp);
    return dummy->next;        
}

// t.c O(n) && s.c O(1);

// the adv pointer is n node ahead, the nodes between them is (n-1).
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* adv = head;
    ListNode* nor = head;
    ListNode* prev = nullptr;
    
    for(int i=1; i<=n ; i++) adv = adv->next;
    while(adv != nullptr) {
        prev = nor;
        nor = nor->next;
        adv = adv->next;
    }
    if(prev == nullptr) {
        head = nor->next;
        delete(nor);
        return head;
    }
    prev->next = nor->next;
    delete(nor);
    return head;
    
}