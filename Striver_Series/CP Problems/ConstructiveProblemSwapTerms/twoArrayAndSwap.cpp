#include<bits/stdc++.h>
using namespace std;

void findMaxSum(vector<int> a, vector<int> b,int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int s1 = 0, e2 = b.size()-1, sum = 0;;
    while(k--) {
        if(a[s1] < b[e2]) {
            swap(a[s1], b[e2]);
            s1++;
            e2--;
        } else break;
    }    
    for(int i=0; i<a.size(); i++) sum += a[i];
    cout<<sum<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i=0; i<n; i++) {
            cin>>b[i];
        }
        findMaxSum(a, b, k);
    }
    return 0;
}