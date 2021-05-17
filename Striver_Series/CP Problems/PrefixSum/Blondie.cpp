#include<bits/stdc++.h>
using namespace std;

void countBullets(vector<int> criminals) {
	long long prefixSum = (long long)criminals[0];
	cout<<criminals[0]<<" ";
	for(int i=1; i<criminals.size(); i++) {
		int curCriminals = criminals[i];
		if(curCriminals == -1) {
			int areaVisited = i;
			long long criminalsKilled = prefixSum;
			int no_of_criminals = (int)((criminalsKilled)/(long long)areaVisited);
			cout<<no_of_criminals<<" ";
			prefixSum += (long long)no_of_criminals;
		} else {
			cout<<curCriminals<<" ";
			prefixSum += (long long)curCriminals;
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n, i=0;
		cin>>n;
		vector<int> criminals(n);
		while(n--) {
			cin>>criminals[i];
			i++;
		}
		countBullets(criminals);
	}
	return 0;
}