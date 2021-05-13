#include<iostream>
#include<conio.h>
using namespace std;
/*
int missing(int a[], int s)
{
	int total = (s+1)*(s+2)/2;    // total sum of n numbers.    n*(n+1)/2 , this may cause integer overflow, if n is very large like 10^6.

	for(int i=0; i<s; i++)
		total = total - a[i];

	return total;

}*/

// actually the below implementation is optimization of above algorithm.
int missing(int a[], int s)
{	
	int total = 1;
	for(int i=0; i<s; i++)
	{
		total = total + i + 2;           // contains the running sum 1+2+3+4....n
		total = total - a[i];              // subtract the elements from total
	}
	return total;               // the remaining number is the missing number
}
int main()
{
	int a[] = {1,2,5,4};
	cout<<missing(a, 4);
	return 0;
}