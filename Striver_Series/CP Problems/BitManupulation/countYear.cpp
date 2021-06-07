#include<bits/stdc++.h>
using namespace std;

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