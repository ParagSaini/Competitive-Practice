#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
const int mod = 1000000007;

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

unordered_map<int, unordered_set<int>> allowedCells; // we can use the map also and store the pair of each i,j of allowed cells.

set<pair<int, int>> visited;
int n = mod-7, m = mod-7;

bool allowed(int r, int c) {
	if(allowedCells.count(r) && allowedCells[r].count(c)) return true;
	return false;
}
void bfs(int x0, int y0, int x1, int y1) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x0, y0));
	visited.insert(make_pair(x0, y0));

	while(!q.empty()) {
		int size = q.size();
		while(size--) {
			int r = q.front().first, c = q.front().second;
			q.pop();

			for(auto dir : dirs) {
				int nR = r + dir.first, nC = c + dir.second;
				if(nR > n || nR < 1 || nC > m || nC < 1 || visited.count(make_pair(nR, nC))) {
					continue;
				}
				if(nR == x1 && nC == y1) {
					// cout<<r<<" "<<c<<endl;
					cnt++;
					cout<<cnt<<endl;
					return;
				}
				if(allowed(nR, nC)) {
					q.push(make_pair(nR, nC));
					visited.insert(make_pair(nR, nC));
				}
			}
		}
		cnt++;
	}
	cout<<-1<<endl;
}
void solve() {
	int x0, y0, x1, y1, n_seg;
	cin>>x0>>y0>>x1>>y1>>n_seg;

	for(int i=0; i<n_seg; i++) {
		int r, a, b;
		cin>>r>>a>>b;
		for(int k=a; k<=b; k++) {
			allowedCells[r].insert(k);
		}
	}
	bfs(x0, y0, x1, y1);
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