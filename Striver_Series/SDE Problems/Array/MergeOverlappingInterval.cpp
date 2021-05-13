#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return intervals;
    
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    
    int s = intervals[0][0];
    int e = intervals[0][1];
    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i][0] > e) {
            result.push_back({s,e});
            s = intervals[i][0];
            e = intervals[i][1];
        } else {
            e = max(e, intervals[i][1]);
        }
    }
    result.push_back({s,e});
    return result;
}