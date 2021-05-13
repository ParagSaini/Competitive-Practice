// function of class ll(linked list), therefore head is directly accessible for its function reverse_r
void ll::reverse_r(node* h, node* prev)
{
    if(h == nullptr)
        return;
    node* temp = h->next;
    h->next = prev;
    prev = h;
    head = prev;
    reverse_r(temp,prev);
}