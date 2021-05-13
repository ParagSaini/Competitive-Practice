#include<bits/stdc++.h>
using namespace std;

// actually a good solution, sort both the arrival and departure arrays in increasing order. and then maintain the two pointer, one traverse the arrival array and another traverse the departure array.

int MinPlatforms(vector<int> arrival, vector<int> departure) {
    if(arrival.size() == 0) return 0;
    
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    
    int i = 0, j = 0;
    int curPlat = 0;
    int maxPlat = 1;
    while(i < arrival.size() && j < departure.size()) {
        if(arrival[i] <= departure[j]) {
            curPlat++;
            maxPlat = max(maxPlat, curPlat);
            i++;
        } else {
            curPlat--;
            j++;
        }
    }
    return maxPlat;
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> arrival;
	    vector<int> departure;
	    for(int i = 0; i<n; i++) {
	        string s;
	        cin>>s;
	        int t = stoi(s);
	        arrival.push_back(t);
	    }
	    for(int i = 0; i < n; i++) {
	        string s;
	        cin>>s;
	        int t = stoi(s);
	        departure.push_back(t);
	    }
	    cout<<MinPlatforms(arrival, departure)<<endl;
	}
	return 0;
}