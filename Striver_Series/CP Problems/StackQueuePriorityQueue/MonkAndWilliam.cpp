#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;


int main() {
    int t;
    t = 1;
    while(t--) {
        int q;
        cin>>q;
        map<int, int> scores;
        for(int i=0; i<q; i++) {
            string query;
            cin>>query;
            if(query == "Push") {
                int n;
                cin>>n;
                scores[n]++;
            } else if(query == "Diff") {
                if(scores.size() == 0) cout<<-1<<endl;
                else {
                    int minVal = (*scores.begin()).first;
                    int maxVal = (*scores.rbegin()).first;
                    cout<<maxVal - minVal<<endl;
                    if(scores.size() == 1) {
                        scores[minVal]--;
                        if(scores[minVal] == 0) scores.erase(minVal);
                    }
                    else {
                        scores[minVal]--;
                        scores[maxVal]--;
                        if(scores[minVal] == 0)  scores.erase(minVal);
                        if(scores[maxVal] == 0) scores.erase(maxVal);
                    }
                }
            } else if(query == "CountHigh") {
                if(scores.size() == 0) cout<<-1<<endl;
                else cout<<(*scores.rbegin()).second<<endl;
                
            } else {
                if(scores.size() == 0) cout<<-1<<endl;
                else cout<<(*scores.begin()).second<<endl;
                
            }
        }
    }
    return 0;
}