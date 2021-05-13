class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) : val(d), next(nullptr) {}
};

// adding all the nodes in the sorted order in List Number 1 i.e l1
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;
    
    ListNode* head1 = l1;
    ListNode* head2 = l2;
    ListNode* prev1 = nullptr;
    
    while(head1 && head2) {
        if(head1->val <= head2->val) {
            prev1 = head1;
            head1 = head1->next;
        }
        else {
            if(prev1 != nullptr)  prev1->next = head2;
            prev1 = head2;
            head2 = head2->next;
            prev1->next = head1;
        }
    }
    if(head2 != nullptr) prev1->next = head2;
    if(l1->val <= l2->val) return l1;
    return l2;
}