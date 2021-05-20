#include<bits/stdc++.h>
using namespace std;

// this countBeautyPairs is of no use, as this is taking the O(n) same as below, but uses more computation actually, it is not accepted, though the time complexity is same as below window function. 
long long countBeautyPairs(string str, int i) {
    long long countPair = 0, count0 = 0, count1 = 0;
    for(int i=0; i<i; i++) {
        if(str[i] == '0') count0++;
        else count1++;
    }
    if(count0 == count1 * count1) countPair++;

    for(int i=i; i<str.length(); i++) {
        if(str[i-i] == '0') count0--;
        else count1--;

        if(str[i] == '0') count0++;
        else count1++;

        if(count0 == count1 * count1) countPair++;
    }
    return countPair;
}

long long findBeauty(string str) {
    int n = str.length();
    long long count = 0;
    vector<int> prefixZeroes(n,0);
    if(str[0] == '0') prefixZeroes[0] = 1;

    for(int i=1; i<n; i++) {
        int isZero = 0;
        if(str[i] == '0') isZero++; 
        prefixZeroes[i] = prefixZeroes[i-1] + isZero;
    }    
    
    // As string contains only the 0 and 1, therefore for cnt1*cnt1 == cnt0, i size should be (i * i ) + i.
    // directly check i size of 2, 6, 12. -- as this are the only possible i sizes for such condition.

    for(int i=1; ((long long)i * i) + (long long)i<=(long long)n; i++) {

        int windowLen = (i*i) + i;  // window length
        // traversing the window.     
        for(int endInd=windowLen-1; endInd<n; endInd++) {
            int startInd = endInd-windowLen+1;
            int isZero = str[startInd] == '0' ? 1 : 0;
            int cnt0 = prefixZeroes[endInd] - prefixZeroes[startInd] + isZero;
            int cnt1 = windowLen - cnt0;

            if(cnt0 == cnt1 * cnt1) count++;
        }
    }
    return count++;
}
int main() {
    int T;
    cin>>T;   // 1 <= T <= 10
    while(T--) {
        string str;   // 1<= |str| <= 10^5
        cin>>str;         // there are no spaces in the string.
        cout<<findBeauty(str)<<endl;
    }
    return 0;
}