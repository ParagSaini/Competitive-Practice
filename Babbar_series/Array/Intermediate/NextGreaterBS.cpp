#include<bits/stdc++.h>
using namespace std;
int NextGreater(vector<int> ar, int t) {
    int s = 0, e = ar.size()-1;
    if(t > ar[e]) return -1;
    while(s <= e) {
        int mid = (s+e) /2;
        if(ar[mid] < t) {
            s = mid+1;
        }else {
            e = mid-1;
        }
    }
    return ar[s];
}
int main() {
    vector<int> ar = {2, 5, 8, 11, 14, 17, 20};
    int t = 6;
    cout<<NextGreater(ar, t);
    return 0;
}