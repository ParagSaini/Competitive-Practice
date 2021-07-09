#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p32;
const ll mod = 1000000007;

ll calMoves(ll x, ll y, vector<vector<pair<ll, ll>>>& mat, ll k) {
	ll ans = LLONG_MIN;
	for(ll i=x; i>(x-k); i--) {
		for(ll j=y; j>(y-k); j--) {
			ans = max(ans, mat[i][j].second);
		}
	}
	return ans;
}
void solve() {
	ll n, m, k;
	cin>>n>>m>>k;
	vector<vector<pair<ll, ll>>> mat(n, vector<pair<ll,ll>>(m));

	// alice = 1, bob = 2, -1, nothing
	bool aliceTurn = true;
	ll move = 1;
	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			ll a, b;
			cin>>a>>b;
			a--; b--;
			if(aliceTurn) {
				mat[a][b] = make_pair(1, move);
			}
			else {
				mat[a][b] = make_pair(2, move);
			}
			aliceTurn = !aliceTurn;
			move++;
		}
	}
	for(auto vec : mat) {
		for(auto it : vec) cout<<it.first<<"-"<<it.second<<" ";
			cout<<endl;
	}
	vector<vector<ll>> solution(n, vector<ll>(m, 1));
	// second is move
	// for(ll i=0; i<n; i++) {
	// 	// solution[i][0] = make_pair(1, mat[i][0].second);
	// 	solution[i][0] = 1;
	// }
	// for(ll i=1; i<m; i++) {
	// 	// solution[0][i] = make_pair(1, mat[0][i].second);
	// 	solution[0][i] = 1;
	// }

	for(ll i=1; i<n; i++) {
		for(ll j=1; j<m; j++) {
			ll cur = mat[i][j].first;

			if(mat[i-1][j].first == cur && mat[i][j-1].first == cur && mat[i-1][j-1].first == cur) {

				ll size = min({solution[i-1][j], solution[i][j-1], solution[i-1][j-1]}) + 1;

				// ll moves = max({solution[i-1][j].second, solution[i][j-1].second, solution[i-1][j-1].second, mat[i][j].second});

				// solution[i][j] = make_pair(size, moves);
				solution[i][j] = size;
			}
			// else {
			// 	// solution[i][j] = make_pair(1, mat[i][j].second);
			// 	solution[i][j] = 1;
			// }
		}
	}
	// cout<<endl<<endl;
	// for(auto vec : solution) {
	// 	for(auto it : vec) cout<<it<<" ";
	// 		cout<<endl;
	// }
	pair<ll, ll> ans;
	ll min_Move = LLONG_MAX;

	for(ll i=0; i<n; i++) {
		for(ll j=0; j<m; j++) {
			if(solution[i][j] == k ) {
				ll curMove = calMoves(i, j, mat, k);
				if(curMove < min_Move) {
					min_Move = curMove;
					ans = make_pair(i, j);
				}
			}
		}
	}
	if(min_Move == LLONG_MAX) cout<<"Draw"<<endl;
	else {
		if(mat[ans.first][ans.second].first == 1) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}

}

void init_code() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
int main() {
	
	init_code();

	ll t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}