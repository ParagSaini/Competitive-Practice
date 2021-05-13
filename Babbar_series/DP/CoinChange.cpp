// Find the no. of ways, we can make change of Cent, Given the smaller notes.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int Ways(vector<int> arr,int cent, unordered_map<string, int>& dp) {
    if(cent < 0) return 0;
    if(cent == 0) return 1;
    if(cent >=1 && arr.size() == 0) return 0;

    string s = to_string(arr.size()) + "|" + to_string(cent);
    int last = arr.size()-1;
    if(dp.count(s)) return dp[s];
    
    int a = Ways(arr, cent - arr[last], dp);
    arr.pop_back();
    int b = Ways(arr, cent, dp);
    
    dp[s] = a + b;
    return dp[s];
    
}
int main()
 {
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
	    int n, cent; 
	    vector<int> arr;
	    unordered_map<string, int> dp;
	    cin>>n;
	    for(int i=0; i<n; i++) {
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    cin>>cent;
	   // int count = 0;
	    cout<<Ways(arr, cent, dp)<<endl;
	    
	}
	return 0;
}