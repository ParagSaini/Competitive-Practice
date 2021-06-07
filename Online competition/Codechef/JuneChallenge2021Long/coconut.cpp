#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int xa, xb, Xa, Xb;
        cin>>xa>>xb>>Xa>>Xb;
        int ans = (Xa/xa) + (Xb/xb);
        cout<<ans<<endl;
    }
    return 0;
}