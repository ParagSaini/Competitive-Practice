// link: https://practice.geeksforgeeks.org/problems/stock-span-problem/0#
#include<bits/stdc++.h>
using namespace std;

// t.c O(n) && s.c O(n)
void PrintSpan(vector<int>& arr) {
    stack<pair<int, int>> st;
    for(int i=0; i<arr.size(); i++) {
        int cur = arr[i];
        int count = 1;
        if(st.empty()) st.push({cur, 1});
        else {
            while(!st.empty() && st.top().first <= cur) {
                count += (st.top().second);
                st.pop();
            }
            st.push({cur, count});
        }
        cout<<(st.top().second)<<" ";
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int i=0; i<n; i++) {
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    PrintSpan(arr);
	    cout<<endl;
	}
	return 0;
}