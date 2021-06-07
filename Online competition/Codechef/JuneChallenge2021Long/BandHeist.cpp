#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getApSum(ll n, ll a, ll d) {
    ll sum = (n*(2*a + (n-1)*d));
    return (sum/2);
}
int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll D, d, P, Q;
        cin>>D>>d>>P>>Q;
        ll parts = D/d;
        ll rem = D%d;
        // look this as a A.p with d = Q, a = P
        ll money = 0;
        money += getApSum(parts, P, Q);
        money *= d; // for each per day.   d(a + a+d + a+2d + a+3d...)
        if(rem != 0) {
            ll printingRate = (P + (parts-1)* Q);
            printingRate += Q;
            money += (printingRate * rem);
        }
        cout<<money<<endl;
    }
    return 0;
}