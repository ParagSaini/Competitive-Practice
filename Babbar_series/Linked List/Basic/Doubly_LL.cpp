#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
/*
    DOUBLY LINKED LIST
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
            next = nullptr;
            prev = nullptr;
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
    void pair(int);
    minmax MM();
};
void ll::pair(int k)
{
    if(head == nullptr || head->next == nullptr)
        return;
    node* start = head;
    node* last = head;
    while(last->next != nullptr)
        last = last->next;
    
    while(start != last)
    {
        int x = start->data + last->data;
        if(x == k)
        {
            cout<<start->data<<" "<<last->data<<endl;
            last = last->prev;
        }
        else if(x > k)
            last = last->prev;
        else
            start = start->next;   
    }
}
void ll::insertatfront(int d)
{
    node* temp = new node(d);
    if(head == nullptr)
        head = temp;
    else
    {
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
        node* start = head;
        while(start->next != nullptr)
            start = start->next;

        start->next = temp;
        temp->prev = start;
    }
}
void ll::del(int d)
{
    if(head == nullptr)
        return;

    else if(head->data == d)
    {
        node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete(temp);
    }
    else
    {
        node* start = head->next;
        // node* prev = head;   No need of previous in DLL.
        while(start != nullptr)
        {
            if(start->data == d)
                break;
            else
                start = start->next;
        }
        // start contains the address of the node to be deleted.
        if(start == nullptr)       // do nothing
            return;
        else
        {
            if(start->next == nullptr)     // start is the last node in our LL
            {
                start->prev->next = nullptr;
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
        while(start != nullptr)
        {
            if(start->data == data)
                return true;
            else
                start = start->next;
        }
        return false;
    }   
}
void ll::print()
{
    if(head == nullptr)
        return;
    node* start = head;
    while(start != nullptr)
    {
        cout<<start->data<<" ";
        start = start->next;
    }
}
int ll::count(int d)
{
    int count = 0;
    node* start = head;
    if(head == nullptr)
        return count;
    while(start != nullptr)
    {
        if(start->data == d)
            count++;
        start = start->next;
    } 
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
        while(start != nullptr)
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
    l1.insertatend(1);
    l1.insertatend(2);
    l1.insertatend(4);
    l1.insertatend(5);
    l1.insertatend(6);
    l1.insertatend(8);
    l1.insertatend(9);
    int k = 9;
    l1.pair(k);
    return 0;
}