#include<bits/stdc++.h>
using namespace std;

void primeSieve(vector<int>& xorr,vector<int>& primeArr ) {
    int n = 1e5;
    vector<bool> prime(n+1, true);
    xorr[1] = 1;
    for(int i=2; i<= n; i++) {
        xorr[i] = (i ^ xorr[i-1]);
        if(prime[i]) {
            for(long long j = (long long)i*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(prime[i]) {
            primeArr.push_back(i);
        }
    }
}
int main() {
    int p = 1e5;
    vector<int> xorr(p+1), primeArr;
    primeSieve(xorr, primeArr);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<xorr[primeArr[n-1]]<<endl;
    }
    return 0;
}