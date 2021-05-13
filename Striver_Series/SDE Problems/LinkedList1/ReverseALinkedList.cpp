class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int d) {
        val = d;
        next =nullptr;
    }
};


ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* nextNode = nullptr;
    while(cur) {
        nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    return prev;
}