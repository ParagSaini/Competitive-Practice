#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Time complexity = O(n*m) with Dynamic programming
int MaxThree(int a, int b, int c) {
    if(a > b) {
       if(a > c) return a;
       return c;
    }
    else {
        if( b > c) return b;
        return c;
    }
}
int MaxAmount(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if(row < 0 || row > (matrix.size()-1) || col > (matrix[0].size()-1)) {
        return 0;
    }
    if(dp[row][col] != -1) {
        return dp[row][col];
    }
    int Dup = MaxAmount(row-1, col+1, matrix, dp);
    int R = MaxAmount(row, col+1, matrix, dp);
    int Ddown = MaxAmount(row+1, col+1, matrix, dp);
    int ans =  matrix[row][col] + MaxThree(Dup, R, Ddown);
    dp[row][col] = ans;
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
	    int row,col;
	    cin>>row>>col;
	    vector<vector<int>> matrix(row);
	    vector<vector<int>> dp(row);
	    for(int i=0; i<row; i++) {
	        for(int j=0; j<col; j++) {
	            int n;
	            cin>>n;
	            matrix[i].push_back(n);
	            dp[i].push_back(-1);
	        }
	    }
	    int ans = INT_MIN;
	    for(int i=0; i<row; i++) {
	        int cost = MaxAmount(i, 0, matrix, dp);
	        if(cost > ans ) {
	            ans = cost;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}