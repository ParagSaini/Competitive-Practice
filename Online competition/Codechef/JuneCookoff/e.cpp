#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

vector<bool> primeSieve() {
	int n = 1e5+11;
	vector<bool> prime(n, true);
	for(int i=2; (ll)i*i<= n; i++) {
		if(prime[i]) {
			for(ll j = i*i; j<=n; j+=i) {
				prime[j] = false;
			}
		}
	}
	return prime;
}
vector<int> getfactor(int n, vector<bool>& prime) {
	vector<int> res;
	res.push_back(1);
	for(int i=2; i<=n; i++) {
		if(n%i == 0) res.push_back(i);
	}
	return res;
}
string make(int f, int n) {
	string res;
	res.push_back('1');
	int i = 1;
	while(i < n) {
		
	}

}
void solve() {
	vector<bool> prime = primeSieve();
	int n;
	cin>>n;
	string str;
	cin>>str;
	int maxdiff = n;
	vector<int> facts = getfactor(n, prime);
	for(auto fact: facts) {
		string cur = make(fact, n);
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

	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}