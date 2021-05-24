#include<bits/stdc++.h>
using namespace std;

// We can't do this with the simple prime sieve because, m, n varies from 1 to 10^9, the maximum size array we can create is 10^8, and it is also given that (n-m) <= 10^5, this is a hint to use the segmented sieve.

// creating array of prime between 2 to approx sqrt(10^9).
vector<int> getPrimes() {
    int n = pow(10,5);  // n = 10^5
    vector<bool> arr(n+1, true);
    vector<int> prime;
    for(int i=2; i<=n; i++) {
        if(arr[i]) {
            for(long long k = (long long)i*i; k <= n; k+=i) {
                arr[k] = false;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(arr[i]) {
            prime.push_back(i);
        } 
    }
    return prime;
}
void printPrime(vector<int>& prime, int l, int r) {
    if(l == 1) l++;       // 1 is not a prime number

    // this is similar to simple sieve look closely.
    vector<bool> rangePrime(r-l+1, true);  // 0 to r-l;
    for(int i=0; prime[i] * (long long)prime[i] <= r; i++) {
        int curPrime = prime[i];
        int baseVal = ((l/curPrime) * curPrime);    // either baseVal = l or just smaller number which is multiple of curPrime. 
        if(baseVal < l) {
            baseVal += curPrime;
        }
        for(int j=baseVal; j<=r; j+=curPrime) {
            rangePrime[j-l] = false;
        }
        if(baseVal == curPrime) {        //it will cause curPrime to be false, but actually it is a prime number, so do following.
            rangePrime[curPrime - l] = true;
        }
    }
    for(int i=0; i<=r-l; i++) {
        if(rangePrime[i]) cout<<i+l<<endl;
    }
}
int main() {
    int t;
    cin>>t;
    vector<int> prime = getPrimes();
    while(t--) {
        int m, n;
        cin>>m>>n;
        printPrime(prime,m, n);
        cout<<endl;
    }
    return 0;
}