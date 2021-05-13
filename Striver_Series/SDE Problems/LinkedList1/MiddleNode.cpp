#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) {
        val = d;
        next =nullptr;
    }
};
// t.c O(n) && s.c O(1)
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// t.c O(n) && s.c O(n) 
ListNode* middleNode(ListNode* head) {
    vector<ListNode*> list;
    ListNode* cur = head;
    while(cur) {
        list.push_back(cur);
        cur = cur->next;
    }
    return list[list.size()/2];
}