#include<bits/stdc++.h>
using namespace std;

void computePrefixSum(vector<long long>& prefixSum, vector<int>& arr) {
    prefixSum[0] = (long long)arr[0];
    for(int i=1; i<arr.size(); i++) {
        prefixSum[i] = (long long)arr[i] + prefixSum[i-1];
    }
}
void performQuery(vector<int> arr, vector<pair<int, int>> queries) {
    int n = arr.size();
    if(n == 0) return;
    vector<long long> prefixSum(n);
    computePrefixSum(prefixSum, arr);

    for(int i=0; i<queries.size(); i++) {
        int a = queries[i].first, b = queries[i].second;
        long long sum = prefixSum[b] - prefixSum[a] + arr[a];
        cout<<sum<<endl;
    }
}
int main() {
    int num, i = 0, q;
    cin>>num;
    vector<int> arr(num);
    vector<pair<int, int>> queries;
    while(num--) {
        cin>>arr[i++];
    }
    cin>>q;
    while(q--) {
        int a, b;
        cin>>a>>b;
        queries.push_back(make_pair(a,b));
    }
    performQuery(arr, queries);
    return 0;
}