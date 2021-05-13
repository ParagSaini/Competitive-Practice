#include<bits/stdc++.h>
using namespace std;

long long sum(int i, int j, vector<long long> memo) {
    if(i == 0) return memo[j];
    return (memo[j] - memo[i-1]);
}
int main() {
    int n;
    cin>>n;
    vector<long long> memo(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        if(i != 0) memo[i] = memo[i-1] + (long long)temp;
        else memo[i] = (long long)temp;

    }
    int q;
    cin>>q;
    while(q--) {
        int i, j;
        cin>>i>>j;
        cout<<sum(i, j, memo)<<endl;
    }
    return 0;
}