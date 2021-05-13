#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
/*
    CIRCULAR DOUBLY LINKED LIST
    Unlike the circular linked list, their is no last pointer, it have a head pointer to access the linked list.
*/

class minmax{                 // for the method MM(Finding min and max)
    public:
    int min;
    int max;
    minmax()
    {
        min = -1;
        max = -1;
    }
    minmax(int m1, int m2)
    {
        min = m1;
        max = m2;
    }
};
class ll{
    class node{
    public:
        int data;
        node* next;
        node* prev;
        node(int d)
        {
            data = d;
            next = this;        // we can write next = nullptr also, but we have make code insertatfront and other functionality carefully.
            prev = this;
        }
    };
    public: 
    node* head = nullptr;
    void insertatfront(int);
    void insertatend(int);
    void del(int);
    bool search(int);
    void print();
    int count(int);
    minmax MM();
};
void ll::insertatfront(int d)
{
    node* temp = new node(d);
    if(head == nullptr)
        head = temp;
    else
    {
        head->prev->next = temp;
        temp->prev = head->prev;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void ll::insertatend(int d)
{
    node* temp = new node(d);
    if(head == nullptr)
        head = temp;
    else
    {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
    }
}
void ll::del(int d)
{
    if(head == nullptr)
        return;

    if(head->next == head)  // only one node in the linked list
    {
        if(head->data == d)
        {
            delete(head);
            head = nullptr;
        }
        return;
    }
    else if(head->data == d) 
    {
        node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete(temp);
    }
    else
    {
        node* start = head->next;
        while(start != head)
        {
            if(start->data == d)
                break;
            else
                start = start->next;
        }
        // start contains the address of the node to be deleted.
        if(start == head)       // do nothing, no such data in our linked list
            return;
        else
        {
            if(start->next == head)     // start is the last node in our LL
            {
                head->prev = start->prev;
                start->prev->next = head;
                delete(start);
            }
            else
            {
                start->prev->next = start->next;
                start->next->prev = start->prev;
                delete(start);
            }
        }   
    }  
}
bool ll::search(int data)
{
    if(head == nullptr)
        return false;
    else
    {
        node* start = head;
        do
        {
            if(start->data == data)
                return true;
            start = start->next;
        } while (start != head);

        return false;
    }   
}
void ll::print()
{
    if(head == nullptr)
        return;
    node* start = head;
    do
    {
        cout<<start->data<<" ";
        start = start->next;
    } while (start != head);
    cout<<endl;
}
int ll::count(int d)
{
    int count = 0;
    node* start = head;
    if(head == nullptr)
        return count;
    do
    {
        if(start->data == d)
            count++;
        start = start->next;
    } while (start != head);
     
    return count;
}
minmax ll::MM()
{
    node* start = head;
    if(head == nullptr)
    {
        minmax temp;
        return temp;
    }
    else
    {
        minmax temp(start->data, start->data);
        start = start->next;
        while(start != head)
        {
            int d = start->data;
            if(d < temp.min)
                temp.min = d;
            else if(d > temp.max)
                temp.max = d;
            start = start->next;
        }
        return temp;
    }
    
}
int main()
{
    system("cls");
    minmax a;
    ll l1;
    l1.insertatfront(1);
    l1.insertatend(2);
    l1.insertatend(3);
    l1.insertatend(4);
    l1.print();
    l1.del(42);
    l1.print();
    l1.del(4);
    l1.print();
    cout<<l1.count(4)<<" "<<l1.count(3)<<endl;
    cout<<l1.search(32)<<" "<<l1.search(3)<<" "<<l1.search(4);
    a = l1.MM();
    cout<<" "<<a.min<<" "<<a.max<<" ";
    return 0;
}