#include<bits/stdc++.h>
using namespace std;
// USE PRINTF AND SCANF, INSTEAD OF COUT AND CIN, TLE WILL BE REMOVED, PRINTF AND SCANF ARE FAST THAN THE COUT AND CIN.
// print all prime less than 10^8
// SIMPLE SIEVE OF ERATHANOS
vector<int> getPrime() {    
    int n = pow(10,8);
    vector<bool> arr(n+1, true);    // 0 to 10^8
    vector<int> prime;
    
    for(int i=2; (long long)i*i <= n; i++) {
        if(arr[i]) {
            for(long long j = (long long)i*i; j<=n; j+=i) {
                arr[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(arr[i]) prime.push_back(i);
    }
    return prime;
}
int main() {
    vector<int> prime = getPrime();
    int n = 0;      // 0th index is actually 1st prime
    for(int i = n; i<prime.size(); i+=100) {
        printf("%d\n", prime[i]);
    }
    return 0;
}