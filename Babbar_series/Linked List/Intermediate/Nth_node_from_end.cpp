// find the nth node from end of the linked list, in one traversal only.
// LOGIC : Traverse the linked list, and simultaneously storing the data in the array, for desired output simply we have to go to that index which is in O(1);
//Time complexity O(n), space complexity O(n);
int getNthFromLast(Node *head, int n)
{
    vector<int> r;
    Node* start = head;
    while(start != nullptr)
    {
        r.push_back(start->data);
        start = start->next;
    }
    int N = r.size();
    if(N-n < 0)
        return -1;
    else
        return r[N-n];
    
}

// Another Very Good approach , Time complexity O(n) and space complexity O(1);
int getNthFromLast(Node *head, int n)
{
    Node* p = head;
    Node* f = head;
        for(int i=1; i<=n-1; i++)
        {
            f = f->next;
            if(f == nullptr) return -1;
        }
        while(f->next != nullptr)
        {
            p = p->next;
            f = f->next;
        }
        return p->data;
}
