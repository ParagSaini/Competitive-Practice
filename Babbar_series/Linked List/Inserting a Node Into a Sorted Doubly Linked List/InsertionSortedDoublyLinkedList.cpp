DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {

// if list is empty, insertAtfront and return head
    if(head == nullptr)
    {
        DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
        head = temp;
        return head;
    }

    DoublyLinkedListNode* start = head;
    // previous_node contain the address of previous node of inserted node
    DoublyLinkedListNode* previous_node = nullptr;
    // next_node contain the address of next node of inserted node
    DoublyLinkedListNode* next_node = nullptr;

// if the data is <= first node data, insert new node at front.
    if(head->data >= data)
    {
        DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
        temp->next = start;
        start->prev = temp;
        head = temp;
        return head;
    }

// After the while loop start contains the position where should our new node will inserted.
    while( (start->data <= data) && (start->next != nullptr) )
        start = start->next;
// it is possible that the given data is greater than every node, so we insert it at the end of the linked list  
    if(start->next == nullptr && start->data < data)
    {
        DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
        start->next = temp;
        temp->prev = start;
        return head;
    } 
// below lines are only executed when the given data to be inserted in between two nodes
    next_node = start;
    previous_node = start->prev;
    DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
    previous_node->next = temp;
    temp->prev = previous_node;
    next_node->prev = temp;
    temp->next = next_node;

    return head;


}
