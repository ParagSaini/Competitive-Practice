#include<bits/stdc++.h>
using namespace std;

// this question is very much similar to the array manipulation question, very good concept
void findMaxDarkness(vector<pair<int, int>> queries, int p) {
    vector<int> prefixArr(p+1, 0); // 0 to p
    int contCount = 0, maxCount = INT_MIN;
    long long sum = 0;

    for(int i=0; i<queries.size(); i++) {
        int x = queries[i].first, r = queries[i].second;
        int left, right;
        left = ((x-r) < 0) ? 0 : (x-r);
        right = x+r;

        prefixArr[left]++;
        if( (right +1) <= p) prefixArr[right+1]--;
    }

    for(int i=0; i<=p; i++) {
        sum += (long long)prefixArr[i];
        if(sum == 0 || sum > 1) contCount++;
        else {
            maxCount = max(maxCount, contCount);
            contCount = 0;
        }
    }
    maxCount = max(contCount, maxCount);
    cout<<maxCount<<endl;
}
int main() {
    int n, p;
    cin>>n>>p;
    vector<pair<int, int>> queries;
    while(n--) {
        int x, r;
        cin>>x>>r;
        queries.push_back(make_pair(x,r));
    }
    findMaxDarkness(queries, p);
    return 0;
}