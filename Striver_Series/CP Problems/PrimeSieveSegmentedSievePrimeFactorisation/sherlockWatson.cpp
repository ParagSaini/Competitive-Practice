#include<bits/stdc++.h>
using namespace std;

// very tricky problem.
void findMinColor(int n) {
    int maxInd = n+1;
    vector<int> priceArr(maxInd+1, 1);   // 0 to 10^5+1;
    for(int i=2; i<=maxInd; i++) {
        if(priceArr[i] == 1) { // means a prime number
            for(long long j = (long long)i*i; j<=maxInd; j+=i) {
                if(priceArr[j] == 1) {    // if the multiple is unvisited.
                    priceArr[j] = 2;
                }
            }
        }
    }
    cout<<2<<endl;
    for(int i=2; i<priceArr.size(); i++) cout<<priceArr[i]<<" ";
}
int main() {
    int n;
    cin>>n;
    if(n == 1) {   // price from 2 to 2.
        cout<<1<<endl<<1<<endl;
    } else if(n == 2) {        // price from 2 to 3;
        cout<<1<<endl<<"1 1"<<endl;
    } else {
        findMinColor(n);
    }
    return 0;
}