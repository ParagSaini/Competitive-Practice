#include<bits/stdc++.h>
using namespace std;
// array is much faster than the vector, so use array in any competitive exan
int MaxValue(int val[],int weights[], int capacity, int start, int** dp, int n) {
    if(capacity <= 0 || start >= n) return 0;
    if(dp[start][capacity] != -1) return dp[start][capacity];

    // include the starting element
    int _val1 = 0;
    if(capacity >= weights[start]) 
        _val1 = val[start] + MaxValue(val, weights, capacity - weights[start], start+1, dp, n);
    // exclude the starting element
    int _val2 = MaxValue(val, weights, capacity, start+1, dp, n);
    dp[start][capacity] = max(_val1, _val2);
    return dp[start][capacity];
}
int main()
 {
	int t;
	cin>>t;
	while(t--) {
	    int capacity, n;
	    int* item_vals;
	    int* item_weights;
	    cin>>n>>capacity;
	    item_vals = new int[n];
	    item_weights = new int[n];
	    int** dp; 
        dp = new int*[n]; 
    
        // loop to create the table dynamically 
        for (int i = 0; i < n; i++) 
            dp[i] = new int[capacity + 1]; 
    
        // loop to initially filled the table with -1  
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < capacity + 1; j++) 
                dp[i][j] = -1; 
        
        for(int i=0; i<n; i++) {
            int _val;
            cin>>_val;
            item_vals[i] = _val;
        }
        for(int i=0; i<n; i++) {
            int _weight;
            cin>>_weight;
            item_weights[i] = _weight;
        }
        cout<<MaxValue(item_vals, item_weights, capacity, 0, dp, n)<<endl;
    }
	return 0;
}