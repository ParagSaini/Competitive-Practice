#include<bits/stdc++.h>
using namespace std;

void primeSieve(vector<int>& xorr,vector<int>& primeArr ) {
    int n = 2e6;          // by choosing 2*10^6, we have > 10^5 prime numbers.
    vector<bool> prime(n+1, true);
    xorr[1] = 1;
    for(int i=2; (long long)i*i<= n; i++) {
        if(prime[i]) {
            for(long long j = (long long)i*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        xorr[i] = (xorr[i-1] ^ i);
        if(prime[i]) {
            primeArr.push_back(i);
        }
    }
}
int main() {
    int p = 2e6;
    vector<int> xorr(p+1), primeArr;
    primeSieve(xorr, primeArr);
    cout<<primeArr.size()<<endl;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<xorr[primeArr[n-1]]<<endl;
    }
    return 0;
}
