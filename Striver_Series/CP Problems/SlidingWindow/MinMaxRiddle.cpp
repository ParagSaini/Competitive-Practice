#include<bits/stdc++.h>
using namespace std;
void maxOutofMinOfWindows(vector<int> arr) {
    // windows varies from 1 to n
    int n = arr.size();
    // create two array next, previous, which contains the next and previous min for each element.
    vector<int> nextSmaller(n), prevSmaller(n), result(n+1, 0);
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(st.empty()) st.push(i);
        else {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()) {
        nextSmaller[st.top()] = n;
        st.pop();
    }
    for(int i=n-1; i>=0; i--) {
        if(st.empty()) st.push(i);
        else {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()) {
        prevSmaller[st.top()] = -1;
        st.pop();
    }

    for(int i=0; i<n; i++) {
        // range 1 to n.
        int range = nextSmaller[i] - prevSmaller[i] - 1;
        result[range] = max(result[range], arr[i]);
    }

    for(int i=n-1; i>=1; i--) {
        result[i] = max(result[i], result[i+1]);
    }
    for(int i=1; i<=n; i++) cout<<result[i]<<" ";
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    maxOutofMinOfWindows(arr);
    return 0;
}