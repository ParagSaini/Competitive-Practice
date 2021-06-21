//https://leetcode.com/discuss/general-discussion/1284202/weekly-contest-246
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int ind = -1;
        string res;
        for(int i=n-1; i>=0 ; i--) {
            int odd = num[i] - '0';
            
            if(odd %2 != 0) {
                ind = i;
                break;
            }
        }
        if(ind == -1) return {};
        for(int i=0; i<=ind; i++) {
            res.push_back(num[i]);
        }
        return res;
    }
};