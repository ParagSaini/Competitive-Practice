#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    int xorr = 0, a, b;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        xorr ^= arr[i];
    }
    int rightMostSetBitNo = xorr & (~(xorr-1));
    int bucket1 = 0, bucket2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] & rightMostSetBitNo) {
            bucket1 ^= arr[i];
        } else {
            bucket2 ^= arr[i]; 
        }
    } 
    if(bucket1 > bucket2) cout<<bucket2<<" "<<bucket1<<endl;
    else cout<<bucket1<<" "<<bucket2<<endl;
    return 0;
}