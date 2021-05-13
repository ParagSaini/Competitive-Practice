#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
int LCS(string s1, string s2, int ind1, int ind2, unordered_map<string, int>& dp) {
    if(ind1 > s1.length()-1 || ind2 > s2.length()-1) return 0;
    string s = to_string(ind1) + "|" + to_string(ind2);
    if(dp.count(s)) return dp[s];
    int count = 0;
    if(s1[ind1] == s2[ind2]) {
        count = 1 + LCS(s1, s2, ind1 + 1, ind2 + 1, dp);
    } else {
        count = max(LCS(s1, s2, ind1 + 1, ind2, dp), LCS(s1, s2, ind1, ind2 + 1, dp));
    }
    dp[s] =  count;
    return dp[s];
    
}
// string LCS(string s1, string s2, int ind1, int ind2, unordered_map<string, string>& dp) {
//     if(ind1 > s1.length()-1 || ind2 > s2.length()-1) return "";
//     string s = to_string(ind1) + "|" + to_string(ind2);
//     if(dp.count(s)) return dp[s];
//     string result;
//     if(s1[ind1] == s2[ind2]) {
//         result.push_back(s1[ind1]);
//         string r = LCS(s1, s2, ind1 + 1, ind2 + 1, dp);
//         result.append(r);
//     } else {
//         string r1 = LCS(s1, s2, ind1 + 1, ind2, dp);
//         string r2 = LCS(s1, s2, ind1, ind2 + 1, dp);
//         if(r1.length() > r2.length()) {
//             result = r1;
//         } else result = r2;
//     }
    
//     dp[s] =  count;
//     return dp[s];
// }
int main()
 {
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
	    int n1, n2;
	    string s1, s2;
	    cin>>n1>>n2;
	    cin>>s1>>s2;
	    unordered_map<string, int> dp;
	    cout<<LCS(s1, s2, 0, 0, dp)<<endl;
	}
	return 0;
}