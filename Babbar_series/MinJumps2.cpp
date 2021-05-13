#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int MinJumps(vector<int> ar) {
    int jump = 1;
    int maxReachableIndex = ar[0];
    int upperbound = ar[0];
    if(ar[0] == 0) return -1;
    
    for(int i=1; i<(ar.size()-1); i++) {
        if(ar[i] == 0 && maxReachableIndex <= i) {
            return -1;
        }
        if(i > upperbound) {
            jump++;
            upperbound = maxReachableIndex;
        }
        maxReachableIndex = max(maxReachableIndex, i+ar[i]);
    }
    return jump;
}
int main()
 {
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    vector<int> ar;
	    for(int i=0; i<n; i++) {
	        int temp;
	        cin>>temp;
	        ar.push_back(temp);
	    }
	    cout<<MinJumps(ar)<<endl;
	}
	return 0;
}