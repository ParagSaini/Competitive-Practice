#include<bits/stdc++.h>
using namespace std;

bool checkCowFitsInCurGap(const vector<int>& arr, int gap, int cows) {
    // fix one cow at starting index.
    int n = arr.size(), left = arr[0];
    cows--;
    for(int i=1; i<n; i++) {
        int curGap = arr[i] - left;
        if(curGap >= gap) {
            left = arr[i];
            cows--;
        }
    }
    if(cows <= 0) return true;      // we can fit the cows within the gap in the barn
    return false;
}

void maximumMinDistance(vector<int> arr, int c) {
    sort(arr.begin(), arr.end());

    int n = arr.size(), minGap = INT_MAX, maxGap = arr[n-1] - arr[0], result; 

    for(int i=1; i<n; i++) minGap = min(minGap, arr[i] - arr[i-1]);

    while(minGap <= maxGap) {
        int curGap = (minGap + maxGap)/2;
        if(checkCowFitsInCurGap(arr, curGap, c)) {
            result = curGap;
            minGap = curGap + 1;
        } else {
            maxGap = curGap - 1;
        }
    }
    cout<<result;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, c;
        cin>>n>>c;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        maximumMinDistance(arr, c);
        cout<<endl;
    }
    return 0;
}