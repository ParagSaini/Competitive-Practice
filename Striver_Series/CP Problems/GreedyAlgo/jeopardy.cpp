#include<bits/stdc++.h>
using namespace std;

/* to get the optimal max Points, we have to make sure that R1 team couldn't answer any question and R2 will answer all the questions. To maximise it, first answer the non auction question, and after that sort the auction question price in descending order and make the auction value as high as possible and add to the points of the r2 team. */

bool comp(int a, int b) {
    return (a>b);
}
int main() {

    int n, m;
    cin>>n>>m;
    vector<int> prices(n);
    unordered_set<int> auctionQInd;
    vector<int> auctionQPrice, regularQPrice;

    for(int i=0; i<n; i++) scanf("%d", &prices[i]);
    for(int i=0; i<m; i++) {
        int ind;
        scanf("%d", &ind);
        auctionQInd.insert(ind-1);  // 0 based indexing
    }
    for(auto it : auctionQInd) auctionQPrice.push_back(prices[it]);
    for(int i=0; i<n; i++) {
        if(!auctionQInd.count(i)) {
            regularQPrice.push_back(prices[i]);
        }
    }
    
    sort(auctionQPrice.begin(), auctionQPrice.end(), greater<int>());  // in descending order

    long long maxPointsR2 = 0;
    for(int i=0; i<regularQPrice.size(); i++) maxPointsR2 += regularQPrice[i];
    
    for(int i=0; i<auctionQPrice.size(); i++) {
        if(maxPointsR2 >= (long long)auctionQPrice[i]) {
            maxPointsR2 *= 2;
        } else {
            maxPointsR2 += auctionQPrice[i];
        }
    }
    cout<<maxPointsR2<<endl;
    return 0;
}