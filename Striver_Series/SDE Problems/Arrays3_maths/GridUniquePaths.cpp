#include<bits/stdc++.h>
using namespace std;


// Optimal Solution using the combinations..
// T.c O(m) or O(n);

 int Ncr(int n, int r) {
    double ans = 1;
    while(r) {
        ans = ans * ((double)n/r);
        n--;
        r--;
    }
    // conversion from double to int, we may loose some decimal point and it may happen that if ans = 56.00.... and after conversion to int it become (int)ans = 55.
    // to avoid this, we take a margin of 0.5, search stackoverflow if required
    int x = (int)(ans + 0.5);
    return x;
}
// see striver video if not clear..
int uniquePaths(int m, int n) {
    int N = m + n - 2;
    int R = n - 1; // or m - 1
    return Ncr(N, R);
}


// Recursive solution and optimised with dp, T.c O(mn);
int uniquePathsHelper(int i, int j, pair<int,int>& destiny, unordered_map<string, int>& dp) {
    
    // boundary conditions
    if(i > destiny.first || j > destiny.second) return 0;
    
    if(i == destiny.first && j == destiny.second) return 1;
    
    string s = to_string(i) + "|" + to_string(j);
    if(dp.count(s)) return dp[s];
    
    // if i move right
    int r = uniquePathsHelper(i, j+1, destiny, dp);
    // if i move down
    int d = uniquePathsHelper(i+1, j, destiny, dp);
    
    dp[s] =  (r + d);
    return dp[s];
}

int uniquePaths(int m, int n) {
    if(m == 0 || n == 0) return 0;
    if(m == 1 && n == 1) return 1;
    unordered_map<string, int> dp;
    pair<int, int> destiny = {(m-1), (n-1)};
    // starting from 0,0
    return uniquePathsHelper(0, 0, destiny, dp);
}

