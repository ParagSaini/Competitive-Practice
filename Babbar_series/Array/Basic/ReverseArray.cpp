#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;
void reverseArray(int a[], int startingIndex, int endIndex)
{
	if(startingIndex >= endIndex)
		return;
	swap(a[startingIndex],a[endIndex]);
	reverseArray(a,startingIndex+1,endIndex-1);
}
int main()
{
  int a[] = {1,2,3,4,5,4};
  int capacity = sizeof(a)/sizeof(int);
  for(int i=0; i<capacity; i++)
  {
  	cout<<a[i]<<" ";
  }
  cout<<endl;
  reverseArray(a,0,capacity-1);
  for(int i=0; i<capacity; i++)
  {
  	cout<<a[i]<<" ";
  }
  getch();
  return 0;
}