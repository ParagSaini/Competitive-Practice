// to find the is A and B are interleave of C or not?
// This is a recursion solution, but we can use Dp to get Time Complexity of O(N*M) 
// N = length of string A, M = length of string B.
bool isInterleave(string A, string B, string C) 
{
    if(A.length() == 0 && B.length() == 0 && C.length() == 0) return true;
    if(C.length() == 0) return false;
    bool first = (A.length() != 0 && A[0] == C[0] && isInterleave(A.substr(1), B, C.substr(1)));
    bool second (B.length() != 0 && B[0] == C[0] && isInterleave(A, B.substr(1), C.substr(1)));
    return first || second ;
}

// After applying Dp

bool isleave(string A, string B, string C, unordered_map<string, bool>& dp) 
{
    if(A.length() == 0 && B.length() == 0 && C.length() == 0) return true;
    if(C.length() == 0) return false;
    string str = A + "|" + B +  "|" + C;
    if(dp.count(str)) return dp[str];

    bool first = (A.length() != 0 && A[0] == C[0] && isleave(A.substr(1), B, C.substr(1), dp));
    bool second (B.length() != 0 && B[0] == C[0] && isleave(A, B.substr(1), C.substr(1), dp));
    return dp[str] = (first || second) ;
}
