#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
void sort012(int a[], int n)
{
    int cur = 0, left = 0, right = n-1;
    
    while(cur <= right ) {
        if(a[cur] == 0) {
            swap(a[left], a[cur]);
            left++;
            cur++;
        } else if( a[cur] == 1) {
            cur++;
        } else {
            swap(a[right], a[cur]);
            right--;
        }
    } 
}