#include<bits/stdc++.h>
using namespace std;

// Top down Dp solution t.c O(n*m);
int MaxSumHelper(vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp) {
// base case
	if(r >= mat.size() || c < 0 || c >= mat[0].size()) return 0;
	
	if(dp[r][c] != INT_MIN) return dp[r][c];
	int maxSum = mat[r][c];
	int cand1 = MaxSumHelper(mat, r+1, c-1, dp);
	int cand2 = MaxSumHelper(mat, r+1, c+1, dp);
	maxSum += max(cand1, cand2);
	dp[r][c] = maxSum;
	return dp[r][c];

}
int MaxSum(vector<vector<int>>& mat) {
	int row = mat.size();
	int col = mat[0].size();
	vector<vector<int>> dp(row);
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) dp[i].push_back(INT_MIN);
	}
	int maxSum = INT_MIN;
	for(int i=0; i<col; i++) {
		int cand = MaxSumHelper(mat, 0, i, dp);
		maxSum = max(cand, maxSum);
	}
	return maxSum;
}