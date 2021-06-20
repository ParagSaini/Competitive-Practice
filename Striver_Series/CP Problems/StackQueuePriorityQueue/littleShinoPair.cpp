#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// finding the next greater elements.
int countR(vector<int> arr) {
    int n = arr.size(), cnt = 0;
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(st.empty()) st.push(arr[i]);
        else {
            while(!st.empty() && st.top() < arr[i]) {
                cnt++;
                st.pop();
            }
            st.push(arr[i]);
        }
    }
    return cnt;
}
int main() {
    int t;
    // cin>>t;
    t = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        vector<int> temp(arr.rbegin(), arr.rend());  // reversing the array
        cout<<countR(arr) + countR(temp)<<endl;
    }
    return 0;
}