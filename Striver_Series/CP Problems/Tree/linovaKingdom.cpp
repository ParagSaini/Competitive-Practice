#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;
vector<vector<int>> edges(3*100000);
vector<pair<int, pair<int, int>>> ancDec;
vector<int> visited(3*100000, 0);
int n, k;

bool comp(pair<int, pair< int, int>> a, pair< int, pair<int, int>> b){
	if(a.second.first == b.second.first) {
		return (a.second.second < b.second.second);
	}
	if(a.second.first > b.second.first) return true;
	return false;

}
void findHappiness(unordered_set<int>& indusNode, int ancestors, int root, int& happiness) {

	if(indusNode.count(root)) happiness += ancestors;

	visited[root] = 1;
	for(auto child : edges[root]) {
		if(visited[child] == 0) {
			if(indusNode.count(root)) {
				findHappiness(indusNode, ancestors, child, happiness);
			}
			else {
				findHappiness(indusNode, ancestors+1, child, happiness);
			}
		}
	}
	visited[root] = 0;
}
int getDecendants(int n_par, int root) {

	visited[root] = 1;
	int cnt = 0;
	for(auto child : edges[root]) {
		if(visited[child] == 0) {
			cnt += 1 + getDecendants(n_par+1, child);
		}
	}
	visited[root] = 0;
	ancDec.push_back(make_pair(root, make_pair(n_par, cnt)));
	return cnt;
}
void solve() {
	cin>>n>>k;
	int happiness = 0;

	for(int i=1; i<=(n-1); i++) {
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	getDecendants(0, 1);
	sort(ancDec.begin(), ancDec.end(), comp);
	for(auto it : ancDec) {
		cout<<it.first<<"->"<<it.second.first<<" "<<it.second.second<<endl;
	}
	unordered_set<int> ansNode;
	for(int i=0; i<k; i++) ansNode.insert(ancDec[i].first);
	findHappiness(ansNode, 0, 1, happiness);
	cout<<happiness<<endl;
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
		solve();
	}
	return 0;
}