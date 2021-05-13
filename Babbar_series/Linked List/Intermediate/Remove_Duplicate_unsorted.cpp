#include<iostream>
#include<unordered_set>
using namespace std;

Node * removeDuplicates( Node *head) 
{
    unordered_set<int> s;
    if(head == nullptr || head->next == nullptr)
        return head;
        
    Node* start = head->next;
    Node* prev = head;
    s.insert(prev->data);
    while(start != nullptr)
    {
        if(s.count(start->data))
        {
            prev->next = start->next;
            delete(start);
            start = prev->next;
        }
        else
        {
            s.insert(start->data);
            prev = start;
            start = start->next;
        }
    }
    return head;
}
