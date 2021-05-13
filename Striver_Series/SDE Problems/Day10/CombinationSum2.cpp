#include<bits/stdc++.h>
using namespace std;

void combHelper(vector<int>& candidates, int start, int target, vector<int>& comb, vector<vector<int>>& result, bool prevTaken) {
    if(target == 0) {
        result.push_back(comb);
        return;
    }
    if(start >= candidates.size() || target < 0) return;
    
    // we would skip the number if the prev number is same as current and prev_Number is not taken.

    if(start != 0 && prevTaken == false && candidates[start] == candidates[start-1]) {
        combHelper(candidates, start+1, target, comb, result, false);
        return;
    } 
    
    comb.push_back(candidates[start]);
    combHelper(candidates, start+1, target - candidates[start], comb, result, true);
    
    comb.pop_back();
    combHelper(candidates, start+1, target, comb, result, false);
            
    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> combination = {};
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    int start = 0;
    bool prevTaken = false;
    if(candidates.size() == 0 ) return result;
    combHelper(candidates, start, target, combination, result, prevTaken);
    return result;
}