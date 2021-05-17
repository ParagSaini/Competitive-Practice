#include<bits/stdc++.h>
using namespace std;


// Mine Approach.. 
//keep track of the minimum value, to get the maximum profit.
// t.c O(n) && s.c O(1)
int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int maxPro = 0;
    for(int i=1; i<prices.size(); i++) {
        int curPrice = prices[i];
        if(curPrice >= mini) maxPro = max(maxPro, curPrice - mini);
        else mini = curPrice;
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