#include<bits/stdc++.h>
using namespace std;

class weightVal {
    public:
    int weight;
    int value;
    double ratio;
    weightVal(int val, int wei) {
        weight = wei;
        value = val;
        ratio = (double)val/(double)wei;
    }
};
bool compare(weightVal a, weightVal b) {
    return a.ratio > b.ratio;
}
// to round off the value upto two decimal.
void roundOffTwodecimal(double& ans) {
    ans = ( (int)(ans * 100.0 + 0.5) /100.0 );
}
double MaxValue(vector<weightVal> ar, int maxW) {
    if(ar.size() == 0) return 0;
    // sorting according to the ratio of value and weight in decreasing order.
    sort(ar.begin(), ar.end(), compare);
    
    int i = 0;
    double ans = 0;
    while(maxW != 0 && i <= ar.size()-1) {
        if(ar[i].weight >= maxW) {
            ans += (ar[i].ratio * (double)maxW );
            break;
        } else {
            ans += (double)ar[i].value;
            maxW = maxW - ar[i].weight;
        }
        i++;
    }
    roundOffTwodecimal(ans);
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n, maxW;
	    cin>>n>>maxW;
	    vector<weightVal> ar;
	    for(int i=0; i<n; i++) {
	        int val, w;
	        cin>>val>>w;
	        weightVal temp(val, w);
	        ar.push_back(temp);
	    }
	    cout<<MaxValue(ar, maxW)<<endl;
	}
	return 0;
}