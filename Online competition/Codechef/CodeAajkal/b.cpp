#include<bits/stdc++.h>
using namespace std;
class pkt{
    public:
    int pktSize, price;
    double unitPrice;
    pkt(int a, double b, int c) {
        pktSize = a;
        unitPrice = b;
        price = c;
    }
};
bool comp(pkt a, pkt b) {
    if(a.unitPrice < b.unitPrice) return true;
    if(a.unitPrice == b.unitPrice) return (a.pktSize > b.pktSize);
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x, y, z;
        cin>>n>>x>>y>>z;
        long long cost = 0;
        vector<pkt> arr = {pkt(10,x/10.0,x), pkt(5,y/5.0,y), pkt(1,z,z)};
        sort(arr.begin(), arr.end(), comp);

        for(int i=0; i<arr.size(); i++) {
            if(n >= arr[i].pktSize) {
                int q = n/arr[i].pktSize;
                n = n % arr[i].pktSize;
                cost += ((long long)q*arr[i].price);
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}