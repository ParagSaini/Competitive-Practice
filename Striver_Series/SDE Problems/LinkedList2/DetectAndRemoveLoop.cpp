#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(){}
};

// t.c O(n) && s.c O(1)
void removeLoop(Node* head)
{
    /* good exampt  1->2             // cycle 1-2-1
                    |<-|
                    */
                        
    if(head == nullptr) return;
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    
    do {
        prev = slow;        // this is important
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast && fast != nullptr && fast->next != nullptr);
    
    if(slow != fast) return;
    
    fast = head;
    while(slow != fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = nullptr;
}