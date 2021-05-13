#include<bits/stdc++.h>
using namespace std;

// Recursive approach(mine)  O(lg(n));
double myPowRecur(double x, long long num) {
    if(num == 0) return 1.0;
    
    int half = num / 2;
    
    double halfPower = myPowRecur(x, half);
    
    if(num % 2 == 1) return halfPower * halfPower * x;
    return halfPower * halfPower;
}
double myPow(double x, int n) {
    long long num = n;
    if(n < 0) num *= -1;
    double ans = myPowRecur(x, num);
    if(n < 0) return 1/ans;
    return ans;
}


// iterative approach O(lg(n));
double myPow(double x, int n) {
    long long num = n;
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