#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void getReqNums(vector<ll>& arr) {
    // we choose 62 because ll 2^63-1 and according to constraints a,b <= 10^18, therfore 62 will cover all the possible numbers.
    for(int i=1; i<=62; i++) {
        ll n = (1LL<<i)-1LL;
        for(int j=0; j<=(i-2); j++) {
            ll x = (n - (1LL<<j));
            arr.push_back(x);
        }
    }
}
int main() {
    ll a, b;
    cin>>a>>b;
    ll cnt = 0;
    vector<ll> reqNums;
    getReqNums(reqNums);
    for(int i=0; i<reqNums.size(); i++) {
        if((reqNums[i] >= a) && (reqNums[i] <= b)) {
            cnt++;
        }
    }
    cout<<endl<<cnt<<endl;
    return 0;
}

int main() {
    long long a, b;
    cin>>a>>b;
    long long count = 0;
    for(int i=0; (1LL << i)/2<= b; i++)  {
        // i-2 is important because i-1 leads to one leading zero, which cause problem.
        for(int j=0; j<=i-2; j++) {
            long long x = (1LL << i) - 1; // number with all 1 in binary.
            x = x - (1LL << j);   // subtracting power of 2.
            if(x >= a && x <= b) {
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}