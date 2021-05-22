#include<bits/stdc++.h>
using namespace std;
class var {
    public:
    bool isPossible;
    long long costToBuy;
    var(bool a, long long b) {
        isPossible = a;
        costToBuy = b;
    }
};

var isPossibleToBuyKitemsInGivenBudget(vector<int> baseCost, int k, int budget) {
    int n = baseCost.size();
    long long sum = 0;
    vector<long long> costs;

    for(int i=0; i<n; i++) costs.push_back(baseCost[i] + (i+1)*(long long)k);
    sort(costs.begin(), costs.end());

    for(int i=0; i<k; i++)  sum += costs[i];

    if(sum <= budget) return var(true, sum);
    return var(false, LLONG_MIN);
}
void findMaximumSouvenirAtMinCost(vector<int> baseCost, int budget) {
    int n = baseCost.size(), maxSouvenir = 0, s = 0, e = n;
    long long minCost = 0;
    // we can't sort the array here, because actual cost depends on the indices of the souvenier, so if we sort here, we distort the array and not able to get the actual price of ith souvineir. So we have to sort every time for each 'k'.
    
    while(s <= e) {
        int mid = (s+e)/2;
        var checkPossiblity = isPossibleToBuyKitemsInGivenBudget(baseCost, mid, budget);
        if(checkPossiblity.isPossible) {
            minCost = checkPossiblity.costToBuy;
            maxSouvenir = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout<<maxSouvenir<<" "<<minCost<<endl;
} 
int main() {
    int n, budget;
    cin>>n>>budget;
    vector<int> baseCost(n);
    for(int i=0; i<n; i++) {
        cin>>baseCost[i];
    }
    findMaximumSouvenirAtMinCost(baseCost, budget);
    return 0;
}