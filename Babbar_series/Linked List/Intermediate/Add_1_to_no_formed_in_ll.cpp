// Time complexity = O(n), space complexity = O(1),
Node* reverse(Node* head) {
    
    if(head == nullptr ||  (head->next == nullptr) )
        return head;
    Node* start = head;
    Node* previous_Node = nullptr;
    Node* n_start = head;
    
    while(n_start != nullptr)
    {
        n_start = n_start->next;
        start->next = previous_Node;
        previous_Node = start;
        start = n_start;
    }
    head = previous_Node;
    return head;
}
Node *addOne(Node *head)
{
    head = reverse(head);        // reversing the linked list.
    int carry = 0;
    Node* start = head;
    
    if(start->data < 9)      // last digit is less than 9.
    {
        start->data = start->data + 1;
        return reverse(head);
    }
    
    while(start != nullptr)
    {
        if(start->data == 9)
        {
            start->data = 0;
            carry = 1;
        }
        else
        {
            start->data = start->data + 1;
            carry = 0;
            break;
        }
        start = start->next;
    }
    head = reverse(head);     // again reversing the linked list.
    if(carry)           // adding '1' to our starting of linked list.
    {
        Node* temp = new Node;
        temp->data = 1;
        temp->next = head;
        head = temp;
    }
    return head;
}