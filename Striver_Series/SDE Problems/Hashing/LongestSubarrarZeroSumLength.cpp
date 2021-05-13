#include<bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
    unordered_set<int> s;
    unordered_map<int, int> sumIndex;
    int sum = 0;
    int maxLength = 0;
    
    for(int i=0; i<n; i++) {
        sum += A[i];
        // sum == 0 is a special case, which occur when the sum of all the previous to curelement is equal to zero.
        if(sum == 0 || s.count(sum)) {
            int l;
            if(sum == 0) {
                // sum == 0, means length of that subarray is i+1.
                l = i+1;
            }
            else l = i - sumIndex[sum];
            
            if(l > maxLength) maxLength = l;
            
        }
        else {
            s.insert(sum);
            sumIndex[sum] = i;
        }
        
    }
    return maxLength;