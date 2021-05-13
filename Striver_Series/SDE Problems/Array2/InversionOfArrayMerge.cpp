#include<bits/stdc++.h>
using namespace std;

// Using the exact coding of merge routine of merge sort.
long long MergeSortArray(vector<int>& ar, int s1, int e1, int e2) {

    long long Inversion = 0;
    int start1 = s1;
    int end1 = e1;
    int start2 = end1+1;
    int end2 = e2;
    int size = end2 - start1 + 1;
    vector<int> temp(size);
    int i = 0;
    while(start1 <= end1 && start2 <= end2) {
        if(ar[start1] > ar[start2]) {
            temp[i] = ar[start2];
            start2++;
            // this is the only line change in merge subroutine and this function
            Inversion += end1 - start1 + 1;
            
        } else {
            temp[i] = ar[start1];
            start1++;   
        }
        i++;
    }
    if(start1 > end1) {
        while(start2 <= end2) {
            temp[i++] = ar[start2++];
        }
    }
    else if(start2 > end2 ) {
        while(start1 <= end1) {
            temp[i++] = ar[start1++];
        }
    }
    
    int k = 0;
    for(int i=s1; i<=e2; i++) {
        ar[i] = temp[k++];
    }
    
    return Inversion;
}

long long countInversionMerge(vector<int>& ar, int s, int e) {
    if(s >= e) return 0;
    
    int mid = (s+e)/2;
    long long l = countInversionMerge(ar, s, mid);
    long long r = countInversionMerge(ar, mid+1, e);
    long long m = MergeSortArray(ar, s, mid, e);
    long long count = (l+r+m);
    
    return count;
}