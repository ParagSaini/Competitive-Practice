#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<conio.h>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	string temp;
	cout<<s<<" "<<s.length()<<endl;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] != ' ')
			temp.push_back(s[i]);
	}
	s = temp;
	cout<<s<<" "<<s.length();
	return 0;
}
