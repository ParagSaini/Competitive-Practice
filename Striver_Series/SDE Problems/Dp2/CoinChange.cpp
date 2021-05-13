#include<bits/stdc++.h>
using namespace std;

// Using the recursion, top down Approach
int coinChangeHelper(vector<int>& coins, int amount, unordered_map<int, int>& dp) {
    if(amount < 0) return INT_MAX;
    // we make the change
    if(amount == 0) return 0;
    
    if(dp.count(amount)) return dp[amount];
    
    // mincoins contains the minimum coins required to make the current amount.
    int minCoins = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int c = coinChangeHelper(coins, amount - coins[i], dp);
        minCoins = min(minCoins, c);
    }
    if(minCoins == INT_MAX) dp[amount] = INT_MAX;
    else dp[amount] = (1 + minCoins);
    return dp[amount];
    
}
int coinChange(vector<int>& coins, int amount) {
    unordered_map<int, int> dp;
    int result = coinChangeHelper(coins, amount, dp);
    if(result == INT_MAX) return -1;
    return result;
}



// Bottom Up approach Tabulation method;
int coinChange(vector<int>& coins, int amount) {
    int dpTable[coins.size()][amount+1];
    int row = coins.size();
    int col = amount+1;
    // initialising the first column;
    for(int i=0; i<row; i++) {
        dpTable[i][0] = 0;
    }
    //initialising the first row
    for(int i=1; i<col; i++) {
        if(i % coins[0] != 0) dpTable[0][i] = -1;
        else dpTable[0][i] = i/coins[0];
    }
    
    for(int i=1; i<row; i++) {
        int CoinValue = coins[i];
        for(int amt=1; amt<col; amt++) {
            int aboveVal = dpTable[i-1][amt];
            if(amt < CoinValue) dpTable[i][amt] = aboveVal;
            else {
                if(dpTable[i][amt-CoinValue] == -1) dpTable[i][amt] = aboveVal;
                else{
                    if(aboveVal == -1) dpTable[i][amt] = 1 + dpTable[i][amt-CoinValue];
                    else dpTable[i][amt] = min(aboveVal, 1 + dpTable[i][amt-CoinValue]);
                }
            }
        }
    }

    return dpTable[row-1][col-1];
}