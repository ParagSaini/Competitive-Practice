#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> arr) {
	int n = arr.size();
	unordered_set<int> repeat;
	for(int i=0; i<n; i++) repeat.insert(arr[i]);
	for(int i=0; i<n && n <= 300; i++) {
		for(int j=0; j<n && n <= 300; j++) {
			if(i != j) {
				int diff = abs(arr[i] - arr[j]);
				if(!repeat.count(diff)) {
					arr.push_back(diff);
					repeat.insert(diff);
					n++;
				}
			}
		}
	}
	if(n > 300) cout<<"NO"<<endl;
	else {
		cout<<arr.size()<<endl;
		for(auto it : arr) cout<<it<<" ";
	}
}
bool comp(int a, int b) {
	return (a>b);
}
int main() {
	// int t;
	// cin>>t;
	// while(t--) {
	// 	int n;
	// 	cin>>n;
	// 	vector<int> arr(n);
	// 	for(int i=0; i<n; i++) cin>>arr[i];
	// 	if(n == 2 && arr[0] == 3 && arr[1] == 4) {
	// 		cout<<5<<endl;
	// 		cout<<"1 2 3 4 5"<<endl;
	// 	} else 
	// 	solve(arr);
	// }
	int x;
	double y;
	float z;
	char ch;
	char s[100];
	// scanf("%lf", &y);
	// cout<<y<<endl;
	vector<int> arr = {1,3,5, 1,6,43};
	sort(arr.begin(), arr.end(), greater<int>());
	for(auto it : arr) cout<<it<<" ";
	return 0;
} 