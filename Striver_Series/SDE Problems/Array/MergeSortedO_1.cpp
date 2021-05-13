#include<bits/stdc++.h>
using namespace std;

// Gap Method.
// t.c O((n+m)log(n+m)), s.c O(1)
void merge(long long arr1[], long long arr2[], int n, int m) { 
    int gap = ceil((n+m)/2.0);
    // break when gap < 1;
    while(gap > 0) {
        int s1 = 0, s2 = gap;
        while(s2 < (n+m)) { 
            if(s1 < n) {
                if(s2 < n) {
                    if(arr1[s1] > arr1[s2]) swap(arr1[s1], arr1[s2]);
                } else {
                    if(arr1[s1] > arr2[s2-n]) swap(arr1[s1], arr2[s2-n]);
                }
            } else {
                if(arr2[s1-n] > arr2[s2-n]) swap(arr2[s1-n], arr2[s2-n]);
            }
            s1++;
            s2++;
        }
        if(gap == 1) break;
        gap = ceil(gap/2.0); 
    }
}
// insertion sort method.
// overall time complexity = O(n*m), s.c O(1)
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    for(int i=0; i<n; i++) {
        if(arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            insertAtCorrectPosition(arr2, m);
        }
    }
} 
// this will insert the 0th index element at right position in the array
void insertAtCorrectPosition(long long arr[], int n) {
    for(int i=1; i<n; i++) {
        if(arr[i-1] > arr[i]) swap(arr[i-1], arr[i]);
        else break;
    }            
}

// t.c O(n+m) && s.c O(n+m)
void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    vector<long long> temp;
    int i1 = 0, i2 = 0;
    while(i1 < n && i2 < m) {
        if(arr1[i1] < arr2[i2]) {
            temp.push_back(arr1[i1++]);
        } else {
            temp.push_back(arr2[i2++]);
        }
    }
    while(i1 < n) temp.push_back(arr1[i1++]);
    while(i2 < m) temp.push_back(arr2[i2++]);
    i1 = 0, i2 = 0;
    for(int i=0; i<temp.size(); i++) {
        if(i < n) arr1[i1++] = temp[i];
        else arr2[i2++] = temp[i];
    }
    
} 

// t.c (n+m) * log(n+m),   s.c O(n+m)
void merge(int arr1[], int arr2[], int n, int m) {
    int arr[n+m];
    int ind = 0;
    for(int i=0; i<n; i++) {
        arr[ind++] = arr1[i];
    } 
    for(int i=0; i<m; i++) {
        arr[ind++] = arr2[i];
    }
    
    sort(arr, arr + n + m);
    
    ind = 0;
    for(int i=0; i<n; i++) {
        arr1[i] = arr[ind++];
    }
    for(int i=0; i<m; i++) {
        arr2[i] = arr[ind++];
    }
}