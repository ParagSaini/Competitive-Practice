#include<bits/stdc++.h>
using namespace std;

// t.c O(1) && s.c O(1)
bool isPowerofTwo(long long n){
    if(n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

// t.c  O(log(n)) && s.c O(1)
bool isPowerofTwo(long long n){
    if(n == 0) return false;
    long long num = n - 1;
    return !(n & num);
}

// t.c O(log(n)) && s.c O(1)
bool isPowerofTwo(long long n){
    if(n == 0) return false;
    while(n != 1) {
        if(n%2 != 0) return false;
        n = n/2;
    }
    return true;
}
// t.c O(log(n)) && s.c O(1)

// stop till we hit a set bit, and check the number
bool isPowerofTwo(long long n){
    if(n == 0) return false;
    while( (n&1) == 0) {
        n = n >> 1;
    }
    if(n == 1) return true;
    return false;
}

// t.c O(log(n)) && s.c O(1)
//counting total number of set bits
int countSetBit(long long n) {
    long long x = 1;
    int setbit = 0;
    while(n != 0) {
        if(n&x != 0) setbit++;
        n = n >> 1;
    }
    return setbit;
}
bool isPowerofTwo(long long n){
    if(n == 0) return false;
    int setbit = countSetBit(n);
    if(setbit == 1) return true;
    return false;
}