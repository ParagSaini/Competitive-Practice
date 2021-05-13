// Reversing a Singly Linked List.
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

// if either list is empty or contain only one node, return the head as it is.
    if(head == nullptr ||  (head->next == nullptr) )
        return head;
// if list contain more than 1 node, we follow the below procedure.
    SinglyLinkedListNode* start = head;
    SinglyLinkedListNode* previous_Node = nullptr;
    SinglyLinkedListNode* n_start = head;
    
    while(n_start != nullptr)
    {
        n_start = n_start->next;
        start->next = previous_Node;
        previous_Node = start;
        start = n_start;
    }
// after the while loop execution, start == nullptr, temp and previous_Node contain the address of the last node.

// assigning last node address in head.
    head = previous_Node;

    return head;
    
    
}