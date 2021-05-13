#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
class minmax{                 // for the method MM
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
        node(int d)
        {
            data = d;
            next = nullptr;
        }
    };
    public: 
    node* head = nullptr;
    bool search(int);
    void insertatfront(int);
    void del(int);
    void print();
    int count(int);
    minmax MM();
    void reverse();
    void reverse_r(node*, node*);
};
void ll::reverse()
{
    // iteratively
    if(head == nullptr || head->next == nullptr)
        return;
    else
    {
        node* prev = nullptr;
        node* start = head;
        node* nstart = head;
        while(nstart != nullptr)
        {
            nstart = nstart->next;
            start->next = prev;
            prev = start;
            start = nstart;
        }
        head = prev;
    }
}
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
minmax ll::MM()
{
    node* start = head;
    if(start == nullptr)
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
int ll::count(int d)
{
    int count = 0;
    node* start = head;
    while(start != nullptr)
    {
        if(start->data == d)
            count++;
        start = start->next;
    }
    return count;
}
void ll::print()
{
    node* start = head;
    while(start != nullptr)
    {
        cout<<start->data<<" ";
        start = start->next;
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
        delete(temp);
    }
    else
    {
        node* start = head->next;
        node* prev = head;
        while(start != nullptr)
        {
            if(start->data == d)
                break;
            else
            {
                prev = start;
                start = start->next;
            } 
        }
        if(start == nullptr)       // do nothing
            return;
        else
        {
            prev->next = start->next;
            delete(start);
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
            start = start->next;            
        }
        return false;
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
        head = temp;
    }
    
}
int main()
{
    system("cls");
    minmax a;
    ll l1,l2;
    l1.insertatfront(1);
    l1.insertatfront(2);
    l1.insertatfront(3);
    l2.insertatfront(1);
    l2.insertatfront(2);
    l2.insertatfront(3);
    l1.print();
    cout<<endl;
    l2.print();
    return 0;
}