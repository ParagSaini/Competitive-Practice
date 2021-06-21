// the nums[i] >= 1 && nums[i] <= 100, for all values, therefore using to solve the problem. Therefore see the constraint carefully.

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> prefix(n, vector<int>(101, 0));
        prefix[0][nums[0]]++;
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<=100; j++) {
                if(j == nums[i]) prefix[i][j] = prefix[i-1][j] + 1;
                else prefix[i][j] = prefix[i-1][j];
            }
        }
        
        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            vector<int> temp(101, 0);
            int minDiff = INT_MAX;
            int prev = -1;
            for(int k=1; k<=100; k++) {
                if(l == 0) temp[k] = prefix[r][k];
                else temp[k] = prefix[r][k] - prefix[l-1][k];
            }
            
            for(int k=1; k<=100; k++) {
                if(temp[k] > 0) {
                    if(prev == -1) prev = k;
                    else {
                        minDiff = min(minDiff, abs(prev - k));
                        prev = k;
                    }
                }
            }
            if(minDiff == INT_MAX) ans.push_back(-1);
            else ans.push_back(minDiff);
        }
        return ans;
    }
};