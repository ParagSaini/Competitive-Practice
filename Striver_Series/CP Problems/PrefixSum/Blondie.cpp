#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long> prefixSum(n);
        for(int i=0; i<n; i++) {
            int temp;
            cin>>temp;
            if(temp == -1) {
                temp = floor(prefixSum[i-1] / i);
            }
            if(i != 0) prefixSum[i] = prefixSum[i-1] + (long long)temp;
            else prefixSum[i] = (long long)temp;
        }
        for(int i=0; i<n; i++) {
           if(i == 0) cout<<prefixSum[i]<<" ";
           else cout<<(prefixSum[i] - prefixSum[i-1])<<" "; 
        }
        cout<<endl;

    }
}