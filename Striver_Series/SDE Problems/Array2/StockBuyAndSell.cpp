#include<bits/stdc++.h>
using namespace std;


// Mine Approach.. 
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    
    int maxPro = 0;
    int mini = prices[0];
    for(int i=1; i<prices.size(); i++) {
        int prof = prices[i] - mini;
        if(prof > maxPro) maxPro = prof;
        if(prices[i] < mini) mini = prices[i];
    }
    return maxPro;
}


// Small variation to kadane's algorithm

int maxProfit(vector<int>& prices) {
    int sum = 0;
    int maxPro = 0;
    for(int i = 1; i < prices.size(); i++) {
        // lets say a b c, in sum you have b-a, and sum > 0 means a is smallest tillnow, now if you calcaulta c-a, you get your answer, to calculate that simply (b-a) + (c- b);
        sum += (prices[i] - prices[i-1]);
        if(maxPro < sum) maxPro = sum;
        if(sum < 0) sum = 0;
    }
    return maxPro;
}