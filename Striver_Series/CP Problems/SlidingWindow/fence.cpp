#include<bits/stdc++.h>
using namespace std;

void printMinHeight(vector<int> ht, int k) {
    long long sum = 0;
    long long minSum = LLONG_MAX;
    int startInd = 0;
    for(int i=0; i<k; i++) sum += (long long)ht[i];
    minSum = sum;
    for(int i=k; i<ht.size(); i++) {
        sum -= (long long)ht[i-k];
        sum += (long long)ht[i];
        if(sum < minSum) {
            minSum = sum;
            startInd = i-k+1;
        }
    }
    cout<<(startInd+1)<<endl;   // printing fences based on 1 indexing.
}
int main() {
    int n, k, i = 0;
    cin>>n>>k;
    vector<int> ht(n);
    while(n--) {
        cin>>ht[i++];
    }
    printMinHeight(ht, k);
    return 0;
}