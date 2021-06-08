#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x1, x2, x3, r;
        cin>>x1>>x2>>x3>>r;
        int l1 = x3-r;
        int r1 = x3+r;
        int l2 = min(x1, x2);
        int r2 = max(x1, x2);
        int ans = r2 - l2;
        int laserDist;
        if(l2 >= r1 || l1 >= r2) laserDist = 0;
        else {
            int c1 = max(l1, l2);
            int c2 = min(r1, r2);
            laserDist = c2 - c1;
        }
        cout<<ans - laserDist<<endl;
    }
    return 0;
}