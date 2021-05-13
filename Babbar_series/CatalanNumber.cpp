#include<iostream>
#include<unordered_map>
#include<string>
// boost libraray for stroing 64 bit number also, not working in vs code but worked in gfg.
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;
cpp_int ncr(int n, int r, unordered_map<string, cpp_int>& dp) {
    string s = to_string(n) + "|" + to_string(r);
    if(n == r || r == 0) {
        dp[s] = 1;
        return dp[s];
    }
    if(dp.count(s)) return dp[s];
    dp[s] = ncr(n-1, r-1, dp) + ncr(n-1, r, dp);
    return dp[s];
}
cpp_int catalanNum(int n) {
    if(n == 0 || n == 1) return 1;
    int N = n;
    unordered_map<string, cpp_int > dp;
    cpp_int ans = ncr(2*N, N, dp) / (N+1);
    return ans;
}