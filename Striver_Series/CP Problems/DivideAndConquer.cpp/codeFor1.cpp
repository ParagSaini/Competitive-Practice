#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isOne(ll len, ll n, ll i) {
    if(n < 2) return n;
    if(i == (len/2) + 1) return (n%2);
    n /= 2;
    len /= 2;
    if(i > len + 1) i -= (len + 1);
    return isOne(len, n, i); 
}
int main() {
    ll n, l, r;
    cin>>n>>l>>r;
    ll p = (int)log2(n) + 1;
    ll len = (1LL << p) -1LL;    // 2^(log2(n)+1) - 1; number of 0 & 1 after all operations.
    ll cnt = 0;
    for(ll i=l; i<=r; i++) {
        if(isOne(len, n, i)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}