#include<bits/stdc++.h>
using namespace std;
// it is given that we don't have to minimise the number of swaps. but swaps should be <= n;

int findMinimumInd(vector<int> arr, int s) {
    int val = arr[s], n = arr.size(), ind = s;
    for(int i=s; i<n; i++) {
        if(arr[i] < val) {
            val = arr[i];
            ind = i;
        }
    }
    return ind;
}
void findNumberOfSwaps(vector<int> arr) {
    int n = arr.size();
    vector<pair<int, int>> swaps;

    for(int i=0; i<n; i++) {
        int ind = findMinimumInd(arr, i);
        swap(arr[i], arr[ind]);
        swaps.push_back(make_pair(i, ind));
    }

    cout<<swaps.size()<<endl;
    for(int i=0; i<swaps.size(); i++) {
        cout<<swaps[i].first<<" "<<swaps[i].second<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    findNumberOfSwaps(arr);
    return 0;
}