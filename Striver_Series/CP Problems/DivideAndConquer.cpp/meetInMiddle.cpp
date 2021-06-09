#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void getSubsetSumArr(vector<ll>& arr, int s, int e, vector<ll>& allSubsetSum, ll sum) {
    if(s > e) {
        allSubsetSum.push_back(sum); 
        return;
    }
    sum += arr[s]; 
    getSubsetSumArr(arr, s+1, e, allSubsetSum, sum);
    sum -= arr[s];
    getSubsetSumArr(arr, s+1, e, allSubsetSum, sum);
    
}
int main() {
    ll n, sum;
    cin>>n>>sum;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) scanf("%lld", &arr[i]); 
    if(n == 1) {
        if(arr[0] == sum) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    int mid = (arr.size()-1)/2;
    ll cnt = 0;
    vector<ll> allSubsetSum1, allSubsetSum2;
    getSubsetSumArr(arr, 0, mid, allSubsetSum1, 0);
    getSubsetSumArr(arr, mid+1, arr.size()-1,allSubsetSum2, 0);
    
    sort(allSubsetSum2.begin(), allSubsetSum2.end());
    int n1 = allSubsetSum1.size(), n2 = allSubsetSum2.size();
    for(int i=0; i<n1; i++) {
        ll curVal = allSubsetSum1[i];
        ll sumFind = sum - curVal;
        int ind = lower_bound(allSubsetSum2.begin(), allSubsetSum2.end(),sumFind) - allSubsetSum2.begin();
        if(ind == n2) continue;
        if(allSubsetSum2[ind] != sumFind) continue;

        int ind2 = upper_bound(allSubsetSum2.begin(), allSubsetSum2.end(),sumFind) - allSubsetSum2.begin();
        if(ind2 == 0) continue;
        cnt += (ind2 - ind);       // count the duplicate sum elements also, thats why we use the upper_bound and the lower bound.
    }
    cout<<cnt<<endl;
    return 0;
}