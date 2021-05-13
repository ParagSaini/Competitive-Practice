#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
// Hint : we can also make a count array of 256(all ascii value).
int anagram(string s, string r)
{
	if(s.length() != r.length())
		return 0;

	for(int i=0; i<r.length(); i++)
	{
		char ch = r[i];
		int flag = 0;
		for(int j=0; j<s.length(); j++)
		{
			if(s[j] == ch)
			{
				s[j] = ' ';
				flag = 1;
				break;
			}
		}
		if(!flag)
			return 0;
	}
	return 1;
}
int main()
{
	string a = "parag";
	string b = "gppar";
	cout<<anagram(a,b)<<endl;
	cout<<a<<" "<<b;
	getch();
	return 0;
}