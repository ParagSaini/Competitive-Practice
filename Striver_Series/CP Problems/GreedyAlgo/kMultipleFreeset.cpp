#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k) {
    if(k == 1) return arr.size();

    unordered_set<long long> skipVals;
    int n = arr.size(), ans = n;

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        // lets say it 'x', we have to find 'y' such that y = x.k, to skip this value
        int x = arr[i];
        if(skipVals.count(x)) {
            ans--;
        } else {
            skipVals.insert((long long)x * k);
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    cout<<solve(arr, k);
    return 0;
}