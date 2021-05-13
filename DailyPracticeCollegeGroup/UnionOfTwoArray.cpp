#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

// O((n+m)log(n+m)), s.c O(n+m)

/* we can't do it with two pointer because, there may be duplicate elements in the individual array itself, to work that idea we need both array to be sorted and contains unique elements.
*/

int doUnion(int a[], int n, int b[], int m)  {
    if(n == 0 && m == 0) return 0;
    vector<int> arr;
    int count = 1;
    for(int i=0; i<(n>m ? n : m); i++) {
        if(i<n) arr.push_back(a[i]);
        if(i<m) arr.push_back(b[i]);
    }
    sort(arr.begin(), arr.end());
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] != arr[i-1]) {
            count++;
        }
    }
    return count;
}