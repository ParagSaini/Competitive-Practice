#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int num) {
    for(int i=2; (long long)i*i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}
vector<int> generateSieve() {
    int maxInd = pow(10,6)-1;
    vector<bool> arr(maxInd+1, true);        // 0 to 10^6-1
    for(int i=2; (long long)i * i <=maxInd; i++) {
        if(arr[i]) {
            for(int j = i*i; j<=maxInd; j+=i) {
                arr[j] = false;
            }
        }
    }
    vector<int> nearestPrime(maxInd+1);
    nearestPrime[1] = 2;
    int prevPrime = 2;
    // traversing from left to right
    for(int i=2; i<=maxInd; i++) {
        if(arr[i] == true) {
            prevPrime = i;
        } 
        nearestPrime[i] = prevPrime;
    }
    prevPrime = INT_MAX;
    int diff = maxInd - nearestPrime[maxInd];
    for(int num=maxInd+1; num <= (maxInd+diff-1); num++ ) {
        if(checkPrime(num)) {
            prevPrime = num;
            break;
        }
    }
    if(prevPrime == INT_MAX) prevPrime = nearestPrime[maxInd];

    // traversing from the right to left
    for(int i=maxInd; i>=2; i--) {
        if(arr[i] == true) {
            prevPrime = i;
        }
        int diff1 = i - nearestPrime[i];
        int diff2 = abs(prevPrime - i);
        if(diff2 < diff1) {
            nearestPrime[i] = prevPrime;
        }
    }
    return nearestPrime;
}
int main() {
    vector<int> nearestPrime = generateSieve();
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", nearestPrime[n]);
    }
    return 0;
}