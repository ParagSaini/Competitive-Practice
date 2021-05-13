#include<bits/stdc++.h>
using namespace std;

int DecimalConversion(string s, unordered_map<char, int>& m) {
    int ans = 0;
    for(int i=0; i<s.length(); i++) {
        int cur_Val = m[s[i]];
        if(i == 0) {
            ans = cur_Val;
            continue;
        }
        int prev_Val = m[s[i-1]];
        if(prev_Val >= cur_Val) ans += cur_Val;
        // (2 * prev_val) because we already added prev value to our sum, so to subtract and decrease the sum, we need two subtraction of prevVal;
        else ans += cur_Val - (2 * prev_Val);
    }
    return ans;
}

int main()
 {
	int t;
	cin>>t;
	unordered_map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	while(t--) {
	    string s;
	    cin>>s;
	    cout<<DecimalConversion(s, m)<<endl;
	}
	return 0;
}