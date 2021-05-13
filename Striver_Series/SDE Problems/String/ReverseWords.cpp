#include<bits/stdc++.h>
using namespace std;
// O(n) approach and with S.c = O(1).
// substr function of string takes O(N) time, where N is the length of the new String it returns;

void printReverse(string s) {
    int end = s.length()-1, i;
    
    for(i=s.length()-1; i>=0; i--) {
        if(s[i] == '.') {
            cout<<s.substr(i+1, end - i)<<".";
            end = i-1;
        }
    }
    cout<<s.substr(i+1, end - i);
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    printReverse(s);
	    cout<<endl;
	}
	return 0;
}