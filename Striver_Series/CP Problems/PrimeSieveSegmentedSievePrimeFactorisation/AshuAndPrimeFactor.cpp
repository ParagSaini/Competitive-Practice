#include<bits/stdc++.h>
using namespace std;
vector<int> getPrimes() {
    int maxInd = pow(10,6);
    vector<int> primeArr(maxInd+1, -1); // -1 means the index is unvisited.

    for(int i=2; i <= maxInd; i++) {
        if(primeArr[i] == -1) {
            int count = 1;
            for(long long j=(long long)i*i; j<=maxInd; j+=i) {
                if(primeArr[j] == -1) {
                    primeArr[j] = 1;      // mark it visited
                    count++;
                }
            }
            primeArr[i] = count;
        }
    }

    return primeArr;
}
int main() {
    int t;
    cin>>t;
    vector<int> primeArrCount = getPrimes();
    while(t--) {
        int n;
        cin>>n;
        cout<<primeArrCount[n]<<endl;
    }
    return 0;
}