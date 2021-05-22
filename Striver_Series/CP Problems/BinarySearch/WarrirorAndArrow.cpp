#include<bits/stdc++.h>
using namespace std;

void findWarriorAliveEveryMinute(const vector<int>& warriorStrength, const vector<long long>& arrows) {
    int n = warriorStrength.size(), q = arrows.size();
    long long arrowUsed = 0;
    vector<long long> prefixStrengthSum(n);   // this is sorted array without any duplicates.
    prefixStrengthSum[0] = warriorStrength[0];

    for(int i=1; i<n; i++) {
        prefixStrengthSum[i] = prefixStrengthSum[i-1] + warriorStrength[i];
    }

    for(int i=0; i<q; i++) {
        // arrowUsed is very useful, as if we killed some warrior strength, and now we don't change the prefixStrengthSum array for remaing warrior, so we have to add the arrowUsed to the curArrow to counter that thing.

        long long arrow = arrows[i] + arrowUsed;
        int ind= lower_bound(prefixStrengthSum.begin(), prefixStrengthSum.end(), arrow) - prefixStrengthSum.begin();

        if(ind == n || (ind == n-1 && prefixStrengthSum[ind] == arrow)) {    // arrow will destroy all the warriors.
            cout<<n<<endl;
            arrowUsed = 0;
        } else if(prefixStrengthSum[ind] == arrow) {  // we get the exact arrow == warriorStrength.
            int warriorAlive = n-ind-1;
            arrowUsed = arrow;
            cout<<warriorAlive<<endl;
        } else {
            int warriorAlive = n - ind;
            arrowUsed = arrow;
            cout<<warriorAlive<<endl;
        }
    }
}
int main() {
    int n, q;
    cin>>n>>q;
    vector<int> warriorStrength(n);
    vector<long long> arrows(q);
    for(int i=0; i<n; i++) {
        cin>>warriorStrength[i];
    }
    for(int i=0; i<q; i++) {
        cin>>arrows[i];
    }
    findWarriorAliveEveryMinute(warriorStrength, arrows);
    return 0;
}