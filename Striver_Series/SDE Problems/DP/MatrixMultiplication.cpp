#include<bits/stdc++.h>
using namespace std;
int fncall = 0;

int MinOperation(vector<int>& mat, int startMat, int endMat, int** dp) {
	fncall++;
	if(startMat == endMat) return 0;
	if(dp[startMat][endMat] != -1) return dp[startMat][endMat];

	int mini = INT_MAX;
	for(int i = startMat; i<endMat; i++) {
		int curOper = MinOperation(mat, startMat, i, dp) + MinOperation(mat, i+1, endMat, dp) + ( mat[startMat] * mat[i+1] * mat[endMat+1]);
		mini = min(mini, curOper);
	}
	dp[startMat][endMat] = mini;
	return dp[startMat][endMat];
}
int main() {
	vector<int> mat = {40, 20, 30, 10, 30};
	int ** dp = new int*[mat.size()-1];
	for(int i=0; i<mat.size()-1; i++) {
		dp[i] = new int[mat.size()-1];
	}
	for(int i=0; i<mat.size()-1; i++) {
		for(int j=0; j<mat.size()-1; j++) dp[i][j] = -1;
	}
	cout<<MinOperation(mat, 0, mat.size()-2, dp)<<endl<<fncall;	
	
	return 0;
}