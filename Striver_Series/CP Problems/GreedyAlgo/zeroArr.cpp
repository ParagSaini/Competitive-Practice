#include<bits/stdc++.h>
using namespace std;

string solve(vector<int> arr) {
    long long sum = 0;
    int maxEle = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        maxEle = max(arr[i], maxEle);
    }
    if((sum %2 == 0) && (maxEle <= (sum - maxEle))) return "YES";
    return "NO";
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    cout<<solve(arr);
    return 0;
}