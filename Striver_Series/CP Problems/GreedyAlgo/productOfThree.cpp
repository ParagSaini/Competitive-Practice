#include<bits/stdc++.h>
using namespace std;
void solve(int n) {
    int minFactor = -1;
    int a,b,c;
    for(int i=2; i<=sqrt(n); i++) {
        if((n%i) == 0) {
            minFactor = i;
            break;
        }
    }
    if(minFactor == -1) { // number is prime
        cout<<"NO"<<endl;
        return;
    }
    a = minFactor;
    n = n/a;
    for(int i=a+1; i<=sqrt(n); i++) {
        if((n%i) == 0) {
            b = i;
            c = (n/i);
            if(b != c && c != a) {
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n; 
        cin>>n;
        solve(n);
    }
    return 0;
}