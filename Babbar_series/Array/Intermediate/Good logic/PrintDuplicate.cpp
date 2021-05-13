#include<iostream>
#include<conio.h>
using namespace std;
void printDuplicates(int arr[], int n)
{
    for(int i=0; i<n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;              // very good logic..

    int flag = 1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]/n > 1)
        {
            cout<<i<<" ";
            flag = 0;
        }
    }
    if(flag)
        cout<<-1;
}
int main()
{
	int a[] = {2,3,1,2,3};
	int n = sizeof(a)/ sizeof(int);
	printDuplicates(a,n);
	return 0;
}