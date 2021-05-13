#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void large3(int a[], int s)          // print largest 3 numbers in O(n) and O(1) space complexity.
{
    int k = 3;                  // we have to find 3 largest number.
    unordered_set<int> s1;
    int great;
    while(k)
    {
        great = a[0];
        for(int i=0; i<s; i++)           // traversing the array.
        {
            if(a[i] > great && !s1.count(a[i]))
                great = a[i];
        }
        s1.insert(great);
        cout<<great<<" ";
        k--;
    }
}
int main()
{
    int a[] = {10,4,3,50,23,90};
    int size = sizeof(a)/sizeof(int);
    large3(a,size);
    return 0;
}