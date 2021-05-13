#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>

    // THEIR MAY BE SOME BUGS IN SPECIAL CASES, LIKE DeleteAny(0) won't work correctly, that can be rectified later.

template<typename T>
class List
{
   class node
   {
   public:
     T data;
     node *link;
     node(T data)
     { 
         this->data= data;
         link=nullptr;
     }
   };

public:
   T operator[](unsigned);
   void insertAtFront(T);
   void insertAtEnd(T);
   void insertAtAny(T,unsigned);
   void DeleteFirst();
   void DeleteEnd();
   void DeleteAny(unsigned);
   unsigned NumberOfNode();

node *start=nullptr;

};
template<typename T>
T List<T>::operator[](unsigned index)
{
   node *p=start;
   if(p==nullptr)
   {
      cout<<"List is empty "<<endl;
      return -1;
   }
   while(index>0)
   {
      p=p->link;
      index--;
   }
   return p->data;
}
template<typename T>
void List<T>::insertAtFront(T d)
{
   node *temp=new node(d);
   temp->link=start;
   start=temp;
}

template<typename T>
void List<T>::insertAtEnd(T d)
{
   node *p=start;
   if(p==nullptr)
   {
      (*this).insertAtFront(d);
      return;
   }

   node *temp=new node(d);

   while(p->link != nullptr)
      p=p->link;

   p->link=temp;

}
template<typename T>
void List<T>::insertAtAny(T d, unsigned index)
{
   node *temp=new node(d);
   node *p=start;
   while(index>1)
   {
      p=p->link;
      index--;
   }
   temp->link=p->link;
   p->link=temp;
}
template <typename T>
void List<T>::DeleteFirst()
{
   node *temp=start;
   start=start->link;
   delete temp;

}
template<typename T>
void List<T>::DeleteEnd()
{
   if(start==nullptr)
      cout<<"List is empty"<<endl;
   else
   {
      int count=0;
      node *temp=start->link;
      while(temp!=nullptr)
      {   temp=temp->link; count++; }
      delete temp;
      temp=start;
      while(count>1)
      {
         temp=temp->link;
         count--;
      }
      temp->link=nullptr;
   }
      
}
template<typename T>
unsigned List<T>:: NumberOfNode()
{
   node *temp=start;
   unsigned count=0;
   while(temp!=nullptr)
   {
      temp=temp->link;
      count++;
   }
   return count;
}
template<typename T> 
void List<T>::DeleteAny(unsigned index)
{
   unsigned NodeNo_=NumberOfNode();
   int count=index;
   if(NodeNo_>index)
   {
      if(NodeNo_==0)
         cout<<"List is empty"<<endl;
      else
         {
            node *p1=start;
            node *p2=start;
            while(index>1)
            {
               p1=p1->link;
               index--;
            }
            while(count>=0)
            {
               p2=p2->link;
               count--;
            }
            delete (p1->link);
            p1->link=p2;

         }
   }
   else
      cout<<"Invalid index no."<<endl;
}

int main()
{
   List<int>n1;
   
   /*n1.insertAtFront(5);
   for(int i=0; i<=1; i++)
      cout<<n1[i]<<endl;
   n1.DeleteAny(0);
   cout<<endl;
   for(int i=0; i<=0; i++)
      cout<<n1[i]<<endl;*/
   n1.insertAtFront(1);
   n1.insertAtEnd(2);
   n1.insertAtEnd(3);
   n1.insertAtEnd(4);
   n1.insertAtEnd(5);
   n1.insertAtFront(6);

   cout<<n1.NumberOfNode()<<" ";
   getch();
   return 0;
}