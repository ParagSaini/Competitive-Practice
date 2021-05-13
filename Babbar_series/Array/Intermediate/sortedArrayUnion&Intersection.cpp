#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

void SortedArrayUnion(int a[], int b[], int capacity1, int capacity2)
{
    if(b[0]>=a[capacity1-1])         // their is no element common in two arrays except may be last of a[] and first of b[];
    {
        for(int i=0; i<capacity1; i++)        // printing array a[] as it is.
            cout<<a[i]<<" ";
        if(b[0] != a[capacity1-1])         // checking whether or not last element of a[] is equal to the first element of b[];
            cout<< b[0]<<" ";
        for(int j=1; j<capacity2; j++)
            cout<<b[j]<<" ";
        
        return;
    }

    if(a[0]>=b[capacity1-1])         // their is no element common in two arrays except may be last of b[] and first of a[];
    {
        for(int i=0; i<capacity2; i++)        // printing array b[] as it is.
            cout<<b[i]<<" ";
        if(a[0] != b[capacity1-1])         // checking whether or not last element of b[] is equal to the first element of a[];
            cout<<a[0]<<" ";
        for(int j=1; j<capacity1; j++)
            cout<<a[j]<<" ";
        
        return;
    }

    // if above if condition not worked, means our array is mixed so printing first array as it is and checking elements of second
    // element whether or not they are present in first array, if present then don't print otherwise print it.

    for(int i=0; i<capacity1; i++)        // printing first array as it is.
        cout<<a[i]<<" ";

    for(int j=0; j<capacity2; j++)
    {
        int isexist = 0;
        for(int i=0; a[i]<=b[j] && i<capacity1; i++)
        {
            isexist = 0;
            if(a[i]!=b[j])
                isexist = 1;
        }
        if(isexist)
            cout<<b[j]<<" ";
    }

}

void SortedArrayIntersection(int a[], int b[], int capacity1, int capacity2)
{
    if(b[0]>=a[capacity1-1])         // their is no element common in two arrays except may be last of a[] and first of b[];
    {
        if(b[0] == a[capacity1-1])         // checking whether or not last element of a[] is equal to the first element of b[];
            cout<<b[0];
        else
            cout<<"Mutually exclusive "<<endl;
        return;
    }

    if(a[0]>=b[capacity1-1])         // their is no element common in two arrays except may be last of b[] and first of a[];
    {
        if(a[0] == b[capacity1-1])         // checking whether or not last element of b[] is equal to the first element of a[];
            cout<<a[0];
        else
            cout<<"Mutually exclusive "<<endl;
        return;
    }

    int ismutuallyexclusive = 1;
    for(int i=0; i<capacity1; i++)
    {
        for(int j=0; a[i]>=b[j] && j<capacity2; j++)
        {
            if(a[i]==b[j])
            {
                cout<<a[i]<<" ";
                ismutuallyexclusive = 0;
                break;
            }
        }
    }
    if(ismutuallyexclusive)
        cout<<"Mutually exclusive "<<endl;
}

int main()
{
    int a[5];
    int b[6];
    int capacity1 = sizeof(a)/sizeof(a[0]);
    int capacity2 = sizeof(b)/sizeof(b[0]);
    cout<<"Enter 5 numbers "<<endl;
    for(int i=0; i<capacity1; i++)
        cin>>a[i];
    cout<<"Enter 6 numbers "<<endl;
    for (int i=0; i<capacity2; i++)
        cin>>b[i];

    SortedArrayUnion(a,b,capacity1, capacity2);
    cout<<endl;
    SortedArrayIntersection(a,b,capacity1,capacity2);

    getch();
    return 0;
}