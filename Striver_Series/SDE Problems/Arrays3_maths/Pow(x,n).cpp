#include<bits/stdc++.h>
using namespace std;

// Recursive approach(mine)  O(lg(n));
double myPowRecur(double x, long long n) {
    if(n == 1) return x;
    int half = n/2;
    double halfVal = myPowRecur(x, half);
    if(n % 2 == 0) return (halfVal * halfVal);
    else return (halfVal*halfVal*x);
    
}
double myPow(double x, int n) {
    if(n == 0) return 1.0;
    
    long long num = (long long)n;   // long long is necessary because, if n = 2^-31, then -1 * 2^-31 gives integer overflow.
    if(n < 0) num *= -1;
    double ans = myPowRecur(x, num);
    if(n < 0) return 1/ans;
    return ans;
}

// iterative approach O(lg(n));
double myPow(double x, int n) {
    long long num = n;
    // (2)^16 = (2^2)^8 = (2^4)^4 = (2^8)2..
    double ans = 1.0;
    if(n < 0) num *= -1;
    while(num > 0) {
        if(num % 2 == 0) {
            x *= x;
            num /= 2;
        } else {
            ans = ans * x;
            num--;
        }
    }
    if(n < 0) return 1.0/ans;
    return ans;
}