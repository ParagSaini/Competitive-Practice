#include<bits/stdc++.h>
using namespace std;
void calculateCasualities(const vector<int>& enemyPower, int bishuPower, const vector<int>& prefixPower) {
    int enemyKilled, enemyPowerSum;

    enemyKilled = upper_bound(enemyPower.begin(), enemyPower.end(), bishuPower) - enemyPower.begin();

    if(enemyKilled-1 >= 0) enemyPowerSum = prefixPower[enemyKilled-1];

    cout<<enemyKilled<<" "<<enemyPowerSum<<endl;
}
int main() {
    int n,q;
    cin>>n;
    vector<int> enemyPowers(n);
    vector<int> prefixPower(n);
    for(int i=0; i<n; i++) {
        cin>>enemyPowers[i];
    }
    // sorting is important to apply the binary searches. 
    sort(enemyPowers.begin(), enemyPowers.end());

    prefixPower[0] = enemyPowers[0];
    for(int i=1; i<n; i++) {
        prefixPower[i] = prefixPower[i-1] + enemyPowers[i];
    }
    cin>>q;
    for(int i=0; i<q; i++) {
        int bishuPower;
        cin>>bishuPower;
        calculateCasualities(enemyPowers, bishuPower, prefixPower);
    }
    return 0;
}