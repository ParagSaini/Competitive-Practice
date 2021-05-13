#include<bits/stdc++.h>
using namespace std;

// t.c O(n) && s.c O(n)
int CountSubarray(vector<int>& arr, int m) {
    unordered_map<int, int> xorr_freq;
    int count = 0;
    int xorr = 0;
    for(auto it : arr) {
        xorr = xorr ^ it;

        if(xorr == m) count++;
        if(xorr_freq.count(xorr ^ m)) count += xorr_freq[xorr ^ m];

        xorr_freq[xorr] += 1;   // clever of writing below thing
        /* 
        if(xorr_freq.count(xorr)) xorr_freq[xorr]++;
        else xorr_freq[xorr] = 1;
        */
    }
    return count;
}

// t.c O(n2) && s.c O(1)
int CountSubarray(vector<int>& arr, int m) {
    int count = 0;
    for(int i=0; i<arr.size(); i++) {
        int Xor = 0;
        for(int j=i; j<arr.size(); j++) {
            Xor = Xor^arr[j];
            if(Xor == m) count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr =  {4,2,2,6,4};
    int m = 6;
    cout<<CountSubarray(arr, m)<<endl;
    return 0;
}