DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {

    // if list is empty return head;
    if(head == nullptr)
        return head;

    /* finding the tail of the doulbly linked list and just swap the head and tail.
    and on each node swapping the prev, and next pointer also. */
    DoublyLinkedListNode* tail = head;
    while(tail->next != nullptr)
    {
        swap(tail->next, tail->prev);
        tail = tail->prev;   // tail->prev because, after swapping the next and prev pointer are interchanged.        
    }
    // 'while' loop doesn't change the pointers of last node, so we do it explicitly.
    swap(tail->next, tail->prev);
    head = tail;
    return head;


}