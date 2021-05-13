#include<bits/stdc++.h>
using namespace std;

int maxThree(int a, int b, int c) {
    return max(max(a, b), c);
}
int MaxSegment(int n, int x, int y, int z, int* dp) {
    if(n < 0) return -1;
    if(n == 0) return 0;
    
    if(dp[n] != INT_MIN) return dp[n];
    
    int xCut = MaxSegment(n-x, x, y, z, dp);
    int yCut = MaxSegment(n-y, x, y, z, dp);
    int zCut = MaxSegment(n-z, x, y, z, dp);
    
    int maxCut = maxThree(xCut, yCut, zCut);
    
    if(maxCut < 0) dp[n] = -1;    // not able to cut the rod
    else dp[n] = (maxCut+1);
    
    return dp[n];
}
int maximizeTheCuts(int n, int x, int y, int z)
{   
    int* dp = new int[n+1];
    // not initialise with -1 because we have a result -1, we don't distinguish between which -1 is for which purpose
    for(int i=0; i<(n+1); i++) dp[i] = INT_MIN;
    int ans =  MaxSegment(n, x, y, z, dp);
    if(ans < 0) return 0;
    return ans;
}