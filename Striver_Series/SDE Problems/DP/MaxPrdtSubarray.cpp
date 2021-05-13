#include<bits/stdc++.h>
using namespace std;

// just maintaing the continours min and max prdt
long long maxProduct(vector<int>& arr) {
    long long ans,maxp,minp;
    ans=maxp=minp=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<0) swap(maxp,minp);
        maxp =max<long long int>(maxp*arr[i],arr[i]);
        minp =min<long long int>(minp*arr[i],arr[i]);
        ans = max(ans,maxp);
    }
    return ans;
}