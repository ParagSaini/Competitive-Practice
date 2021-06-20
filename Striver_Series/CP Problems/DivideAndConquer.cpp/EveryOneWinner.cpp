#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        vector<int> arr;
        scanf("%d", &n);
        set<int> reqNums;   // set for unique and sorted numbers.
        for(int participants=1; ; participants++) {
            int ratingPerParticipant = (n/participants);
            if(ratingPerParticipant < participants) break;
            
            reqNums.insert(ratingPerParticipant);
            reqNums.insert(participants); 
        }
        reqNums.insert(0);
        cout<<reqNums.size()<<endl;
        for(auto it : reqNums) printf("%d ", it);
        cout<<endl;
    }
    return 0;
}