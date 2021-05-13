class Node {
    public:
    int data;
    Node* next;
    Node* bottom;
    Node(int d) : data(d), next(nullptr) {}
};

// t.c O(n * m) , s.c O(1)
// Merging the two sorted Linked List
Node* Merge(Node* first, Node* sec) {
    Node* head1 = first;
    Node* head2 = sec;
    Node* prev1 = nullptr;
    
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            prev1 = head1;
            head1 = head1->bottom;
        }
        else {
            if(prev1 != nullptr)  prev1->bottom = head2;
            prev1 = head2;
            head2 = head2->bottom;
            prev1->bottom = head1;
        }
    }
    if(head2 != nullptr) prev1->bottom = head2;
    if(first->data <= sec->data) return first;
    return sec;
}

Node *flatten(Node *root)
{
   if(root == nullptr || root->next == nullptr) return root;
   Node* result = nullptr;
   Node* h1 = root;
   Node* h2 = root->next;
   while(h2) {
       Node* next_ll = h2->next;
       if(h1->data <= h2->data) result = h1;
       else result = h2;
       h1 = Merge(h1, h2);
       h2 = next_ll;
   }
   return result;
   
}
