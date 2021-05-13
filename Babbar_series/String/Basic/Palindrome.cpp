#include<iostream>
#include<conio.h>
#include<stack>
#include<string>
using namespace std;
// we can also use the stack for checking a string is palindrome or not?
// below method is without using stack
int palindrome(string s)
{
	int start = 0;
	int end = s.length()-1;
	while(start < end)
	{
		if(s[start] != s[end])
			return 0;
		else
		{
			start++;
			end--;
		}
	}
	return 1;
}
int main()
{
	string s = "abba";
	if(palindrome(s))
		cout<<"Yes";
	else
		cout<<"No";
	getch();
	return 0;
}