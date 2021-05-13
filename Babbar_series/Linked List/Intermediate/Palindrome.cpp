int palindrome(node* head)
{
  if(head == nullptr || head->next == nullptr)        // either list is empty or contain only one element.
    return 1;

  node* fast = head;                  // move two steps
  node* slow = head;                  // move one step at a time, contain mid node at end of below loop.
  node* prev = head;

  //Example : head->a->b->c->d->c->b->a->Null           odd no. of elements
  // head->a->b->c->c->b->a->Null                        even no. of elements
  while(fast->next != nullptr && fast->next->next != nullptr)
  {
    fast = fast->next->next;
    slow = slow->next;
    prev->next = slow->next;
    slow->next = head;
    head = slow;
    slow = prev;
  }
  // After the while loop, prev points to node 'a' in the middle
  // head->d->c->b->a->c->b->a->Null         odd ex
  // head->c->b->a->c->b->a->Null          even ex          
  node* start1 = head;
  node* start2 = slow->next;

  if(fast->next == nullptr)              // odd no. of elements 
    start1 = start1->next;           // skipping the middle element in our original linked list.
  
  // comparing the two linked list
  while(start1 != prev->next)         // we can also write start2 != nullptr
  {
    if(start1->data != start2->data)
      return 0;
    start1 = start1->next;
    start2 = start2->next;
  }
  return 1;
  
}