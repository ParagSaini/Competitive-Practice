class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) : val(d), next(nullptr) {}
};

// t.c O(max(m, n)) && s.c O(max(m, n));
// the numbers given are already in reverse order, so no need to reverse them.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* result = dummy;
    ListNode* head1 = l1;
    ListNode* head2 = l2;
    int carry = 0;
    
    while(head1 || head2) {
        int x = (head1 != nullptr) ? head1->val : 0;
        int y = (head2 != nullptr) ? head2->val : 0;
        
        int val = x + y + carry;
        carry = val / 10;
        val = val % 10;
        ListNode* new_node = new ListNode(val);
        dummy->next = new_node;
        dummy = dummy->next;
        
        if(head1 != nullptr) head1 = head1->next;
        if(head2 != nullptr) head2 = head2->next;
    }
    
    if(carry != 0) {
        dummy->next = new ListNode(1);
    }

    return result->next;       
}