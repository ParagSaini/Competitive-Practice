#include<bits/stdc++.h>
using namespace std;

int main() {
    int xorr = 1;
    for(int i=2; i<= 1000; i++) {
        xorr ^= i;
        cout<<xorr<<" ";
    }
    return 0;
}