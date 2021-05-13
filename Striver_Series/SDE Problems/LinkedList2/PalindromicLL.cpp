#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) : val(d), next(nullptr) {}
};

// t.c O(n) && s.c O(1)
ListNode* reverse(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* next_node = nullptr;
    while(cur) {
        next_node = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_node;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    // finding the middle node
    while(fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the linked list from middle node
    prev->next = reverse(slow);
    slow = prev->next;
    fast = head;
    while(fast != prev->next) {
        if(fast->val != slow->val) return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

// t.c O(n) && s.c O(n)
bool isPalindrome(ListNode* head) {
    vector<int> arr;
    ListNode* h = head;
    while(h) {
        arr.push_back(h->val);
        h = h->next;
    }
    int s = 0, e = arr.size()-1;
    while(s < e) {
        if(arr[s++] != arr[e--]) return false;
    }
    return true;
}