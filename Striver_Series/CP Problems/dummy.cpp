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
class comp1{
	public:
	bool operator()(int a, int b) {
		return (a>b);
	}
};
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
	// int x;
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	double y;
	float z;
	char ch;
	// long long x;
	char s[100];
	// scanf("%lld", &x);
	// cout<<x<<endl;
	int** arr = new int* [20];
	for(int i=0; i<20; i++) {
		arr[i] = new int[20];
	}
	for(int i=0; i<20; i++) {
		for(int j=0; j<20; j++) {
			arr[i][j] = i+j;
		}
	}
	for(int i=0; i<20; i++) {
		for(int j=0; j<20; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 