#include<bits/stdc++.h>
using namespace std;


void combSum(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
    if(target == 0) {
        result.push_back(combination);
        return;
    }
    if(start >= candidates.size() || target < 0) return;
    
    combination.push_back(candidates[start]);
    combSum(candidates, target - candidates[start], start,combination , result);
    
    
    combination.pop_back();
    combSum(candidates, target, start+1, combination, result);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if(candidates.size() == 0) return result;
    vector<int> combination = {};
    combSum(candidates, target, 0, combination, result);
    return result;
}