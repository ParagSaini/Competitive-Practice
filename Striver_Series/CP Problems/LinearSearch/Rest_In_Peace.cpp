#include<bits/stdc++.h>
using namespace std;

// t.c O(n), s.c O(1)
string checkMood(int num) {
	string mood1 = "The streak is broken!";
	string mood2 =  "The streak lives still in our heart!";

	if(num % 21 == 0) return mood1;
	int prevDig = (num % 10);
	num /= 10;
	
	while(num) {
		int curDig = (num % 10);
		if(prevDig == 1 && curDig == 2) return mood1;
		num /= 10;
		prevDig = curDig;
	}
	return mood2;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int num;
		cin>>num;
		cout<<checkMood(num)<<endl;
	}
	return 0;
}