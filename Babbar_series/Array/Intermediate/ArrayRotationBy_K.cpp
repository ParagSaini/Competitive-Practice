#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;
 // Better optimal solution..
void circularArrayRotation(vector<int> a, int k) {

    int capacity_Array = a.size();
    
    k = k % capacity_Array; // after improved logic, this line makes no difference, this line is only for the first logic to make it better.

//The following logic for rotating the array take two loops, hence for larger rotation like in test case 5, k = 66875, this takes more time, and therefore compiler shows the time exceeded error.
// IMPROVE THE LOGIC FOR ROTATION..
    /*while(k > 0)
    {
        //ROTATING THE ARRAY ONE TIMES, AND KEEP REPEATING THE PROCESS.

        int temp = a[capacity_Array-1];  // storing last element of array in temp.
        for(int i=capacity_Array-1; i>0; i--)
            a[i] = a[i-1];
        a[0] = temp;

        k--;
    }*/

//IMPROVED LOGIC..
//TRADE OFF BETWEEN MEMORY AND TIME, I CHOOSE TIME, THEREFORE USING EXTRA MEMORY TO REDUCE THE TIME.

// creating the temp array of size equal to the array 'a', and initialized with '0'.
    int temp_Array[a.size()]={};
    for(int i=0; i<capacity_Array; i++)
    {
// finding the Index of i_th element after the rotation, and assigning that element value at new index at our temp_Array.
        int Index_After_Rotation = (i+k)%capacity_Array;
        temp_Array[Index_After_Rotation] = a[i];
    }

}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int capacity = sizeof(a)/sizeof(a[0]);
    int n;
    cout<<"Enter a number by which you want to shift the array ";
    cin>>n;
    while(n)
    {
        int temp = a[capacity-1];
        for(int i=(capacity-2); i>=0; i--)           // shifting array one time.
        {
            a[i+1] = a[i];
        }
        a[0] = temp;
        n--;
    }
    for(int i=0; i<capacity; i++)
        cout<<a[i]<<" ";
    getch();
    return 0;
}