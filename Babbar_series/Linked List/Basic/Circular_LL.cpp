#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
/* IN THE CIRCULAR LINKED LIST, IN PLACE OF last WE HAVE LAST NODE POINTER, WHICH POINT TO LAST NODE IN 
OUT CLL, WE DON'T HAVE last IN CLL BECAUSE USING OF LAST NODE POINTER MAKES OUR INSERTION AT END, BEGINNING OPERATION
IN O(1)..
THE REST THINGS ARE SAME FOR CLL AS IN TEH SLL(SINGLY LINKED LIST)
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
        node(int d)
        {
            data = d;
            next = nullptr;
        }
    };
    public: 
    node* last = nullptr;
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
    if(last == nullptr)
    {
        last = temp;
        last->next = temp;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
}
void ll::insertatend(int d)
{
    node* temp = new node(d);
    if(last == nullptr)
    {
        last = temp;
        last->next = temp;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;                 // only additional we wrote for insertatend as compare to insertatfront.
    }
}
void ll::del(int d)
{
    if(last == nullptr)
        return;
    if(last->next == last)          // only one node in the linked list
    {
        if(last->data == d)
        {
            delete(last);
            last = nullptr;
        }
        return;           
    }
    else if(last->data == d)             // deletion at end.
    {
        node* start = last;
        while(start->next != last)
            start = start->next;
        
        start->next = last->next;
        delete(last);
        last = start;
        
    }
    else
    {
        node* start = last->next;
        node* prev = last;
        while(start != last)
        {
            if(start->data == d)
                break;
            else
            {
                prev = start;
                start = start->next;
            } 
        }
        if(start == last)       // do nothing, no such data in our linked list.
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
    if(last == nullptr)
        return false;
    else
    {
        node* start = last;
        do{
            if(start->data == data)
                return true;
            start = start->next;
        }while(start != last);

        return false;
    }   
}
void ll::print()
{
    if(last == nullptr)
        return;
    node* start = last->next;
    if(start == last)
    {
        cout<<start->data<<" ";
        return;
    }
    else
    {
        while(start != last)
        {
            cout<<start->data<<" ";
            start = start->next;
        }
        cout<<start->data<<" ";         // for printing the last node.
    }
    

}
int ll::count(int d)
{
    int count = 0;
    node* start = last;
    if(last == nullptr)
        return count;
    do
    {
        if(start->data == d)
            count++;
        start = start->next;   
    } while (start != last);
 
    return count;
}
minmax ll::MM()
{
    node* start = last;
    if(last == nullptr)
    {
        minmax temp;
        return temp;
    }
    else
    {
        minmax temp(start->data, start->data);
        start = start->next;
        while(start != last)
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
    l1.insertatend(32);
    l1.insertatfront(2);
    l1.insertatend(1);
    l1.insertatfront(31);
    l1.insertatend(8);
    l1.print();
    a = l1.MM();
    cout<<a.min<<" "<<a.max<<" "<<endl;
    return 0;
}