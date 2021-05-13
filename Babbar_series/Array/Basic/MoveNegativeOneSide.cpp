#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
void move(int a[], int s)
{
  int i,index;
  for(i=0; i<s; i++)            // finding the first +ve no.
    if(a[i] >= 0)
    {
      index = i;
      break;
    }
  for(int j=i+1; j<s; j++)
  {
    if(a[j] < 0)
    {
      swap(a[j], a[index]);
      index++;
    }
  }
}
int main()
{
  int a[] = {4,5,6,3,2,1,-1,-3,-32,-6,-8};
  int capacity = sizeof(a)/sizeof(a[0]);
  move(a,capacity);
  for(int i=0; i<capacity; i++)
  {
    cout<<a[i]<<" ";
  }
  getch();
  return 0;
}