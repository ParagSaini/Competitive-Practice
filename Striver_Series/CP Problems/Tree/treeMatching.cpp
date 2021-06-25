#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<vector<int>> arr(3*100000);
int n;
vector<int> maxMatching(3*100000);

int solve(int root, vector<int>& visited) {
	int ans = 0;
	vector<pair<int, int>> matching;
	int matchingSum = 0;
	visited[root] = 1;

	for(auto child : arr[root]) {

		if(visited[child] == 0) {
			int matches = solve(child, visited);
			matching.push_back(make_pair(child, matches));
			matchingSum += matches;
		}
	}
	for(int i=0; i<matching.size(); i++) {
		int curChild = matching[i].first;
		int sum = 0;
		for(int k = 0; k < arr[curChild].size(); k++) {
			sum += maxMatching[arr[curChild][k]];
		}
		ans = max(ans, matchingSum - matching[i].second + 1 + sum);
	}
	visited[root] = 0;
	return maxMatching[root] = ans;
}

void init_code() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main() {
	
	init_code();

	int t;
	// cin>>t;
	t = 1;
	while(t--) {
		cin>>n;
		for(int i=1; i<=(n-1); i++) {
			int a, b;
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		vector<int> visited(n+1, 0);
		cout<<solve(1, visited)<<endl;
	}
	return 0;
}