#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

void BinarySort(int a[], int capacity)
{
  int index=0; 
  int left = 0;
  int right = capacity-1; 
  while(index<=right)
  {
    if(a[index] == 0)
    {
      swap(a[index],a[left]);
      left++;
      index++;
    }
    else if(a[index] == 1)
    {
      index++;
    }
    else if(a[index] == 2)
    {
      swap(a[index],a[right]);
      right--;
    }

  }
}
//ANOTHER SOLUTION, USING COUNTSORT TECHNIQUE.. SAME TIME COMPLEXITY.
/*void sort3(vector<int>& a)
{
  int index = 0;
  int temp[3] = {};
  for(int i=0; i<a.size(); i++)
    temp[a[i]]++;
  for(int i=0; i<3; i++)
  {
    int k = temp[i];
    while(k)
    {
      a[index] = i;
      index++;
      k--;
    }
  }
}*/
int main()
{
  int a[] = {0,1,0,2,1,0,0,1,2,0,1,2,0,1,0,2,2,0,2,2,0,1,1};
  int capacity = sizeof(a)/sizeof(a[0]);

  BinarySort(a,capacity);

  for(int i=0; i<capacity; i++)
  {
    cout<<a[i]<<" ";
  }
  getch();
  return 0;
}