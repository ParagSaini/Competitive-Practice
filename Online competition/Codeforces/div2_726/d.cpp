#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
bool isPrime(int n) {
	if(n == 1) return false;
	for(int i=2; i*i<=n; i++) {
		if(n%i == 0) return false;
	}
	return true;
}
bool solve(int N, bool A, int dp[][2])
{
	// check if N=1 or N=3 then player B wins
	if(isPrime(N)) return (A == 1 ? 0 : 1);

	if (dp[N][A] != -1)
		return dp[N][A];

	int ans = (A == 1) ? 0 : 1;

	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			if (A) ans |= solve(N - i, 0, dp);
			else ans &= solve(N - i, 1, dp);
		}
	}

	return dp[N][A] = ans;
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
	// t = 1;
	while(t--) {
		int n;
		cin>>n;

		int dp[n+1][2];

		memset(dp, -1, sizeof(dp));

		if (solve(n, 1, dp) == true)
			cout <<"Alice"<<endl;
		else
			cout <<"Bob"<<endl;

	}
	return 0;
}