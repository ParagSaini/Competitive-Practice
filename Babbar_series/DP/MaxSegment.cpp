/* Given an integer N denoting the Length of a line segment. you need
to cut the line segment in such a way that the cut length of a line 
segment each time is integer either x , y or z. and after performing 
all cutting operation the total number of cutted segments must be 
maximum. */
int Maxthree(int a, int b, int c) {
    if( a > b) {
        if( a > c) return a;
        return c;
    } else {
        if( b > c) return b;
        return c;
    }
}
int MaxSegment(int n, int x, int y, int z, unordered_map<int, int>& dp) {
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(dp.count(n)) return dp[n];
    int a = MaxSegment(n-x, x, y, z, dp);
    int b = MaxSegment(n-y, x, y, z, dp);
    int c = MaxSegment(n-z, x, y, z, dp);
    if(a < 0) a = -1;
    else  a++;
    if( b< 0) b = -1;
    else b++;
    if(c<0) c = -1;
    else c++;
    
    dp[n] = Maxthree(a, b, c);
    return dp[n];
    
    
}