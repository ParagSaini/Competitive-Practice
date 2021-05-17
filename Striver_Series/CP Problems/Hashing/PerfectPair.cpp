#include<bits/stdc++.h>
using namespace std;

// 1 <= t <= 10, 1 <= n <= 10^5, 1 <= Ai <= 10^3
// maximum perfect square or perfect cube will be = 10^3 + 10^3 = 2000, therefore making the precomputedArr for square and cube checks.

void preComputeSqCube(vector<bool>& arr) {
    for(long long i=1; i<=2000; i++) {
        if( (i*i) <= 2000) arr[i*i] = true;
        if((i*i*i) <= 2000) arr[i*i*i] = true;
    }
}
long long countPerfectPair(unordered_map<int, int>& freq, vector<int>& arr, vector<bool>& perfectArr) {
    long long count = 0;
    for(int i=0; i<arr.size(); i++) {
        int curFreq = freq[arr[i]];
        // this line is very important., may be the sum of duplicate number is a perfect square. and if yes, then nC2 is the no of pair. 
        if(curFreq > 1 && perfectArr[2*arr[i]]) count += (((long long)curFreq * (curFreq -1) )/2 );
        for(int j=i+1; j<arr.size(); j++) { 
            int sum = arr[i] + arr[j];
            if(perfectArr[sum]) {
                count += (long long)freq[arr[i]] * freq[arr[j]];
            }
        }
    }
    return count;
}
int main() {
    int t;
    cin>>t;
    vector<bool> perfectArr(2001, false);     // 0 to 2000
    preComputeSqCube(perfectArr);
    while(t--) {
        int n;             // n = 10^5
        cin>>n;
        unordered_map<int, int> freq;
        vector<int> arr;
        while(n--) {
            int temp;
            cin>>temp;
            freq[temp]++;
        }
        // only pushing the unique elements
        // maximum arr.size() == 10^3
        for(auto it : freq) arr.push_back(it.first);
        cout<<countPerfectPair(freq, arr, perfectArr)<<endl;
    }
    return 0;
}