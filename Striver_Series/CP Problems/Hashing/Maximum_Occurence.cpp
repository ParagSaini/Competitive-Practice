#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	unordered_map<char, int> m;
	getline(cin, s);
	for(int i=0; i<s.length(); i++) {
		m[s[i]]++;
	}
	int maxi = INT_MIN;
	char ch;
	for(auto it : m) {
		if(it.second == maxi) {
			ch = ((int)ch < (int)it.first ? ch : it.first);
		}
		else if(it.second > maxi) {
			maxi = it.second;
			ch = it.first;
		}
	}
	cout<<ch<<" "<<maxi<<endl;
	return 0;
}