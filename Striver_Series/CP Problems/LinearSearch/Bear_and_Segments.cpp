#include<bits/stdc++.h>
using namespace std;
// t.c O(n), s.c O(1)
void checkString(string str) {
	int s=0, e=str.length()-1;
	while(s <= e) {
		if( (str[s] == '1') && (str[e] == '1')) break;
		if(str[s] == '0') s++;
		if(str[e] == '0') e--;
	}
	if(s > e) cout<<"NO"<<endl;
	else {
		for(int i=s; i<=e; i++) {
			if(str[i] != '1') {
				cout<<"NO"<<endl;
				return;
			}
		}
		cout<<"YES"<<endl;
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    checkString(s);
	}
	return 0;
}