#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

class dist{
    public:
    ll len, s, e;
    dist(ll a, ll b, ll c) {
        len = a;
        s = b;
        e = c;
    }
};
class comp {
    public:
    bool operator()(dist a, dist b) {
        if(a.len == b.len) {
            return (a.s > b.s);
        } 
        return (a.len < b.len);
    }
};
int main() {
    ll n, k;
    cin>>n>>k;
    string str;
    cin>>str;
    ll q;
    cin>>q;
    priority_queue<dist, vector<dist>, comp> maxheap;
    unordered_map<ll, ll> kpos;
    ll s = 1, e = n;
    maxheap.push(dist(e-s+1, s, e));
    for(int i=1; i<=k; i++) {
        dist top = maxheap.top();
        maxheap.pop();
        ll mid;
        if((top.len %2) != 0) {
            mid = (top.s + top.e)/2;
        } else {
            mid = (top.s + top.e)/2;
            ll pos1 = mid, pos2 = mid+1;
            if(str[i-1] == 'R') {
                mid = pos2;
            } else {
                mid = pos1;
            }
        }
        kpos[mid] = i;
        if((mid-1-top.s+1) > 0) maxheap.push(dist(mid-1-top.s+1, top.s, mid-1));
        if((top.e-(mid+1)+1) > 0) maxheap.push(dist(top.e-(mid+1)+1, mid+1, top.e));
    }
    for(int i=0; i<q; i++) {
        ll x;
        cin>>x;
        if(kpos.count(x)) {
            cout<<kpos[x]<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}