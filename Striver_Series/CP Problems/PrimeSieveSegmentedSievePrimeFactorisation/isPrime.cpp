#include<bits/stdc++.h>
using namespace std;

/* Every Number can be represented in the form of (6*k+i) where i is in between 0 to 5.So any number can be represented in atleast one of the forms 6*k , 6*k+1 , 6*k+2 , 6*k+3 ,6*k+4 , 6*k+5. Out of these numbers 6*k +2 , 6*k+4 are divisible by 2 and 6*k +3 , 6*k are divisible by 3. So the remaining are 6*k+1 and 6*k+5. 6*k+5 can also be represented by 6*k-1.
so after removing multiple of 2 and 3, we have to check by only two numbers 6k-1 and 6k+1
*/
// t.c O(sqrt(n/6))
bool checkPrime(int n) {
    // every number is represented in 
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    // removing all multiple of 2 and 3.
    if(n%2 == 0 || n%3 == 0) return false;
    // 6k-1, 6k+1, k = 1,2,3,4,5,...
    for(int i=5; (long long)i*i <= n; i+=6) {
        // i = 6k-1, i+2 = 6k+1
        if(n%i == 0 || n%(i+2) == 0) return false;
    }
    return true;
}

// t.c O(sqrt(n));
// the greatest factor of any number is <= sqrt(n);
bool checkPrime(int n) {
    for(int i=2; (long long)i*i <= n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}
bool checkPrime(int n) {
    for(int i=2; i<n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    cout<<checkPrime(n);
    return 0;
}