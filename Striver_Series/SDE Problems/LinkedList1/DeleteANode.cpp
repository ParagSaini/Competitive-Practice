#include<bits/stdc++.h>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) {
        val = d;
        next = nullptr;
    }
};

// the address of node to be deleted is given
// O(1) approach

void deleteNode(ListNode* node) {
    ListNode* cur = node;

    cur->val = cur->next->val;
    ListNode* todelete = cur->next;
    cur->next = cur->next->next;
    delete(todelete);
}

// O(n) approach
void deleteNode(ListNode* node) {
    ListNode* prev = nullptr;
    ListNode* cur = node;
    while(cur->next != nullptr) {
        cur->val = cur->next->val;
        prev = cur;
        cur = cur->next;
    }
    delete(cur);
    prev->next = nullptr;   
}
