#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    for(int i=0; i<n; i++) {
        int cur = arr[i];
        arr[i] = temp;
        temp = cur;
    }
}