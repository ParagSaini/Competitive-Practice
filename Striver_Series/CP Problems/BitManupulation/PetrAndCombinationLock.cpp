#include<bits/stdc++.h>
using namespace std;

// using the power set or Bit masks.
bool isPossible(vector<int> angle) {
    int n = angle.size();
    int maxNum = (1<<n) -1; // or pow(2,n)-1;        number whose binary representation is all '1', n times.
    for(int i=0; i<=maxNum; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            // getting the last bit of the binary representation of that number.
            if( (i>>j) & 1) { // do clockwise
                sum += angle[j];
            } else sum -= angle[j]; // do anticlockwise
        }
        if(sum % 360 == 0) return true;
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    vector<int> angle(n);
    for(int i=0; i<n; i++) cin>>angle[i];
    if(isPossible(angle)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

// Using the recursion.
bool isPossible(vector<int> angle, int sum, int start) {
    if(start == angle.size()) {
        if(sum % 360 == 0) return true;
        return false;
    }
    return ( isPossible(angle, sum+angle[start], start+1) || isPossible(angle, sum-angle[start], start+1));
}
int main() {
    int n, sum = 0, s = 0;
    cin>>n;
    vector<int> angle(n);
    for(int i=0; i<n; i++) cin>>angle[i];
    if(isPossible(angle, sum, s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}