#include<bits/stdc++.h>
using namespace std;

void findIntersection(pair<int, int>& commonInterval, int l, int r) {
    if(commonInterval.first == -1) return;
    int low = commonInterval.first, high = commonInterval.second;
    int maxi = max(low, l);
    if(maxi > high) {
        low = -1;
        high = -1;
    } else {
        low = maxi;
        high = min(high, r);
    }
    commonInterval.first = low;
    commonInterval.second = high;
}
vector<int> getPrimes() {
    int n = pow(10,5);  // n = 10^5
    vector<bool> arr(n+1, true);
    vector<int> prime;
    for(int i=2; i<=n; i++) {
        if(arr[i]) {
            for(long long k = (long long)i*i; k <= n; k+=i) {
                arr[k] = false;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(arr[i]) {
            prime.push_back(i);
        } 
    }
    return prime;
}
int countPrime(vector<int>& prime, int l, int r) {
    if(l == 1) l++;       // 1 is not a prime number
    int count = 0;
    // this is similar to simple sieve look closely.
    vector<bool> rangePrime(r-l+1, true);  // 0 to r-l;
    for(int i=0; prime[i] * (long long)prime[i] <= r; i++) {
        int curPrime = prime[i];
        int baseVal = ((l/curPrime) * curPrime);    // either baseVal = l or just smaller number which is multiple of curPrime. 
        if(baseVal < l) {
            baseVal += curPrime;
        }
        for(int j=baseVal; j<=r; j+=curPrime) {
            rangePrime[j-l] = false;
        }
        if(baseVal == curPrime) {        //it will cause curPrime to be false, but actually it is a prime number, so do following.
            rangePrime[curPrime - l] = true;
        }
    }
    for(int i=0; i<=r-l; i++) {
        if(rangePrime[i]) count++;
    }
    return count;
}
int countPrime(pair<int, int> interval) {
    int l = interval.first, r = interval.second, count = 0;
    vector<int> prime = getPrimes();
    return countPrime(prime, l, r);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,l,r;
        cin>>n>>l>>r;
        pair<int, int> commonInterval = make_pair(l,r);

        for(int i=0; i<n-1; i++) {
            cin>>l>>r;
            findIntersection(commonInterval, l,r);
        }
        if(commonInterval.first == -1) cout<<-1<<endl;
        else {
            int n = countPrime(commonInterval);
            cout<<n<<endl;
        }
    }
    return 0;
}