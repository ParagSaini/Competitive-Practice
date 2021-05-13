#include<iostream>
#include<conio.h>
#include<stack>
#include<string>
using namespace std;
// the below algorithm actually reverse the word in the string itself, not just print them.
/*void reverseword(string& s, int start, int end)
{
	if(start >= end)
		return;
	swap(s[start], s[end]);
	reverseword(s, start+1, end-1);
}
int main()
{
	string s = "parag i      my name   ";
	int start = -1;                // this contains the index of first alphabhet of a word.
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] == ' ')
		{
			if(start != -1)
			{
				reverseword(s, start, i-1);
				start = -1;
			}
		}
		else
		{
			if(start == -1)            // to make sure start always contains the index of first alphabet of the word.
				start = i;
		}
	}
	if(start != -1)                           // this condition make sure that last word also get reversed.
		reverseword(s, start, s.length()-1);
	cout<<s;
	getch();
	return 0;
}*/

/* USING THE STACK FOR THIS PROBLEM. */

void reverseword(string s)
{
	stack<char> x;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] != ' ')
			x.push(s[i]);
		else
		{
			while(!x.empty())
			{
				cout<<x.top();
				x.pop();
			}
			cout<<" ";
		}
	}
	while(!x.empty())               // their is no space after the last word.
	{
		cout<<x.top();
		x.pop();
	}
}
int main()
{
	string s = "parag is      my name";
	reverseword(s);
	getch();
	return 0;
}