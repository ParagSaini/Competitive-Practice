#include<bits/stdc++.h>
using namespace std;
// function call to see how time complexity effects on using dp and not, On using the top down dp it seems it will not working and it doesn't have any similar subproblems but if you just used it you can see the difference, from O(2^n) to O(n * target).

int fnCall = 0;
bool subsetSum(int N, int arr[], int start, int target, int** dp) {
	fnCall++;
	if(target == 0) return true;
	if(start >= N || target < 0) return false;
	string str = to_string(start) + "|" + to_string(target);
	if(dp[start][target] != -1) return dp[start][target];
    
	// include start in subset
	int a = subsetSum(N, arr, start+1, target-arr[start], dp);
	// not include
	int b = subsetSum(N, arr, start+1, target, dp);	
	dp[start][target] = (a || b);
	return dp[start][target];
}
int main()
{
	int ar[] = {1,5, 11, 5};
	int n = sizeof(ar)/sizeof(int);
	int target = 22;
	int ** dp = new int*[n];
	for(int i=0; i<n; i++) dp[i] = new int[target + 1];
	for(int i=0; i<n; i++) {
		for(int j=0; j<=target; j++) dp[i][j] = -1;
	}
	cout<<subsetSum(n, ar, 0, target, dp);
	cout<<endl<<fnCall<<endl<<target;
	return 0;
}